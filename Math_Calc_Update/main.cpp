//DataStructures-02 22000056 Naim Kim
// input sensitive ** undistinguies bug occurs sometimes.. will fix soon.,

#include <iostream>
#include <string>
#include <sstream>
#include "postfix_calc.h"
#include "basic_calc.h"

int main()
{
    while (true)
    {
        int choice = 0;
        std::string input;

        while (true)
        {
            std::cout << "Select Calculator Type:" << std::endl;
            std::cout << "1. Postfix Calculator" << std::endl;
            std::cout << "2. Regular Calculator" << std::endl;
            std::cout << "3. Exit\n"
                      << std::endl;
            std::cout << "What Calculator would you like to use? (or select 3 to exit) >> ";
            std::getline(std::cin, input);

            // Check if input is a valid integer
            // added to prevent infinite loop... when adding text
            std::stringstream ss(input);
            if (ss >> choice && (choice == 1 || choice == 2 || choice == 3))
            {
                break;
            }
            else
            {
                std::cout << "Invalid choice. Please select 1, 2, or 3." << std::endl;
            }
        }

        // Convert input to an int
        std::stringstream(input) >> choice;

        if (choice == 3)
        {
            std::cout << "See you next time! :)" << std::endl;
            break;
        }

        if (choice == 1)
        {
            std::string postfix_expr;

            std::cout << "Enter a postfix expression (be sure to add ' ' spaces in between your characters): ";
            std::getline(std::cin, postfix_expr);

            Calculator calc(postfix_expr);

            std::cout << ">> " + postfix_expr + " = " << calc.evaluate() << "\n"
                      << std::endl;
        }
        else if (choice == 2)
        {
            std::string arithmetic_expr;

            std::cout << "Enter an arithmetic expression: ";
            std::getline(std::cin, arithmetic_expr);

            BasicCalculator basicCalc(arithmetic_expr);

            std::cout << "\t" + arithmetic_expr + " = " << basicCalc.evaluate() << "\n"
                      << std::endl;
        }
    }
    return 0;
}
