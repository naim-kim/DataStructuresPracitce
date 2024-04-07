#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

// Function to sort birthdays (ignoring year)
void sortBirthdays(vector<pair<string, string>>& namesAndBirthdays) {
    // Custom comparator to compare only the month and day
    auto compareDates = [](const pair<string, string>& a, const pair<string, string>& b) {
        string birthdayA = a.second.substr(5); // Extracting month and day
        string birthdayB = b.second.substr(5);
        return birthdayA < birthdayB;
    };

    // Sorting based on birthdays (ignoring year)
    sort(namesAndBirthdays.begin(), namesAndBirthdays.end(), compareDates);
}

int main() {
    vector<pair<string, string>> namesAndBirthdays = getNamesAndBirthdays();

    sortBirthdays(namesAndBirthdays);

    // Code for the next steps will go here

    return 0;
}
