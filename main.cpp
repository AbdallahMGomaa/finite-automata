#include <iostream>

#include "Alphabet.h"
#include "DFA.h"
#include "State.h"

int main() {
    // first DFA is what was defined in lecture 2 page 24, a DFA to check if the number of 1s in a string is divisible by 3
    // count(input, 1s) % 3 == 0
    BST* bst = new BST();
    bst->insert('0');
    bst->insert('1');
    Alphabet* alphabet = new Alphabet(bst);

    State* start_state = new State("q0");
    State* first_state = new State("q1");
    State* second_state = new State("q2");
    State* third_state = new State("q3");

    vector<State*> accept_states;
    accept_states.push_back(start_state);
    vector<State*> states;
    states.push_back(start_state);
    states.push_back(first_state);
    states.push_back(second_state);
    map<pair<State*, char>, State*> transitions;
    transitions.insert(make_pair(make_pair(start_state, '0'), start_state));
    transitions.insert(make_pair(make_pair(start_state, '1'), first_state));
    transitions.insert(make_pair(make_pair(first_state, '0'), first_state));
    transitions.insert(make_pair(make_pair(first_state, '1'), second_state));
    transitions.insert(make_pair(make_pair(second_state, '0'), second_state));
    transitions.insert(make_pair(make_pair(second_state, '1'), states[0]));

    DFA dfa1(states, alphabet, transitions, start_state, accept_states);

    cout << dfa1.process_string("111") << " == 1" << endl; // should be true
    cout << dfa1.process_string("101") << endl;
    cout << dfa1.process_string("110") << endl;
    cout << dfa1.process_string("001") << endl;
    cout << dfa1.process_string("1") << endl;
    cout << dfa1.process_string("1") << endl;
    cout << dfa1.process_string("") << " == 1" << endl; // should be true
    cout << dfa1.process_string("1111") << endl;
    cout << dfa1.process_string("1110") << " == 1" << endl; // should be true
    cout << dfa1.process_string("0110") << endl;
    cout << dfa1.process_string("0111") << " == 1" << endl; // should be true
    cout << dfa1.process_string("01112") << endl;

    // Design a DFA that recognizes the language L= {w|w ∈ {0, 1}* and w has 101 as a substring }
    cout << "_______________________________________________________________________________________" << endl;
    states.clear();
    states.push_back(start_state);
    states.push_back(first_state);
    states.push_back(second_state);
    states.push_back(third_state);

    accept_states.clear();
    accept_states.push_back(third_state);

    transitions.clear();
    transitions.insert(make_pair(make_pair(start_state, '0'), start_state));
    transitions.insert(make_pair(make_pair(start_state, '1'), first_state));
    transitions.insert(make_pair(make_pair(first_state, '0'), second_state));
    transitions.insert(make_pair(make_pair(first_state, '1'), first_state));
    transitions.insert(make_pair(make_pair(second_state, '0'), start_state));
    transitions.insert(make_pair(make_pair(second_state, '1'), third_state));
    transitions.insert(make_pair(make_pair(third_state, '0'), third_state));
    transitions.insert(make_pair(make_pair(third_state, '1'), third_state));

    DFA dfa2(states, alphabet, transitions, start_state, accept_states);
    cout << dfa2.process_string("101") << " == 1" << endl; // should be true
    cout << dfa2.process_string("111") << endl;
    cout << dfa2.process_string("0") << endl;
    cout << dfa2.process_string("001") << endl;
    cout << dfa2.process_string("1") << endl;
    cout << dfa2.process_string("100001") << endl;
    cout << dfa2.process_string("0001010000") << " == 1" << endl; // should be true
    cout << dfa2.process_string("1111") << endl;
    cout << dfa2.process_string("0111000101") << " == 1" << endl; // should be true
    cout << dfa2.process_string("0110") << endl;
    cout << dfa2.process_string("0101") << " == 1" << endl; // should be true
    cout << dfa2.process_string("011012") << endl;

    // Design a DFA that recognizes the language L= {w| w ∈ {0, 1}∗ and the last symbol in w is a 1}
    cout << "_______________________________________________________________________________________" << endl;
    states.clear();
    states.push_back(start_state);

    states.push_back(first_state);

    accept_states.clear();
    accept_states.push_back(first_state);

    transitions.clear();
    transitions.insert(make_pair(make_pair(start_state, '0'), start_state));
    transitions.insert(make_pair(make_pair(start_state, '1'), first_state));
    transitions.insert(make_pair(make_pair(first_state, '0'), start_state));
    transitions.insert(make_pair(make_pair(first_state, '1'), first_state));


    DFA dfa3(states, alphabet, transitions, start_state, accept_states);
    cout << dfa3.process_string("1") << " == 1" << endl; // should be true
    cout << dfa3.process_string("1110") << endl;
    cout << dfa3.process_string("0") << endl;
    cout << dfa3.process_string("000") << endl;
    cout << dfa3.process_string("100000") << endl;
    cout << dfa3.process_string("00010100001") << " == 1" << endl; // should be true
    cout << dfa3.process_string("1110") << endl;
    cout << dfa3.process_string("0111000101") << " == 1" << endl; // should be true
    cout << dfa3.process_string("0110") << endl;
    cout << dfa3.process_string("0101") << " == 1" << endl; // should be true
    cout << dfa3.process_string("011012") << endl;

    // Design a DFA that recognizes the language L= {w| w ∈ {0, 1}∗ and the symbol before last in w is a 1}
    cout << "_______________________________________________________________________________________" << endl;
    states.clear();
    states.push_back(start_state);
    states.push_back(first_state);
    states.push_back(second_state);
    states.push_back(third_state);

    accept_states.clear();
    accept_states.push_back(second_state);
    accept_states.push_back(third_state);

    transitions.clear();
    transitions.insert(make_pair(make_pair(start_state, '0'), start_state));
    transitions.insert(make_pair(make_pair(start_state, '1'), first_state));
    transitions.insert(make_pair(make_pair(first_state, '0'), second_state));
    transitions.insert(make_pair(make_pair(first_state, '1'), third_state));
    transitions.insert(make_pair(make_pair(second_state, '0'), start_state));
    transitions.insert(make_pair(make_pair(second_state, '1'), first_state));
    transitions.insert(make_pair(make_pair(third_state, '0'), second_state));
    transitions.insert(make_pair(make_pair(third_state, '1'), third_state));


    DFA dfa4(states, alphabet, transitions, start_state, accept_states);
    cout << dfa4.process_string("10") << " == 1" << endl; // should be true
    cout << dfa4.process_string("1100") << endl;
    cout << dfa4.process_string("0") << endl;
    cout << dfa4.process_string("000") << endl;
    cout << dfa4.process_string("100000") << endl;
    cout << dfa4.process_string("000101000010") << " == 1" << endl; // should be true
    cout << dfa4.process_string("111000001") << endl;
    cout << dfa4.process_string("0111000111") << " == 1" << endl; // should be true
    cout << dfa4.process_string("01100") << endl;
    cout << dfa4.process_string("01010") << " == 1" << endl; // should be true
    cout << dfa4.process_string("0110112") << endl;



    delete bst;
    delete alphabet;
    delete start_state;
    delete first_state;
    delete second_state;
    delete third_state;

    return 0;
}
