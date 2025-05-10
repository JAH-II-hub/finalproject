#include "scanner.h"
#include <iostream>

int main() {
    std::string input;
    std::cout << "Enter arithmetic expression: ";
    std::getline(std::cin, input);

    Scanner scanner(input);
    std::vector<Token> tokens = scanner.getAllTokens();

    for (const auto& token : tokens) {
        std::cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER: std::cout << "NUMBER"; break;
            case OPERATOR: std::cout << "OPERATOR"; break;
            case UNKNOWN: std::cout << "UNKNOWN"; break;
            default: std::cout << "OTHER";
        }
        std::cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}