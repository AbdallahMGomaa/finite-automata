#include "lexer.h"
#include <iostream>

using namespace std;

int main() {
    Lexer lexer;
    lexer.process_input("if (x == y) { z = x }");
    lexer.process_input("for (i < j) { i = i + 1}");
    lexer.process_input("while (l) { x = 2*y + 1}");
    return 0;
}