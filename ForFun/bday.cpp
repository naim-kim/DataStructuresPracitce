#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to get list of names and birthdays from the user
vector<pair<string, string>> getNamesAndBirthdays() {
    vector<pair<string, string>> namesAndBirthdays;
    string input;

    cout << "Enter names and birthdays in the format 'name yyyy-mm-dd'. Enter 'done' to finish:\n";

    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "done")
            break;

        size_t pos = input.find('\t'); // Assuming the input is separated by a tab character
        if (pos == string::npos) {
            cout << "Invalid input format. Please enter in the format 'name yyyy-mm-dd'.\n";
            continue;
        }

        string name = input.substr(0, pos);
        string birthday = input.substr(pos + 1);

        namesAndBirthdays.push_back(make_pair(name, birthday));
    }

    return namesAndBirthdays;
}

int main() {
    vector<pair<string, string>> namesAndBirthdays = getNamesAndBirthdays();

    // Code for the next steps will go here

    return 0;
}
