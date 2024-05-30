#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>

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
    auto it = remove_if(contacts.begin(), contacts.end(), [&](const Contact& contact) { 
        return contact.name == name; 
    });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
    }
}

Contact* searchName(const string& name) {
    for (auto& contact : contacts) {
        if (contact.name == name) {
            return &contact;
        }
    }
    return nullptr;
}

Contact* searchEmail(const string& email) {
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
    if (contacts.empty()) {
        cout << "file is empty!" << endl;
        return;
    }
    for (const auto& contact : contacts) {
        cout << left << setw(20) << contact.name
             << setw(12) << contact.birthday
             << setw(25) << contact.email
             << setw(15) << contact.phone_number << endl;
    }
}

void showMenu() {
    cout << "1. See all contacts" << endl;
    cout << "2. Search contact" << endl;
    cout << "3. Insert contact" << endl;
    cout << "4. Delete contact" << endl;
    cout << "5. Save contacts to file" << endl;
    cout << "6. Quit" << endl;
}

int main() {
    string filename;
    cout << "Enter file name: ";
    cin >> filename;
    load(filename);

    int input;
    do {
        showMenu();
        cout << "Enter your input: ";
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the newline character from the buffer
        
        switch (input) {
            case 1: {
                int ifsort;
                cout << "1. Sort by name" << endl;
                cout << "2. Sort by birthday" << endl;
                cout << "3. Go back" << endl;
                cout << "Enter your input: ";
                cin >> ifsort;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the newline character from the buffer
                if (ifsort == 1) {
                    sortByName();
                    printContacts();
                } else if (ifsort == 2) {
                    sortByBirthday();
                    printContacts();
                }
                break;
            }
            case 2: {
                int ifsearch;
                cout << "1. Search by name" << endl;
                cout << "2. Search by email" << endl;
                cout << "3. Go back" << endl;
                cout << "Enter your input: ";
                cin >> ifsearch;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the newline character from the buffer
                if (ifsearch == 1) {
                    string name;
                    cout << "Enter name: ";
                    getline(cin, name);
                    Contact* contact = searchName(name);
                    if (contact) {
                        cout << contact->name << " - " << contact->birthday << " - " << contact->email << " - " << contact->phone_number << endl;
                    } else {
                        cout << "Contact not found." << endl;
                    }
                } else if (ifsearch == 2) {
                    string email;
                    cout << "Enter email: ";
                    getline(cin, email);
                    Contact* contact = searchEmail(email);
                    if (contact) {
                        cout << contact->name << " - " << contact->birthday << " - " << contact->email << " - " << contact->phone_number << endl;
                    } else {
                        cout << "Contact not found." << endl;
                    }
                }
                break;
            }
            case 3: {
                Contact contact;
                cout << "Enter name: ";
                getline(cin, contact.name);
                cout << "Enter birthday: ";
                getline(cin, contact.birthday);
                cout << "Enter email: ";
                getline(cin, contact.email);
                cout << "Enter phone number: ";
                getline(cin, contact.phone_number);
                insert(contact);
                break;
            }
            case 4: {
                string name;
                cout << "Enter name of the contact to delete: ";
                getline(cin, name);
                deleteContact(name);
                cout << name << "Deleted" << endl;
                break;
            }
            case 5: {
                save(filename);
                break;
            }
            case 6: {
                cout << "Bye! " << endl;
                break;
            }
            default: {
                cout << "Invalid input.. Try again." << endl;
                break;
            }
        }
    } while (input != 6);

    return 0;
}
