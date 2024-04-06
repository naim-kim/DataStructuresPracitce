#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include "contact.h"

#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

void Contact::load(string file_name) {
    char c_str[1024];
    strcpy(c_str, file_name.c_str());

    ifstream file(c_str);
    if (!file.is_open()) {
        cerr << "Unable to open file." << endl;
        return;
    }

}
void Contact::print() {
    // implement here
}

// implement the other functions here 

