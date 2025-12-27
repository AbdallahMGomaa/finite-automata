#include "Stack.h"

Stack::Stack() {
}

void Stack::push(State* s) {
    v.push_back(s);
}

State* Stack::pop() {
    if (v.empty()) {
        return nullptr;
    }
    State* s = v.back();
    v.pop_back();
    return s;
}

void Stack::clear() {
    v.clear();
}

State *Stack::top()
{
    return v.back();
}

bool Stack::empty() {
    return v.size() == 0;
}
