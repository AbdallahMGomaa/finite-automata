//
// Created by Abdallah Gomaa on 21/11/2025.
//

#ifndef NFA_H
#define NFA_H
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include "Alphabet.h"

#include "State.h"
#include "DFA.h"

using namespace std;

class NFA {
    vector<State*> states;
    Alphabet *alphabet;
    map<State*, vector<pair<char, State*>>> transitions;
    State* start_state;
    vector<State*> accept_states;
    bool traverse_NFA(State* current_state, const string& input, int input_index, set<pair<State*, int>>& visited);
    set<State*> epsilon_closure(State* s);
    set<State*> epsilon_closure(const set<State*>& state);
    string state_set_name(const set<State*>& state);
    public:
    NFA(const vector<State*>& states, Alphabet* alphabet, const map<State*, vector<pair<char, State*>>> &transitions,
        State* start_state, const vector<State*> &accept_states);
    bool process_string(const string &input);
    DFA* to_DFA();
};

#endif //NFA_H
