// postfix_calc.h
#ifndef __POSTFIX_CALC_H__
#define __POSTFIX_CALC_H__

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class PostfixCalculator {
private:
    string postfix_expr;
public:
    PostfixCalculator(string str) : postfix_expr(str) {}
    float evaluate();
};

#endif
