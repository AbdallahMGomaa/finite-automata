/*
    if -> if 
    else -> else 
    while -> while 
    for -> for 
    startBlock -> {
    endBlock -> }
    leftParantheses -> (
    rightParantheses -> )
    letter_ -> [A−Za−z] | _
    digit -> [0−9]
    id -> letter_(letter_|digit)∗
    digits -> digit+
    opFrac -> (.digits)?
    opExp -> (E [+−]? digits)?
    number -> digits opFrac opExp
    operator -> +, -, *, /, &, |, !, &&, ||
    comp -> ==, !=, <, <=, >, >=
*/

#ifndef FALLBACK_DFA_H
#define FALLBACK_DFA_H

#include "DFA.h"
#include "Stack.h"
#include <iostream>

using namespace std;

typedef string (*fallbackFunction)(string, map<string,int>&, int&);

class FallbackDFA : public DFA {
    map<State*, fallbackFunction> fallbacks;
    bool is_accepting(State*);
public:
    bool process_string(const string &input);
    FallbackDFA(const vector<State*>& states, Alphabet* alphabet, const map<pair<State*, char>, State*> &transitions,
        State* start_state, const vector<State*> &accept_states, const map<State*, fallbackFunction>& fallbacks);

    FallbackDFA(DFA* dfa, map<State*, fallbackFunction> fallbacks);
};

#endif