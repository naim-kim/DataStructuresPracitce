#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// To lowercase
char toLower(char c) {
    return tolower(static_cast<unsigned char>(c));
}

// Comparator func for sorting
bool comparator(const pair<char, int>& a, const pair<char, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    string fileName;
    cout << "Enter a file name: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file) {
        cerr << "Cannot open file: " << fileName << endl;
        return 1;
    }

    map<char, int> counter;
    char ch;

    while (file.get(ch)) {
        if (isprint(ch) && !isspace(ch)) { // Ignore whitespace
            ch = toLower(ch); // match lower case
            counter[ch]++;
        }
    }

    file.close();

    vector<pair<char, int>> freqVec(counter.begin(), counter.end());

    // STL sort
    sort(freqVec.begin(), freqVec.end(), comparator);

    cout << "10 most frequent characters:\n";
    for (int i = 0; i < 10 && i < freqVec.size(); ++i) {
        cout << i + 1 << ") " << freqVec[i].first << ": " << freqVec[i].second << endl;
    }

    return 0;
}
