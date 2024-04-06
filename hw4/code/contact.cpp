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
     total_num = 0; // Reset total_num before loading contacts

    string line;
    while (getline(file, line)) {
        persons[total_num++] = str2person(line);
    }
    file.close();
}

void Contact::print() {

    for (int i = 0; i < total_num; ++i) {
        cout << "[" << persons[i].name << "][" << persons[i].dob.year << persons[i].dob.month << persons[i].dob.day << "][" << persons[i].email << "][" << persons[i].phone << "]" << endl;
    }
}

// implement the other functions here 

