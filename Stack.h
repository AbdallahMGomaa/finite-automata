#ifndef STACK_H
#define STACK_H

#include "State.h"

using namespace std;

class Stack{
    private:
        vector<State*> v;
    public:
        Stack();
        void push(State*);
        State* pop();
        void clear();
        State* top();
        bool empty();
};



#endif