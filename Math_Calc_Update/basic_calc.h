//DataStructures-02 22000056 Naim Kim

#ifndef BASIC_CALC_H
#define BASIC_CALC_H

#include <iostream>
#include <string>

class BasicCalculator
{
private:
    std::string arithmetic_expr;

    bool isOperator(char ch);
    int precedence(char op);
    float calculate(float operand1, float operand2, char op);

public:
    BasicCalculator(std::string expr) : arithmetic_expr(expr) {}
    float evaluate();
};

#endif
