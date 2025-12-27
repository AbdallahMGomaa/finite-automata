#include "fallback_dfa.h"

bool FallbackDFA::process_string(const string &input)
{
    map<string, int> variable_addresses;
    int id = 0;

    int L = 0, R = 0;
    State* rejecting_state = new State("q_rejected");
    State *current_state;
    Stack stack;
    while (R < input.size()) {
        current_state = start_state;
        stack.clear();
        while (L < input.size()) {
            char c = input[L];
            auto it = transitions.find({current_state, c});
            if (it == transitions.end()) {
                current_state = rejecting_state;
                break;
            }
            current_state = it->second;

            stack.push(current_state);
            L++;
        }

        if (is_accepting(current_state)) {
            string lex = input.substr(R, L - R);
            cout << fallbacks[current_state](lex, variable_addresses, id) << " ";
            return true;
        }

        while (!stack.empty()) {
            current_state = stack.pop();
            if (is_accepting(current_state)) {
                string lex = input.substr(R, L - R);
                cout << fallbacks[current_state](lex, variable_addresses, id) << " ";
                L--;
                break;
            }
            L--;
        }
        L++;
        R = L;
    }
    return true;
}

bool FallbackDFA::is_accepting(State *current_state) {
    return find(accept_states.begin(), accept_states.end(), current_state) != accept_states.end();
}

FallbackDFA::FallbackDFA(
    const vector<State *> &states, Alphabet *alphabet, const map<pair<State *, char>, State *> &transitions,
    State *start_state, const vector<State *> &accept_states, const map<State *, fallbackFunction> &fallbacks) : DFA(states, alphabet, transitions, start_state, accept_states)
{
    this->fallbacks = fallbacks;
}

FallbackDFA::FallbackDFA(DFA *dfa, map<State *, fallbackFunction> fallbacks) : DFA(dfa)
{
    this->fallbacks = fallbacks;
}
