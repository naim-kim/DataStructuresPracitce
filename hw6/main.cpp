#include <iostream>
#include <string>
#include "calc.h"

using namespace std;

int main() {
	string str;

    cout << "Input postfix expression: ";
	getline(cin, str);	// reading one line from keyboard

	Calculator calc(str);

    cout << "Result = " << calc.evaluate() << endl;

	return 0;
}
