
#include "fallbacks.h"

string fallback(string lex, map<string, int>& variable_address, int& last_address) {
    vector<string> keywords = {"if", "else", "for", "while"};
    vector<string> compares = {"==", "!=", "<", "<=", ">", ">="};
    vector<string> operators = {"+", "-", "*", "/", "&", "|", "!", "&&", "||"};
    if (find(keywords.begin(), keywords.end(), lex) != keywords.end()) {
        return "<" + lex + ">";
    } else if (find(compares.begin(), compares.end(), lex) != compares.end()) {
        return "<cmp," + lex + ">";
    } else if (find(operators.begin(), operators.end(), lex) != operators.end()) {
        return "<operator," + lex + ">"; 
    } else if (lex == "(") {
        return "<LP>";
    } else if (lex == ")") {
        return "<RP>";
    } else if (lex == "{") {
        return "<LB>";
    } else if (lex == "}") {
        return "<RB>";
    } else if (lex == "=") {
        return "<ASSIGN>";
    } else if (isalpha(lex[0])) {
        int id;
        auto it = variable_address.find(lex);
        if (it != variable_address.end()) {
            id = it->second;
        } else {
            id = last_address++;
            variable_address[lex] = id;
        }
        return "<id," + to_string(id) + ">";
    } else if (isdigit(lex[0])) {
        return "<num," + lex + ">";
    } else {
        return "<ERROR>";
    }
}
