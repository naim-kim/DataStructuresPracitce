#include "infix_calc.h"
#include <cctype>
#include <cstdlib>

#include <stack>
#include <iostream>

bool BasicCalculator::isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int BasicCalculator::precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

float BasicCalculator::calculate(float operand1, float operand2, char op)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand2 == 0)
        {
            std::cerr << "Error: Division by zero!" << std::endl;
            exit(1);
        }
        return operand1 / operand2;
    default:
        std::cerr << "Error: Invalid operator!" << std::endl;
        exit(1);
    }
}

float BasicCalculator::evaluate()
{
    std::stack<float> operandStack;
    std::stack<char> operatorStack;

    for (size_t i = 0; i < arithmetic_expr.length(); ++i)
    {
        char ch = arithmetic_expr[i];
        if (isdigit(ch) || ch == '.')
        {
            std::string numStr;
            while (i < arithmetic_expr.length() && (isdigit(ch) || ch == '.'))
            {
                numStr += ch;
                ch = arithmetic_expr[++i];
            }
            operandStack.push(std::stof(numStr));
            --i;
        }
        else if (ch == '(')
        {
            operatorStack.push(ch);
        }
        else if (ch == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                char op = operatorStack.top();
                operatorStack.pop();
                float operand2 = operandStack.top();
                operandStack.pop();
                float operand1 = operandStack.top();
                operandStack.pop();
                operandStack.push(calculate(operand1, operand2, op));
            }
            if (!operatorStack.empty() && operatorStack.top() == '(')
                operatorStack.pop();
        }
        else if (isOperator(ch))
        {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(ch))
            {
                char op = operatorStack.top();
                operatorStack.pop();
                float operand2 = operandStack.top();
                operandStack.pop();
                float operand1 = operandStack.top();
                operandStack.pop();
                operandStack.push(calculate(operand1, operand2, op));
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.empty())
    {
        char op = operatorStack.top();
        operatorStack.pop();
        float operand2 = operandStack.top();
        operandStack.pop();
        float operand1 = operandStack.top();
        operandStack.pop();
        operandStack.push(calculate(operand1, operand2, op));
    }

    return operandStack.top();
}
