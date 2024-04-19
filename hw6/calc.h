// calc.h
#ifndef __CALC_H__
#define __CALC_H__

#include <iostream>
#include <string>

using namespace std;

class Calculator {
private:
    string expression;
public:
    Calculator(string str) : expression(str) {}
    float evaluate();
};

#endif
