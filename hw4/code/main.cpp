#include <iostream>
#include <string>
#include "contact.h"
using namespace std;

#define MAX_NUM 1000 // can be given by standard input

int main() {
    string file_name;
    Contact* contacts;
    contacts = new Contact(MAX_NUM); 

    cout << "file name of contact data:" << endl; 
    cin >> file_name;

    contacts->load(file_name);
    contacts->print();

    return 0;
}
