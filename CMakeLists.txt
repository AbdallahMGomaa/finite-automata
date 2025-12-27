cmake_minimum_required(VERSION 3.31)
project(Compilers)

set(CMAKE_CXX_STANDARD 20)

add_executable(DFA test_DFA.cpp
        DFA.cpp
        DFA.h
        state.cpp
        state.h
        alphabet.cpp
        alphabet.h
        BST.cpp
        BST.h)

add_executable( NFA_to_DFA NFA_to_DFA.cpp
        NFA.cpp
        NFA.h
        DFA.cpp
        DFA.h
        state.cpp
        state.h
        alphabet.cpp
        alphabet.h
        BST.cpp
        BST.h)

add_executable( test_lexer  test_lexer.cpp
        lexer.cpp
        lexer.h
        fallback_dfa.cpp
        fallback_dfa.h
        fallbacks.cpp
        fallbacks.h
        Stack.cpp
        Stack.h
        NFA.cpp
        NFA.h
        DFA.cpp
        DFA.h
        state.cpp
        state.h
        alphabet.cpp
        alphabet.h
        BST.cpp
        BST.h)
