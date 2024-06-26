//DataStructures-02 22000056 Naim Kim

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "postfix_calc.h"
#include "stack.h"

float Calculator::evaluate()
{
    Stack<float> stack;
    char *token;
    float val = 0;

    // Convert the postfix string to a C-style string
    char *postfix_cstr = const_cast<char *>(postfix.c_str());

    // Tokenizer
    token = strtok(postfix_cstr, " ");
    while (token)
    {
        if (isdigit(*token) || (strlen(token) > 1 && *token == '-' && isdigit(token[1])))
        {
            stack.push(atof(token));
        }
        else
        {
            float operand2, operand1;
            if (!stack.isEmpty())
            {
                operand2 = stack.pop();
            }
            else
            {
                std::cout << "Error: Not enough operands for operator." << std::endl;
                return 0;
            }

            if (!stack.isEmpty())
            {
                operand1 = stack.pop();
            }
            else
            {
                std::cout << "Error: Not enough operands for operator." << std::endl;
                return 0;
            }

            switch (*token)
            {
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
                if (operand2 == 0)
                {
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
        // get next token
        token = strtok(NULL, " ");
    }

    // get the result from stack
    if (!stack.isEmpty())
    {
        val = stack.pop();
    }
    else
    {
        std::cout << "Error: No result calculated." << std::endl;
        return 0;
    }

    if (!stack.isEmpty())
    {
        std::cout << "Error: Multiple values left on stack." << std::endl;
        return 0;
    }
    return val;
}
