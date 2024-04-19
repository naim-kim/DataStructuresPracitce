#ifndef BASIC_CALC_H
#define BASIC_CALC_H

#include <iostream>
#include <string>
#include "postfix_calc.h"

class BasicCalculator {
private:
    std::string infix;

    // Private helper functions
    bool isOperator(char ch);
    int precedence(char op);
    std::string infixToPostfix(std::string infixExpr);

public:
    BasicCalculator(std::string expr) : infix(expr) {}
    float evaluate();
};

#endif // BASIC_CALC_H
