// postfix_calc.cpp

#include "postfix_calc.h"
#include <sstream> // for std::istringstream

float Calculator::evaluate()
{
    std::stack<float> stack;
    std::istringstream iss(postfix);
    std::string token;
    float val;

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            stack.push(std::stof(token));
        }
        else
        {
            float operand2 = stack.top();
            stack.pop();
            float operand1 = stack.top();
            stack.pop();

            switch (token[0])
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
                    std::cerr << "Error: Division by zero encountered!" << std::endl;
                    return 0;
                }
                stack.push(operand1 / operand2);
                break;
            default:
                std::cerr << "Invalid operator encountered!" << std::endl;
                return 0;
            }
        }
    }

    if (!stack.empty())
    {
        val = stack.top();
        stack.pop();
    }
    else
    {
        std::cerr << "Error: No result calculated." << std::endl;
        return 0;
    }

    if (!stack.empty())
    {
        std::cerr << "Error: Multiple values left on stack." << std::endl;
        return 0;
    }
    return val;
}
