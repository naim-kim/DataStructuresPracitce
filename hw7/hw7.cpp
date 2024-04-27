//DataStructures-02 22000056 Naim Kim

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Node
{
public:
    string info;
    Node *next;

    Node(string info) : info(info), next(nullptr) {}
};

class Stack
{
private:
    Node *head;

public:
    Stack() : head(nullptr) {}

    void push(string info)
    {
        Node *newNode = new Node(info);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    string pop()
    {
        if (!head)
        {
            return "";
        }
        else
        {
            Node *temp = head;
            string info = temp->info;
            head = head->next;
            delete temp;
            return info;
        }
    }

    ~Stack()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void output(const string &file_name)
{
    Stack stack;
    ifstream file(file_name);

    if (!file.is_open())
    {
        cerr << "Error opening " << file_name << endl;
        return;
    }

    string line;

    cout << endl << "Input file data: (data format should be 'name, id, email')\n" << endl;

    while (getline(file, line))
    {
        // Skip empty lines
        if (line.empty() || line.find_first_not_of(" \t\n\v\f\r") == string::npos)
        { // findFirstNonWhitespace
            continue;
        }

        stringstream ss(line);
        string name, id, email;

        if (getline(ss, name, ',') && getline(ss, id, ',') && getline(ss, email, ',')) {
            cout << name + ", " + id + ", " + email << endl; // print og content
            stack.push(id + ", " + name + ", " + email);

        } else {
            cout << "file [ " << file_name << " ]'s format is wrong.\n" << endl;
            return; // Exit the func when format is wrong
        }
    }

    file.close();

    cout << "\nOutput data: (the lines are in the reverse order"
         << "\n              and each line has a different order from the input line)\n" << endl;

    while (true)
    {
        string info = stack.pop();
        if (info != "")
        {
            cout << info << endl;
        }
        else
        {
            break;
        }
    }
    cout << endl;
}

int main()
{
    string file_name;
    while (true)
    {
        cout << "Enter the input file name: ";
        cin >> file_name;
        output(file_name);
        cout << "Do you want to try again? (y/n): ";
        string ans;
        cin >> ans;
        if (ans == "n")
        {
            cout << "See you next time! :)" << endl;
            break;
        }
    }
    return 0;
}