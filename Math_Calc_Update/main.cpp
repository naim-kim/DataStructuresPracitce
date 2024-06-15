#include "infix_calc.h"
#include "postfix_calc.h"
#include <iostream>
#include <string>

int main() {
    while (true) {
        std::string choice;
        std::cout << "\nChoose the type of expression to evaluate \n(1: Infix, 2: Postfix, 3: Exit): ";
        std::getline(std::cin, choice);

        if (choice == "3") {
            break;
        }

        if (choice == "1") {
            std::string infix_expr;
            std::cout << "\nEnter an infix expression: ";
            std::getline(std::cin, infix_expr);
            BasicCalculator infixCalc(infix_expr);
            try {
                std::cout << "> " << infix_expr << " = " << infixCalc.evaluate() << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else if (choice == "2") {
            std::string postfix_expr;
            std::cout << "\nEnter a postfix expression: ";
            std::getline(std::cin, postfix_expr);
            Calculator postfixCalc(postfix_expr);
            try {
                std::cout << "> " << postfix_expr << " = " << postfixCalc.evaluate() << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        } else {
            std::cerr << "\n> Invalid choice. Please enter 1, 2, or 0." << std::endl;
        }
    }

    std::cout << "\n> Exiting the program. Bye!\n" << std::endl;
    return 0;
}
