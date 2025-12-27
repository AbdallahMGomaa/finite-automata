#include "lexer.h"
#include <iostream>

using namespace std;

int main() {
    Lexer lexer;
    lexer.process_input("if (x == y) { z = x }");
    cout << endl;
    lexer.process_input("for (i < j) { i = i + 1}");
    cout << endl;
    lexer.process_input("while (l) { x = 2*y + 1}");
    cout << endl;
    return 0;
}