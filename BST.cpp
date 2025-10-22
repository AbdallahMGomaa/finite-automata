//
// Created by Abdallah Gomaa on 22/10/2025.
//

#include "BST.h"

Node::Node(char value) {
    this->key = value;
    this->left = nullptr;
    this->right = nullptr;
}

Node* BST::insert(Node* node, char key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

bool BST::search(Node* node, char key) {
    if (node == nullptr) {
        return false;
    }
    if (key == node->key) {
        return true;
    }
    if (key < node->key) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

void BST::insert(char key) {
    root = insert(root, key);
}

bool BST::search(char key) {
    return search(root, key);
}