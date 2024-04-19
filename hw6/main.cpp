#include <iostream>
#include <string>
#include <sstream>
#include "postfix_calc.h"
#include "basic_calc.h"

int main() {
    while (true) {
        int choice = 0;
        std::string input;

        while (true) {
            std::cout << "Select Calculator Type:" << std::endl;
            std::cout << "1. Postfix Calculator" << std::endl;
            std::cout << "2. Regular Calculator" << std::endl;
            std::cout << "3. Exit" << std::endl;
            std::cout << "What Calculator would you like to use? (or select 3 to exit) >> ";
            std::getline(std::cin, input);

            // Check if input is a valid integer
            std::stringstream ss(input);
            if (ss >> choice && (choice == 1 || choice == 2 || choice == 3)) {
                break; // Break out of the inner loop if input is valid
            } else {
                std::cout << "Invalid choice. Please select 1, 2, or 3." << std::endl;
            }
        }

        // Convert the input to an integer
        std::stringstream(input) >> choice;

        if (choice == 3) {
            std::cout << "See you next time! :)" << std::endl;
            break; // Break out of the outer loop if choice is 3
        }

        if (choice == 1) {
            std::string postfix_expr;

            std::cout << "Enter a postfix expression (be sure to add ' ' spaces in between your characters): ";
            std::getline(std::cin, postfix_expr);    // reading one line from keyboard

            Calculator calc(postfix_expr);

            std::cout << ">> " + postfix_expr + " = " << calc.evaluate() << "\n" << std::endl;

        } else if (choice == 2) {
            std::string arithmetic_expr;

            std::cout << "Enter an arithmetic expression: ";
            std::getline(std::cin, arithmetic_expr);    // reading one line from keyboard

            BasicCalculator basicCalc(arithmetic_expr);

            std::cout << "\t" + arithmetic_expr + " = " << basicCalc.evaluate() << "\n" << std::endl;
        }
    }

    return 0;
}
