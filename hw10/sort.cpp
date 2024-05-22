#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <cctype>

using namespace std;

// Function to replace punctuations by ‘ ‘(whitespace)
string removePunctuation(const string& line) {
    string cleanedLine = line;
    for (char& ch : cleanedLine) {
        if (!isalnum(ch) && !isspace(ch)) {
            ch = ' ';
        }
    }
    return cleanedLine;
}




int main() {
    string fileName;
    cout << "Enter a .txt file: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Unable to open file: " << fileName << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;

        string cleanedLine = removePunctuation(line);

        // Parse cleaned line into words
        istringstream stream(cleanedLine);
        string word;
        while (stream >> word) {
            cout << word << endl;
        }
    }

    inputFile.close();
    return 0;
}
