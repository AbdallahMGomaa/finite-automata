//
// Created by Abdallah Gomaa on 22/10/2025.
//

#ifndef DFA_H
#define DFA_H
#include <map>
#include <vector>
#include "Alphabet.h"

#include "State.h"

using namespace std;


class DFA {
    protected:
        vector<State*> states;
        Alphabet *alphabet;
        map<pair<State*, char>, State*> transitions;
        State* start_state;
        vector<State*> accept_states;
    public:
        DFA(const DFA*);
        DFA(const vector<State*>& states, Alphabet* alphabet, const map<pair<State*, char>, State*> &transitions,
            State* start_state, const vector<State*> &accept_states);
        bool process_string(const string &input);
        vector<State*> get_states();
        vector<State*> get_accept_states();

};



#endif //DFA_H
