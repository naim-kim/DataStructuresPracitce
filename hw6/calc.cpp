// calc.cpp
#include "calc.h"
#include "stack.h"

float Calculator::evaluate() {
    Stack<float> stack;
    string token;
    float operand1, operand2;
    float result = 0;

    size_t pos = 0;
    while ((pos = expression.find(" ")) != string::npos) {
        token = expression.substr(0, pos);
        expression.erase(0, pos + 1);

        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack.push(stof(token)); // Convert string to float and push to stack
        }
        else { // token is an operator
            operand2 = stack.pop();
            operand1 = stack.pop();
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
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid operator encountered!" << endl;
                    return 0;
            }
        }
    }

    result = stack.pop(); // Result is stored in the top of the stack

    return result;
}
