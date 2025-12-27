//
// Created by Abdallah Gomaa on 22/10/2025.

#include "DFA.h"

DFA::DFA(const DFA* dfa) {
    this->states = dfa->states;
    this->alphabet = dfa->alphabet;
    this->start_state = dfa->start_state;
    this->accept_states = dfa->accept_states;
    this->transitions = dfa->transitions;
}

DFA::DFA(const vector<State *> &states, Alphabet *alphabet, const map<pair<State *, char>, State *> &transitions, State *start_state, const vector<State *> &accept_states) : alphabet(alphabet)
{
    this->states = states;
    this->transitions = transitions;
    this->start_state = start_state;
    this->accept_states = accept_states;
}

bool DFA::process_string(const string &input) {
    if (alphabet->is_valid_input(input)) {
        State* current_state = this->start_state;
        for (const char c : input) {
            current_state = transitions[make_pair(current_state, c)];
        }
        if (find(accept_states.begin(), accept_states.end(), current_state) != accept_states.end()) {
            return true;
        }
    }
    return false;
}

vector<State *> DFA::get_states()
{
    return states;
}

vector<State *> DFA::get_accept_states()
{
    return accept_states;
}