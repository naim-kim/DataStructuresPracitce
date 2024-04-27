#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Item {
public:
    string data;
    Item* next;

    Item(string data) : data(data), next(nullptr) {}
};

class Stack {
private:
    Item* head;

public:
    Stack() : head(nullptr) {}

    void push(string data) {
        Item* newItem = new Item(data);
        if (!head) {
            head = newItem;
        } else {
            newItem->next = head;
            head = newItem;
        }
    }

    string pop() {
        if (!head) {
            return "";
        } else {
            Item* temp = head;
            string data = temp->data;
            head = head->next;
            delete temp;
            return data;
        }
    }

    ~Stack() {
        while (head) {
            Item* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void output(const string& file_name) {
    Stack stack;
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error opening" << file_name << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, id, email;
        getline(ss, name, ',');
        getline(ss, id, ',');
        getline(ss, email, ',');
        stack.push(id + ", " + name + ", " + email);
    }
    file.close();

    while (true) {
        string data = stack.pop();
        if (data != "") {
            cout << data << endl;
        } else {
            break;
        }
    }
}

int main() {
    string file_name;
    cout << "Enter the input file name: ";
    cin >> file_name;
    output(file_name);
    return 0;
}