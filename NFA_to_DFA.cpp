#include <iostream>
#include "BST.h"
#include "Alphabet.h"
#include "State.h"
#include <map>
#include "NFA.h"

using namespace std;

int main() {
    BST* bst = new BST();
    bst->insert('0');
    bst->insert('1');
    Alphabet* alphabet = new Alphabet(bst);

    State* start_state = new State("q0");
    State* first_state = new State("q1");
    State* second_state = new State("q2");
    State* third_state = new State("q3");
    vector<State*> accept_states = {third_state};
    vector<State*> states = {start_state, first_state, second_state, third_state};
    map<State*, vector<pair<char, State*>>> transitions;

    // design an NFA that accepts the language {w|w \in {0,1}* and w contains a 1 in the third position from the end}
    transitions[start_state] = {{'0', start_state}, {'1', start_state}, {'1', first_state}};
    transitions[first_state] = {{'0', second_state},{'1', second_state}};
    transitions[second_state] = {{'0', third_state}, {'1', third_state}};
    accept_states.push_back(third_state);
    NFA* nfa1 = new NFA(states, alphabet, transitions, start_state, accept_states);
    DFA* dfa1 = nfa1->to_DFA();
    cout << dfa1->process_string("1011") << endl;
    cout << dfa1->process_string("101") << " == 1" << endl; // should be true
    cout << dfa1->process_string("010") << endl;
    cout << dfa1->process_string("001") << endl;
    cout << dfa1->process_string("1") << endl;
    cout << dfa1->process_string("1") << endl;
    cout << dfa1->process_string("") << endl;
    cout << dfa1->process_string("11011") << endl;
    cout << dfa1->process_string("11101") << " == 1" << endl; // should be true
    cout << dfa1->process_string("0010") << endl;
    cout << dfa1->process_string("01101") << " == 1" << endl; // should be true
    cout << dfa1->process_string("011") << endl;
    // design an NFA that accepts any string with 101 as a substring
    accept_states.clear();
    transitions.clear();
    cout << "_______________________________________________________________________________________" << endl;
    transitions[start_state] = {{'0', start_state}, {'1', start_state}, {'1', first_state}};
    transitions[first_state] = {{'0', second_state}};
    transitions[second_state] = {{'1', third_state}};
    transitions[third_state] = {{'0', third_state}, {'1', third_state}};
    accept_states.push_back(third_state);

    NFA* nfa2 = new NFA(states, alphabet, transitions, start_state, accept_states);
    DFA* dfa2 = nfa2->to_DFA();

    cout << dfa2->process_string("111") << endl;
    cout << dfa2->process_string("101") << " == 1" << endl; // should be true
    cout << dfa2->process_string("110") << endl;
    cout << dfa2->process_string("001") << endl;
    cout << dfa2->process_string("1") << endl;
    cout << dfa2->process_string("1") << endl;
    cout << dfa2->process_string("") << endl;
    cout << dfa2->process_string("1111") << endl;
    cout << dfa2->process_string("11101") << " == 1" << endl; // should be true
    cout << dfa2->process_string("0110") << endl;
    cout << dfa2->process_string("01101") << " == 1" << endl; // should be true
    cout << dfa2->process_string("0111") << endl;

    // design an NFA that recognizes the language L = {w | w \in {a,b,c} and at least one a or b or c is not a symbol in w}
    delete bst;
    delete alphabet;
    bst = new BST();
    bst->insert('a');
    bst->insert('b');
    bst->insert('c');
    alphabet = new Alphabet(bst);
    accept_states.clear();
    transitions.clear();

    transitions[start_state] = {{' ', first_state}, {' ', second_state}, {' ', third_state}};
    transitions[first_state] = {{'a', first_state}, {'b', first_state}};
    transitions[second_state] = {{'a', second_state}, {'c', second_state}};
    transitions[third_state] = {{'b', third_state}, {'c', third_state}};

    accept_states.push_back(first_state);
    accept_states.push_back(second_state);
    accept_states.push_back(third_state);

    NFA* nfa3 = new NFA(states, alphabet, transitions, start_state, accept_states);
    DFA* dfa3 = nfa3->to_DFA();
    cout << "_______________________________________________________________________________________" << endl;
    cout << dfa3->process_string("abbbbc") << endl;
    cout << dfa3->process_string("caaac") << " == 1" << endl; // should be true
    cout << dfa3->process_string("abc") << endl;
    cout << dfa3->process_string("babbac") << endl;
    cout << dfa3->process_string("") << endl;
    cout << dfa3->process_string("acb") << endl;
    cout << dfa3->process_string("") << endl;
    cout << dfa3->process_string("bacba") << endl;
    cout << dfa3->process_string("aaaaaba") << " == 1" << endl; // should be true
    cout << dfa3->process_string("baac") << endl;
    cout << dfa3->process_string("cbbcbcbcbcbcbcbc") << " == 1" << endl; // should be true
    cout << dfa3->process_string("cabca") << endl;




    return 0;
}