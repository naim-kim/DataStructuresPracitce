#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Contact {
    string name;
    string birthday;
    string email;
    string phone_number;
};

vector<Contact> contacts;

void load(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Can't open file: " << filename << endl;
        return;
    }
    
    contacts.clear();
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        Contact contact;
        getline(ss, contact.name, ';');
        getline(ss, contact.birthday, ';');
        getline(ss, contact.email, ';');
        getline(ss, contact.phone_number, ';');
        contacts.push_back(contact);
    }
    inputFile.close();
}

void save(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Can't open file: " << filename << endl;
        return;
    }
    
    for (const auto& contact : contacts) {
        outputFile << contact.name << ";" 
                   << contact.birthday << ";" 
                   << contact.email << ";" 
                   << contact.phone_number << endl;
    }
    outputFile.close();
}

void insert(const Contact& contact) {
    contacts.push_back(contact);
}

void deleteContact(const string& name) {
    contacts.erase(remove_if(contacts.begin(), contacts.end(), 
                             [&](const Contact& contact) { return contact.name == name; }), 
                   contacts.end());
}

Contact* retrieveByName(const string& name) {
    for (auto& contact : contacts) {
        if (contact.name == name) {
            return &contact;
        }
    }
    return nullptr;
}

Contact* retrieveByEmail(const string& email) {
    for (auto& contact : contacts) {
        if (contact.email == email) {
            return &contact;
        }
    }
    return nullptr;
}

void sortByName() {
    sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.name < b.name;
    });
}

void sortByBirthday() {
    sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        return a.birthday < b.birthday;
    });
}

void printContacts() {
    for (const auto& contact : contacts) {
        cout << left << setw(20) << contact.name
             << setw(12) << contact.birthday
             << setw(25) << contact.email
             << setw(15) << contact.phone_number << endl;
    }
}

int main() {
    load("contacts.txt");

    Contact newContact = {"Jake Lee", "30456222", "email@example.com", "010-1234-5678"};
    insert(newContact);

    cout << "All contacts:" << endl;
    printContacts();

    cout << "\nSorted by name:" << endl;
    sortByName();
    printContacts();

    cout << "\nSorted by birthday:" << endl;
    sortByBirthday();
    printContacts();

    cout << "\nRetrieving by name (Jake Lee):" << endl;
    Contact* contact = retrieveByName("Jake Lee");
    if (contact) {
        cout << contact->name << " - " << contact->birthday << " - " << contact->email << " - " << contact->phone_number << endl;
    } else {
        cout << "Contact not found." << endl;
    }

    cout << "\nRetrieving by email (email@example.com):" << endl;
    contact = retrieveByEmail("email@example.com");
    if (contact) {
        cout << contact->name << " - " << contact->birthday << " - " << contact->email << " - " << contact->phone_number << endl;
    } else {
        cout << "Contact not found." << endl;
    }

    cout << "\nDeleting contact (Jake Lee):" << endl;
    deleteContact("Jake Lee");
    printContacts();

    save("contacts.txt");

    return 0;
}
