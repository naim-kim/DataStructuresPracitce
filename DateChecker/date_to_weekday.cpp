#include <iostream>
#include <string>

using namespace std;

// Function to determine if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the day of the week for a given date
string getDayOfWeek(int day, int month, int year) {
    // Array with leading number of days values
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) {
        year -= 1;
    }
    int weekDay = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;

    // Array with days of the week
    string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return daysOfWeek[weekDay];
}

int main() {
    string date;
    int year, month, day;
    
    while (true) {
        cout << "Enter date (yyyy-mm-dd) or 'q' to quit: ";
        cin >> date;
        
        if (date == "q") {
            break;
        }
        
        // Parse the date string
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        
        string dayOfWeek = getDayOfWeek(day, month, year);
        cout << "The day of the week is: " << dayOfWeek << endl;
    }

    cout << "Program terminated." << endl;
    return 0;
}
