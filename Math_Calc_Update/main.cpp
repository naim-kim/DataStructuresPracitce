#include "basic_calc.h"
#include "postfix_calc.h"
#include <iostream>
#include <string>

int main()
{
    std::string infix_expr, postfix_expr;

    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infix_expr);

    BasicCalculator basicCalc(infix_expr);
    std::cout << "Infix evaluation: " << basicCalc.evaluate() << std::endl;

    std::cout << "Enter a postfix expression: ";
    std::getline(std::cin, postfix_expr);

    Calculator postfixCalc(postfix_expr);
    std::cout << "Postfix evaluation: " << postfixCalc.evaluate() << std::endl;

    return 0;
}
