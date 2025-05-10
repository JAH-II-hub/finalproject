#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>

enum TokenType {
    NUMBER,
    OPERATOR,
    UNKNOWN,
    END_OF_INPUT
};

struct Token {
    TokenType type;
    std::string value;
    Token(TokenType typeOfToken, const std::string& valueOfToken);
};

class Scanner {
public:
    Scanner(const std::string& input);
    Token getNextToken();
    std::vector<Token> getAllTokens();
    
private:
    std::string input;
    size_t pos = 0;
    void skipWhitespace();
};

#endif