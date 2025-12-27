#include "lexer.h"

void Lexer::assign_alphabet_transitions_from_state_to_state(map<State *, vector<pair<char, State *>>> &transitions, State *from_state, State *to_state)
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        transitions[from_state].push_back({c, to_state});
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        transitions[from_state].push_back({c, to_state});
    }
    transitions[from_state].push_back({'_', to_state});
}

void Lexer::assign_digits_transition_from_state_to_state(map<State *, vector<pair<char, State *>>> &transitions, State *from_state, State *to_state)
{
    for (char c = '0'; c <= '9'; c++)
    {
        transitions[from_state].push_back({c, to_state});
    }
}

Lexer::Lexer()
{

    bst = new BST();
    for (char i = '0'; i <= '9'; i++)
    {
        bst->insert(i);
    }
    bst->insert('_');
    for (char i = 'a'; i <= 'z'; i++)
    {
        bst->insert(i);
    }
    bst->insert(' ');
    for (char i = 'A'; i <= 'Z'; i++)
    {
        bst->insert(i);
    }
    bst->insert('\t');
    bst->insert('\n');
    bst->insert('(');
    bst->insert(')');
    bst->insert('{');
    bst->insert('}');
    bst->insert('=');
    bst->insert('+');
    bst->insert('-');
    bst->insert('*');
    bst->insert('/');

    alphabet = new Alphabet(bst);

    State *q_init = new State("q_init");
    State *q_i = new State("q_i");
    State *q_if = new State("q_if");
    State *q_e = new State("q_e");
    State *q_el = new State("q_el");
    State *q_els = new State("q_els");
    State *q_else = new State("q_else");
    State *q_f = new State("q_f");
    State *q_fo = new State("q_fo");
    State *q_for = new State("q_for");
    State *q_w = new State("q_w");
    State *q_wh = new State("q_wh");
    State *q_whi = new State("q_whi");
    State *q_whil = new State("q_whil");
    State *q_while = new State("q_while");
    State *q_lb = new State("q_lb");
    State *q_rb = new State("q_rb");
    State *q_lp = new State("q_lp");
    State *q_rp = new State("q_rp");
    State *q_id = new State("q_id");
    State *q_num = new State("q_num");
    State *q_dot = new State("q_.");
    State *q_ex = new State("q_ex");
    State *q_num_with_frac = new State("q_numwithfrac");
    State *q_num_with_exp = new State("q_numwithexp");
    State *q_plus = new State("q_+");
    State *q_minus = new State("q_-");
    State *q_mul = new State("q_*");
    State *q_div = new State("q_/");
    State *q_assign = new State("q_=");
    State *q_compeq = new State("q_==");
    State *q_not = new State("q_!");
    State *q_compneq = new State("q_!=");
    State *q_compgt = new State("q_>");
    State *q_compgte = new State("q_>=");
    State *q_complt = new State("q_<");
    State *q_complte = new State("q_<=");
    State *q_and = new State("q_&");
    State *q_andand = new State("q_&&");
    State *q_or = new State("q_|");
    State *q_oror = new State("q_||");

    accept_states = {
        q_if, q_else, q_for, q_while, q_lb, q_rb, q_lp, q_rp, q_id, q_num, q_plus, q_minus, q_mul, q_div, q_assign, q_compeq, q_compneq,
        q_compgt, q_compgte, q_complt, q_complte, q_not, q_and, q_andand, q_or, q_oror, q_num_with_frac, q_num_with_exp};
    states = {
        q_init, q_i, q_if, q_e, q_el, q_els, q_else, q_f, q_fo, q_for, q_w, q_wh, q_whi, q_whil, q_while, q_lb, q_rb, q_lp, q_rp,
        q_id, q_num, q_plus, q_minus, q_mul, q_div, q_assign, q_compeq, q_compneq, q_compgt, q_compgte, q_complt,
        q_complte, q_not, q_and,
        q_andand, q_or, q_oror, q_num_with_frac, q_num_with_exp, q_dot, q_ex};

    transitions[q_init] = {
        {'i', q_i}, {'e', q_e}, {'f', q_f}, {'w', q_w}, {'(', q_lp}, {')', q_rp}, {'{', q_lb}, {'}', q_rb}, {'=', q_assign}, {'+', q_plus}, {'-', q_minus}, {'*', q_mul}, {'/', q_div}, {'<', q_complt}, {'>', q_compgt}, {'!', q_not}, {'&', q_and}, {'|', q_or}};
    assign_alphabet_transitions_from_state_to_state(transitions, q_init, q_id);
    assign_digits_transition_from_state_to_state(transitions, q_init, q_num);
    assign_alphabet_transitions_from_state_to_state(transitions, q_id, q_id);
    assign_digits_transition_from_state_to_state(transitions, q_id, q_id);
    assign_digits_transition_from_state_to_state(transitions, q_num, q_num);

    transitions[q_num] = {{'.', q_dot}, {'E', q_num_with_exp}, {'e', q_ex}};
    assign_digits_transition_from_state_to_state(transitions, q_dot, q_num_with_frac);
    assign_digits_transition_from_state_to_state(transitions, q_num_with_frac, q_num_with_frac);
    assign_digits_transition_from_state_to_state(transitions, q_ex, q_num_with_exp);
    assign_digits_transition_from_state_to_state(transitions, q_ex, q_ex);

    transitions[q_i] = {{'f', q_if}};

    transitions[q_f] = {{'o', q_fo}};
    transitions[q_fo] = {{'r', q_for}};

    transitions[q_w] = {{'h', q_wh}};
    transitions[q_wh] = {{'i', q_whi}};
    transitions[q_whi] = {{'l', q_whil}};
    transitions[q_whil] = {{'e', q_while}};

    transitions[q_e] = {{'l', q_el}};
    transitions[q_el] = {{'s', q_els}};
    transitions[q_els] = {{'e', q_else}};

    transitions[q_assign] = {{'=', q_compeq}};
    transitions[q_not] = {{'=', q_compneq}};
    transitions[q_compgt] = {{'=', q_compgte}};
    transitions[q_complt] = {{'=', q_complte}};
    transitions[q_and] = {{'&', q_andand}};
    transitions[q_or] = {{'|', q_oror}};

    nfa = new NFA(states, alphabet, transitions, q_init, accept_states);

    dfa = nfa->to_DFA();

    map<State *, fallbackFunction> fallbacks;
    for (State *state : dfa->get_accept_states())
    {
        fallbacks[state] = fallback;
    }

    fallbackDFA = new FallbackDFA(dfa, fallbacks);
}

Lexer::~Lexer()
{
    delete bst;
    delete alphabet;
    delete nfa;
    delete dfa;
    for (State *state : states)
    {
        delete state;
    }
}

bool Lexer::process_input(const string& input)
{
    return fallbackDFA->process_string(input);
}
