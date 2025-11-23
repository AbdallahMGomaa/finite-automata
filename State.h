//
// Created by Abdallah Gomaa on 22/10/2025.
//

#ifndef STATE_H
#define STATE_H
#include <string>

using namespace std;

class State {
    string name;
public:
    State(const string &name);
    string get_name();
};

#endif //STATE_H
