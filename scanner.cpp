#include "scanner.h"
#include <cctype>
#include <iostream>

Token::Token(TokenType typeOfToken, const std::string& valueOfToken) 
    : type(typeOfToken), value(valueOfToken) {}

Scanner::Scanner(const std::string& input) : input(input) {}

void Scanner::skipWhitespace() {
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }
}

Token Scanner::getNextToken() {
    skipWhitespace();

    if (pos >= input.length()) {
        return Token(END_OF_INPUT, "");
    }

    char current = input[pos];
    
    // Handle negative numbers or subtraction
    if (current == '-' && (pos + 1 < input.length()) && isdigit(input[pos+1])) {
        std::string number = "-";
        pos++;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos];
            pos++;
        }
        return Token(NUMBER, number);
    }
    
    // Handle numbers (positive)
    if (isdigit(current)) {
        std::string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos];
            pos++;
        }
        return Token(NUMBER, number);
    }

    // Handle operators
    if (current == '+' || current == '-' || current == '*' || current == '/' || 
        current == '(' || current == ')') {
        std::string op(1, current);
        pos++;
        return Token(OPERATOR, op);
    }

    // Handle unknown tokens
    std::string unknown;
    while (pos < input.length() && !isspace(input[pos]) && 
           !isdigit(input[pos]) &&
           input[pos] != '+' && input[pos] != '-' &&
           input[pos] != '*' && input[pos] != '/' &&
           input[pos] != '(' && input[pos] != ')') {
        unknown += input[pos];
        pos++;
    }
    return Token(UNKNOWN, unknown);
}

std::vector<Token> Scanner::getAllTokens() {
    std::vector<Token> tokens;
    while (true) {
        Token token = getNextToken();
        if (token.type == END_OF_INPUT) break;
        tokens.push_back(token);
    }
    return tokens;
}