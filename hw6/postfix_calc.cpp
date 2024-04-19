#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "postfix_calc.h"
#include "stack.h"

float Calculator::evaluate() {
    Stack<float> stack;
    char* token;
    float val = 0;

    // Convert the postfix string to a C-style string
    char* postfix_cstr = const_cast<char*>(postfix.c_str());

    // Tokenize the postfix expression
    token = strtok(postfix_cstr, " ");
    while(token){
        // Check if the token represents a number
        if (isdigit(*token) || (strlen(token) > 1 && *token == '-' && isdigit(token[1]))) {
            stack.push(atof(token)); // Convert string to float and push to stack
        }
        else { // token is an operator
            float operand2, operand1;
            if (!stack.isEmpty()) {
                operand2 = stack.pop();
            } else {
                std::cout << "Error: Not enough operands for operator." << std::endl;
                return 0;
            }

            if (!stack.isEmpty()) {
                operand1 = stack.pop();
            } else {
                std::cout << "Error: Not enough operands for operator." << std::endl;
                return 0;
            }

            switch(*token) {
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
                        std::cout << "Error: Division by zero encountered!" << std::endl;
                        return 0;
                    }
                    stack.push(operand1 / operand2);
                    break;
                default:
                    std::cout << "Invalid operator encountered!" << std::endl;
                    return 0;
            }
        }
        // Get the next token
        token = strtok(NULL, " ");
    }

    // Retrieve the final result from the stack
    if (!stack.isEmpty()) {
        val = stack.pop(); // Result is stored in the top of the stack
    } else {
        std::cout << "Error: No result calculated." << std::endl;
        return 0;
    }

    // Check if there are multiple values left on the stack
    if (!stack.isEmpty()) {
        std::cout << "Error: Multiple values left on stack. The postfix expression is invalid." << std::endl;
        return 0;
    }

    return val;
}
