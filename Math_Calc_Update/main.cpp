// main.cpp

#include "basic_calc.h"
#include "postfix_calc.h"
#include <iostream>
#include <string>

int main()
{
    std::string infix_expr = "3 + 5 * ( 2 - 8 )";
    BasicCalculator basicCalc(infix_expr);
    std::cout << "Infix evaluation: " << basicCalc.evaluate() << std::endl;

    std::string postfix_expr = "3 5 2 8 - * +";
    Calculator postfixCalc(postfix_expr);
    std::cout << "Postfix evaluation: " << postfixCalc.evaluate() << std::endl;

    return 0;
}
