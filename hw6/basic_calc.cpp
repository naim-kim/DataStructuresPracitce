//DataStructures-02 22000056 Naim Kim

#include "basic_calc.h"
#include "stack.h"
#include <cctype>

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
    return 0; //  () >>>>
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
    Stack<float> operandStack;
    Stack<char> operatorStack;

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
            while (!operatorStack.isEmpty() && operatorStack.read_top() != '(')
            {
                char op = operatorStack.pop();
                float operand2 = operandStack.pop();
                float operand1 = operandStack.pop();
                operandStack.push(calculate(operand1, operand2, op));
            }
            operatorStack.pop(); // Pop '('
        }
        else if (isOperator(ch))
        {
            while (!operatorStack.isEmpty() && precedence(ch) <= precedence(operatorStack.read_top()))
            {
                char op = operatorStack.pop();
                float operand2 = operandStack.pop();
                float operand1 = operandStack.pop();
                operandStack.push(calculate(operand1, operand2, op));
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.isEmpty())
    {
        char op = operatorStack.pop();
        float operand2 = operandStack.pop();
        float operand1 = operandStack.pop();
        operandStack.push(calculate(operand1, operand2, op));
    }

    return operandStack.pop();
}
