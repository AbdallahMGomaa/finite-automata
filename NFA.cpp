#include "NFA.h"

bool NFA::traverse_NFA(State *current_state, const string &input, int input_index, set<pair<State*, int>>& visited) {
    if (visited.count({current_state, input_index})) {
        return false;
    }
    visited.insert({current_state, input_index});
    vector<pair<char, State *>> current_state_transitions = this->transitions[current_state];
    bool result = false;

    if (input_index == input.size()) {
        if (find(accept_states.begin(), accept_states.end(), current_state) != accept_states.end()) {
            return true;
        }
        for (int i=0; i<current_state_transitions.size(); i++) {
            if (current_state_transitions[i].first == ' ') {
                result |= traverse_NFA(current_state_transitions[i].second, input, input_index, visited);
                if (result) {
                    return true;
                }
            }
        }
    }
    else {
        for (int i=0; i<current_state_transitions.size(); i++) {
            if (current_state_transitions[i].first == input[input_index]) {
                set<pair<State*, int>> new_visited = visited;
                result |= traverse_NFA(current_state_transitions[i].second, input, input_index+1, new_visited);
            }
            else if (current_state_transitions[i].first == ' ') { // epsilon transition (same input_index)
                set<pair<State*, int>> new_visited = visited;
                result |= traverse_NFA(current_state_transitions[i].second, input, input_index, new_visited);
            }
            if (result){
                return true;
            }
        }
    }
    
    return false;
}

NFA::NFA(const vector<State *> &states, Alphabet *alphabet, const map<State *, vector<pair<char, State *>>> &transitions, State *start_state, const vector<State *> &accept_states) : alphabet(alphabet)
{
    this->states = states;
    this->transitions = transitions;
    this->start_state = start_state;
    this->accept_states = accept_states;
}

bool NFA::process_string(const string &input) {
    if (alphabet->is_valid_input(input)) {
        set<pair<State*, int>> visited;
        return this->traverse_NFA(this->start_state, input, 0, visited);
    }
    return false;
}

set<State*> NFA::epsilon_closure(State* s) {
    set<State*> closure;
    stack<State*> st;
    st.push(s);
    closure.insert(s);

    while (!st.empty()) {
        State* current = st.top();
        st.pop();
        if (!transitions.count(current)) continue;
        auto& transitions_from_current = transitions[current];
        for (auto& t : transitions_from_current) {
            if (t.first == ' ') { // epsilon transition
                if (!closure.count(t.second)) {
                    closure.insert(t.second);
                    st.push(t.second);
                }
            }
        }
    }
    return closure;
}

set<State*> NFA::epsilon_closure(const set<State*>& state_set) {
    set<State*> result;
    for (State* state : state_set) {
        auto closure = epsilon_closure(state);
        result.insert(closure.begin(), closure.end());
    }
    return result;
}

string NFA::state_set_name(const set<State*>& state_set) {
    vector<string> names;
    for (State* state : state_set) {
        names.push_back(state->get_name());
    }
    sort(names.begin(), names.end());
    string res;
    for (auto& n : names) {
        res += n + "_";
    }
    return res;
}

DFA* NFA::to_DFA() {
    map<set<State*>, State*> dfa_state_map;

    vector<State*> dfa_states;
    Alphabet* dfa_alphabet = this->alphabet;
    map<pair<State*, char>, State*> dfa_transitions;
    vector<State*> dfa_accept_states;
    set<State*> start_closure = epsilon_closure(this->start_state);

    State* dfa_start = new State(state_set_name(start_closure));
    State* dfa_start_state = dfa_start;

    dfa_state_map[start_closure] = dfa_start;
    dfa_states.push_back(dfa_start);
    queue<set<State*>> q;
    q.push(start_closure);

     while (!q.empty()) {
        set<State*> current_set = q.front();
        q.pop();

        State* current_dfa_state = dfa_state_map[current_set];

        for (char sym : alphabet->get_symbols()) {

            set<State*> next_set;

            for (State* s : current_set) {
                for (auto& t : transitions[s]) {
                    if (t.first == sym) {
                        next_set.insert(t.second);
                    }
                }
            }

            next_set = epsilon_closure(next_set);

            if (next_set.empty()) {
                continue;
            }

            if (!dfa_state_map.count(next_set)) {
                State* new_dfa_state = new State(state_set_name(next_set));
                dfa_state_map[next_set] = new_dfa_state;
                dfa_states.push_back(new_dfa_state);
                q.push(next_set);
            }
            dfa_transitions[{current_dfa_state, sym}] = dfa_state_map[next_set];
        }
    }


    for (auto& entry : dfa_state_map) {
        set<State*> group = entry.first;
        State* dfa_state = entry.second;

        for (State* accept_state : accept_states) {
            if (group.count(accept_state)) {
                dfa_accept_states.push_back(dfa_state);
                break;
            }
        }
    }

    return new DFA(dfa_states, dfa_alphabet, dfa_transitions, dfa_start_state, dfa_accept_states);
}
