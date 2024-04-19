#include <iostream>
#include <string>
#include "calc.h"

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

            std::cout << "Result = " << calc.evaluate() << std::endl;
        } 
        /*else if (choice == 2) {
            std::cout << "Regular Calculator not implemented yet" << std::endl;
        } */
        else if (choice == 3) {
            std::cout << "Exiting the program..." << std::endl;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
