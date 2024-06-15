// postfix_calc.h

#ifndef __POSTFIX_CALC_H__
#define __POSTFIX_CALC_H__

#include <string>

class Calculator
{
private:
    std::string postfix;

public:
    Calculator(std::string postfix_expr) : postfix(postfix_expr) {}
    float evaluate();
};

#endif
