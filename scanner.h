#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
using namespace std;

enum TokenType {
    NUMBER,
    OPERATOR,
    UNKNOWN,
    END_OF_INPUT
};

struct Token {
    TokenType type;
    string value;
    Token(TokenType typeOfToken, const string& valueOfToken);
};

class Scanner {
public:
    Scanner(const string& input);
    Token getNextToken();
    vector<Token> getAllTokens();
    
private:
    string input;
    size_t pos = 0;
    void skipWhitespace();
};

#endif