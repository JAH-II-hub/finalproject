#include "scanner.h"
#include <cctype>
#include <iostream>
using namespace std;

Token::Token(TokenType typeOfToken, const string& valueOfToken) 
    : type(typeOfToken), value(valueOfToken) {}

Scanner::Scanner(const string& input) : input(input) {}

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
    
    // Handle negative numbers
    if (current == '-' && (pos + 1 < input.length()) && isdigit(input[pos+1])) {
        string number = "-";
        pos++;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos];
            pos++;
        }
        return Token(NUMBER, number);
    }
    
    // Handle positive numbers
    if (isdigit(current)) {
        string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos];
            pos++;
        }
        return Token(NUMBER, number);
    }

    // Handle operators
    if (current == '+' || current == '-' || current == '*' || 
        current == '/' || current == '(' || current == ')') {
        string op(1, current);
        pos++;
        return Token(OPERATOR, op);
    }

    // Handle unknown tokens
    string unknown;
    while (pos < input.length() && !isspace(input[pos]) && 
           !isdigit(input[pos]) && input[pos] != '+' && 
           input[pos] != '-' && input[pos] != '*' && 
           input[pos] != '/' && input[pos] != '(' && 
           input[pos] != ')') {
        unknown += input[pos];
        pos++;
    }
    return Token(UNKNOWN, unknown);
}

vector<Token> Scanner::getAllTokens() {
    vector<Token> tokens;
    while (true) {
        Token token = getNextToken();
        if (token.type == END_OF_INPUT) break;
        tokens.push_back(token);
    }
    return tokens;
}