#include <fstream>
#include <string>
#include "calc.h"

int main() {
	string str;

    cout << "input postfix expression:";
	getline(cin, str);	// reading one line from keyboard

	Calculator calc(str);

    cout << "result = " << calc.evaluate() << endl;

	return 0;
}
