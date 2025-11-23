//
// Created by Abdallah Gomaa on 22/10/2025.
//

#ifndef ALPHABET_H
#define ALPHABET_H
#include "BST.h"
#include <string>

using namespace std;


class Alphabet {
private:
    BST* bst;
public:
    Alphabet(BST* bst);
    bool is_valid_input(const string & str);
    vector<char> get_symbols();
};


#endif //ALPHABET_H
