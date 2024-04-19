#include <iostream>
#include <string>
#include "postfix_calc.h"
#include "calc.h"

using namespace std;

int main() {
    int choice;
    cout << "Select Calculator Type:" << endl;
    cout << "1. Postfix Calculator" << endl;
    cout << "2. Regular Calculator" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cin.ignore(); // Ignore newline character in buffer

    if (choice == 1) {
        string postfix_expr;
        cout << "Input postfix expression: ";
        getline(cin, postfix_expr);

        PostfixCalculator postfix_calc(postfix_expr);
        cout << "Result = " << postfix_calc.evaluate() << endl;
    } else if (choice == 2) {
        string expression;
        cout << "Input expression: ";
        getline(cin, expression);

        Calculator regular_calc(expression);
        cout << "Result = " << regular_calc.evaluate() << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
