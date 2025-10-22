cmake_minimum_required(VERSION 3.31)
project(DFA)

set(CMAKE_CXX_STANDARD 20)

add_executable(DFA main.cpp
        DFA.cpp
        DFA.h
        state.cpp
        state.h
        alphabet.cpp
        alphabet.h
        BST.cpp
        BST.h)
