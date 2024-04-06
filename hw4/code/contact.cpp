// 22000056 김나임

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include "contact.h"

#include <iostream>
#include <sstream>
#include <cstring> // strlen
#include <cctype> // isspace

using namespace std;

void Contact::load(string file_name) {

    char c_str[1024];
    strcpy(c_str, file_name.c_str());

    ifstream file(c_str);
    if (!file.is_open()) {
        cerr << "Unable to open file :(" << endl;
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

Person Contact::str2person(string line) {
    stringstream ss(line);
    string token;
    int i = 0;
    Person p;

    while (getline(ss, token, ';')) {

        char* trimmed = this->trim(const_cast<char*>(token.c_str()));
        token = trimmed;

        switch (i) {
        case 0:
            p.name = token;
            break;

        case 1: {
            string dateStr = token;
            p.dob.year = stoi(dateStr.substr(0, 4));
            p.dob.month = stoi(dateStr.substr(4, 2));
            p.dob.day = stoi(dateStr.substr(6, 2));

            break;
        }

        case 2:
            p.email = token;
            break;
            
        case 3:
            p.phone = token;
            break;
        }
        i++;
    }
    return p;
}

char* Contact::trim(char* s) {
    char* ptr;
    if (!s) return nullptr;
    while (isspace(*s)) s++;
    for (ptr = s + std::strlen(s) - 1; (ptr >= s) && std::isspace(*ptr); --ptr)
        ;
    *(ptr + 1) = '\0';
    return s;
}