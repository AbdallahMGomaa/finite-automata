#include "State.h"
#include "Alphabet.h"
#include "NFA.h"
#include "fallback_dfa.h"
#include "fallbacks.h"

using namespace std;

class Lexer {
    BST* bst;
    Alphabet* alphabet;
    vector<State*> accept_states, states;
    map<State*, vector<pair<char, State*>>> transitions;
    NFA* nfa;
    DFA* dfa;
    FallbackDFA* fallbackDFA;

    void assign_alphabet_transitions_from_state_to_state(map<State*, vector<pair<char, State*>>> &transitions, State* from_state, State* to_state);

    void assign_digits_transition_from_state_to_state(map<State*, vector<pair<char, State*>>> &transitions, State* from_state, State* to_state);
public:
    Lexer();
    ~Lexer();
    bool process_input(const string&);
};


