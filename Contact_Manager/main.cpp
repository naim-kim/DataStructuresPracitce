#include <iostream>
#include <string>
#include "contact.h" // Assuming your header file is named contact.h

using namespace std;

#define MAX_NUM 1000 // Can be given by standard input

int main() {
    string file_name;
    Contact *contacts;
    contacts = new Contact(MAX_NUM);

    cout << "Enter the file name of contact data:" << endl;
    cin >> file_name;

    contacts->load(file_name);
    contacts->print();

    delete contacts; // Free allocated memory before exit

    return 0;
}
