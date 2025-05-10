# language Scanner

A scanner that tokenizes arithmetic expressions, numbers, and unknown inputs.

## Features
. Tokenizes: 
    - Numbers (e.g., 123, -5.2)
    - Operators (+, -, *, /, (, ))
    - Unknown symbols (e.g., letters, symbols)
. Handles whitespace and negative numbers.
. Outputs tokens with types and values.

## How to Build and Run
Type into the terminal:
1) g++ main.cpp scanner.cpp -o scanner
2) ./scanner

## example:

### input:
10 + 6 * (-1 - 9) / 2

### output:
Token(Type: NUMBER, Value: "10")
Token(Type: OPERATOR, Value: "+")
Token(Type: NUMBER, Value: "6")
Token(Type: OPERATOR, Value: "*")
Token(Type: OPERATOR, Value: "(")
Token(Type: NUMBER, Value: "-1")
Token(Type: OPERATOR, Value: "-")
Token(Type: NUMBER, Value: "9")
Token(Type: OPERATOR, Value: ")")
Token(Type: OPERATOR, Value: "/")
Token(Type: NUMBER, Value: "2")

# YOUTUBE LINK:
