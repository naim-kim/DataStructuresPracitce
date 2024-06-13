#include "basic_calc.h"
#include "postfix_calc.h"
#include <iostream>
#include <string>

int main()
{
    std::string expr;
    char choice;

    std::cout << "Choose the type of expression to evaluate (i for infix, p for postfix): ";
    std::cin >> choice;
    std::cin.ignore(); // To ignore the newline character after the choice

    if (choice == 'i' || choice == 'I') {
        std::cout << "Enter an infix expression: ";
        std::getline(std::cin, expr);

        BasicCalculator basicCalc(expr);
        std::cout << "Infix evaluation: " << basicCalc.evaluate() << std::endl;
    } 
    else if (choice == 'p' || choice == 'P') {
        std::cout << "Enter a postfix expression: ";
        std::getline(std::cin, expr);

        Calculator postfixCalc(expr);
        std::cout << "Postfix evaluation: " << postfixCalc.evaluate() << std::endl;
    } 
    else {
        std::cout << "Invalid choice! Please run the program again and choose either 'i' for infix or 'p' for postfix." << std::endl;
    }

    return 0;
}
