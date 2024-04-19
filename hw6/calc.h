#ifndef  __CALC_H__
#define  __CALC_H__

#include <iostream>
#include <ctype.h>  
#include <stdlib.h> 

using namespace std;

class Calculator {
    private:
        string postfix;
    public:
        Calculator(string str) : postfix(str) {}
        float evaluate();
};

#endif
