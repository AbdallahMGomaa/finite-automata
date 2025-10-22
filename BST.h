//
// Created by Abdallah Gomaa on 22/10/2025.
//

#ifndef DFA_BST_H
#define DFA_BST_H

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(char value);
};

class BST {
    Node* root;
    Node* insert(Node* node, char key);

    bool search(Node* node, char key);
public:
    void insert(char key);
    bool search(char key);
};


#endif //DFA_BST_H