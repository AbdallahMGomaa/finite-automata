//
// Created by Abdallah Gomaa on 22/10/2025.
//

#include "State.h"

State::State(const string &name) {
    this->name = name;
}

string State::get_name()
{
    return this->name;
}
