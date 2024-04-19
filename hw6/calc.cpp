#include <string>
#include <cstring> // Include cstring for strtok function
#include "calc.h"
#include "stack.h"

float Calculator::evaluate() {
    Stack<float> stack;
    char* token;
    float operand1, operand2;
    float val = 0;

    // Convert the postfix string to a C-style string
    char* postfix_cstr = const_cast<char*>(postfix.c_str());

    token = strtok(postfix_cstr, " ");
    while(token){
        if (isdigit(*token)) {
            stack.push(atof(token)); // Convert string to float and push to stack
        }
        else { // token is an operator
            operand2 = stack.pop();
            operand1 = stack.pop();
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
                    stack.push(operand1 / operand2);
                    break;
                default:
                    cout << "Invalid operator encountered!" << endl;
                    return 0;
            }
        }
        token = strtok(NULL, " ");
    }
    val = stack.pop(); // Result is stored in the top of the stack

    return val;
}