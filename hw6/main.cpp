#include <iostream>
#include <string>
#include "postfix_calc.h"
#include "basic_calc.h"

int main() {
    int choice = 0;

    while (choice != 3) {
        std::cout << "Select Calculator Type:" << std::endl;
        std::cout << "1. Postfix Calculator" << std::endl;
        std::cout << "2. Regular Calculator" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cin.ignore(); // Ignore newline character in buffer

        if (choice == 1) {
            std::string str;

            std::cout << "Input postfix expression: ";
            std::getline(std::cin, str);    // reading one line from keyboard

            Calculator calc(str);

            std::cout << ">> " + str + " = " << calc.evaluate() << "\n" << std::endl;

        } 
        else if (choice == 2) {
            std::string expression;

            std::cout << "Enter an arithmetic expression: ";
            std::getline(std::cin, expression);    // reading one line from keyboard

            BasicCalculator basicCalc(expression);

            std::cout << "\t" + expression + " = " << basicCalc.evaluate() << "\n" << std::endl;
        }
        else if (choice == 3) {
            std::cout << "See you next time! :)" << std::endl;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
