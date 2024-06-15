#ifndef __BASIC_CALC_H__
#define __BASIC_CALC_H__

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
