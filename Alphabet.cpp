//
// Created by Abdallah Gomaa on 22/10/2025.
//

#include "Alphabet.h"

Alphabet::Alphabet(BST* bst) {
    this->bst = bst;
}

bool Alphabet::is_valid_input(const string & str) {
    for (char c : str) {
        if (!bst->search(c)) {
            return false;
        }
    }
    return true;
}