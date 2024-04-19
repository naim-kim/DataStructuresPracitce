#ifndef BASIC_CALC_H
#define BASIC_CALC_H

#include <iostream>
#include <string>

class BasicCalculator {
private:
    std::string expression;

    // Private helper functions
    bool isOperator(char ch);
    int precedence(char op);
    float calculate(float operand1, float operand2, char op);

public:
    BasicCalculator(std::string expr) : expression(expr) {}
    float evaluate();
};

#endif // BASIC_CALC_H
