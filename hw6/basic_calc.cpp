#include "basic_calc.h"
#include "stack.h"

bool BasicCalculator::isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int BasicCalculator::precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // Parentheses have the highest precedence
}

std::string BasicCalculator::infixToPostfix(std::string infixExpr) {
    std::string postfix;
    Stack<char> operatorStack;

    for (char& ch : infixExpr) {
        if (isdigit(ch) || ch == '.') {
            postfix += ch;
        } else if (ch == '(') {
            operatorStack.push(ch);
        } else if (ch == ')') {
            while (!operatorStack.isEmpty() && operatorStack.read_top() != '(') {
                postfix += operatorStack.pop();
            }
            operatorStack.pop(); // Pop '('
        } else if (isOperator(ch)) {
            while (!operatorStack.isEmpty() && precedence(ch) <= precedence(operatorStack.read_top())) {
                postfix += operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.pop();
    }

    return postfix;
}

float BasicCalculator::evaluate() {
    // Convert infix expression to postfix
    std::string postfixExpr = infixToPostfix(infix);

    // Evaluate postfix expression using the postfix calculator
    Calculator postfixCalc(postfixExpr);
    return postfixCalc.evaluate();
}
