#include <string.h>
#include "calc.h"
#include "stack.h"

float Calculator::evaluate() {
    Stack stack;
    char* token;
    float operand1, operand2;
    float val = 0;

    token = strtok(postfix, " ");
    while(token){
        if (token is numeric) {
            // do something
        }
        else { // token is an operator
            // do something
        }
        token = strtok(NULL, " ");
    }
    // get the result

    return val;
}
