#include "postfix_calc.h"
#include <stack>
#include <sstream>
#include <iostream>

float Calculator::evaluate() {
    std::stack<float> stack;
    std::istringstream iss(postfix);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack.push(std::stof(token));
        } else {
            if (stack.size() < 2) {
                std::cerr << "Error: Insufficient operands for the operator '" << token << "'" << std::endl;
                return 0;
            }

            float operand2 = stack.top(); stack.pop();
            float operand1 = stack.top(); stack.pop();

            switch (token[0]) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        std::cerr << "Error: Division by zero encountered!" << std::endl;
                        return 0;
                    }
                    stack.push(operand1 / operand2);
                    break;
                default:
                    std::cerr << "Invalid operator encountered: " << token << std::endl;
                    return 0;
            }
        }
    }

    if (stack.size() != 1) {
        std::cerr << "Error: The postfix expression is invalid. Stack size is not 1 after evaluation." << std::endl;
        return 0;
    }

    return stack.top();
}
