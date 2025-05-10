#include "scanner.h"
#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter arithmetic expression: ";
    getline(cin, input);

    Scanner scanner(input);
    vector<Token> tokens = scanner.getAllTokens();

    for (const auto& token : tokens) {
        cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER: cout << "NUMBER"; break;
            case OPERATOR: cout << "OPERATOR"; break;
            case UNKNOWN: cout << "UNKNOWN"; break;
            default: cout << "OTHER";
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}