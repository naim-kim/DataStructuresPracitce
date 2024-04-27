#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Node {
public:
    string info;
    Node* next;

    Node(string info) : info(info), next(nullptr) {}
};

class Stack {
private:
    Node* head;

public:
    Stack() : head(nullptr) {}

    void push(string info) {
        Node* newNode = new Node(info);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    string pop() {
        if (!head) {
            return "";
        } else {
            Node* temp = head;
            string info = temp->info;
            head = head->next;
            delete temp;
            return info;
        }
    }

    ~Stack() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void output(const string& file_name) {
    Stack stack;
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Error opening " << file_name << endl;
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
        string info = stack.pop();
        if (info != "") {
            cout << info << endl;
        } else {
            break;
        }
    }
}

int main() {
    string file_name;
    while (true) {
        cout << "Enter the input file name: ";
        cin >> file_name;
        output(file_name);
        cout << "Do you want to try again? (y/n): ";
        string ans;
        cin >> ans;
        if (ans != "y") {
            break;
        }
    }
    return 0;
}
