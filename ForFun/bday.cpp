#include <iostream>
#include <fstream> // File I/O
#include <string>
#include <vector>
#include <algorithm>
#include <cctype> // isspace
#include <sstream> // istringstream

using namespace std;

// Function to get list of names and birthdays from the user
vector<pair<string, string>> getNamesAndBirthdays() {
    vector<pair<string, string>> namesAndBirthdays;
    string input;

    cout << "Enter the list of names and birthdays 'name yyyy-mm-dd'. Enter 'done' to finish:\n";

    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "done")
            break;

        // split string
        istringstream iss(input);
        string name, birthday;
        iss >> name >> birthday;

        if (name.empty() || birthday.empty()) {
            cout << "Please enter in the format 'name yyyy-mm-dd' or 'done' to finish\n";
            continue;
        }

        namesAndBirthdays.push_back(make_pair(name, birthday));
    }

    return namesAndBirthdays;
}

// Function to sort birthdays (ignore year)
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

void printSortedBirthdays(const vector<pair<string, string>>& namesAndBirthdays) {
    cout << "Birthdays by Month:\n";

    // Iterate through each month
    for (int month = 1; month <= 12; ++month) {
        cout << " [ " << month << "¿ù ]" << endl;

        for (const auto& entry : namesAndBirthdays) {
            int birthdayMonth = stoi(entry.second.substr(5, 2));

            // If bday month == current month, print (day & name)
            if (birthdayMonth == month) {
                cout << entry.second.substr(8) << " - " << entry.first << endl;
            }
        }

        cout << endl;
    }
}

void saveBirthdaysToFile(const vector<pair<string, string>>& namesAndBirthdays, const string& filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        outputFile << "Birthdays by Month:\n";

        for (int month = 1; month <= 12; ++month) {
            outputFile << " [ " << month << "¿ù ]" << endl;

            for (const auto& entry : namesAndBirthdays) {
                int birthdayMonth = stoi(entry.second.substr(5, 2));

                if (birthdayMonth == month) {
                    outputFile << entry.second.substr(8) << " - " << entry.first << endl;
                }
            }

            outputFile << endl;
        }

        cout << "Data saved to " << filename << endl;
        outputFile.close();

    } else {

        cerr << "Unable to open file: " << filename << endl;
    }
}

int main() {
    vector<pair<string, string>> namesAndBirthdays = getNamesAndBirthdays();

    sortBirthdays(namesAndBirthdays);

    printSortedBirthdays(namesAndBirthdays);

    string filename;
    cout << "Enter filename to save data: ";
    getline(cin, filename);

    saveBirthdaysToFile(namesAndBirthdays, filename);

    return 0;
}