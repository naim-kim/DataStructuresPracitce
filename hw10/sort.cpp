#include <iostream>
#include <fstream>
#include <string>

#include <sstream> // for stringstream 
#include <cctype> // for isalnum() and isspace()

#include <map>
#include <algorithm> // for transform()

#include <vector> 

using namespace std;

// Function to replace punctuations by ‘ ‘(whitespace)
string removePunctuation(const string& line) {
    string cleanLine = line;
    for (char& ch : cleanLine) {
        if (!isalnum(ch) && !isspace(ch)) {
            ch = ' ';
        }
    }
    return cleanLine;
}

// Function to convert a string to lowercase <-> upper case
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c){ return tolower(c); });
    return lowerStr;
}
string toUpper(const string& str) {
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), [](unsigned char c){ return toupper(c); });
    return upperStr;
}


// Function to merge two sorted arrays
// sort by frequency descending order & alphabetical order
void merge(vector<pair<string, int>>& vec, int left, int mid, int right) {
    int leftSize = mid - left + 1; // size of left half
    int rightSize = right - mid; // size of right half
    vector<pair<string, int>> L(leftSize);
    vector<pair<string, int>> R(rightSize);

    for (int i = 0; i < leftSize; i++) L[i] = vec[left + i];
    for (int i = 0; i < rightSize; i++) R[i] = vec[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (L[i].second >= R[j].second) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        vec[k] = R[j];
        j++;
        k++;
    }
}
/*******************************************************************************
 * I chose to implement this algorithm because it is efficient
 * with the time complexity of O(nlogn). Meaning that Merge Sort is stable enough 
 * to be used for sorting a list of words frequencies.
 * Moreover, due to my unsatisfactory results on the quiz, I gor motivated to implement it.
********************************************************************************/

void mergeSort(vector<pair<string, int>>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

int main() {
/*
    string fileName;
    cout << "Enter a .txt file: ";
    cin >> fileName;
*/

// Hardcoded file name for temporary use
    string fileName = "1.txt";

    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Can't open file: " << fileName << endl;
        return 1;
    }

    map<string, int> counter;
    string line;

    while (getline(inputFile, line)) {
        // Remove punctuation marks
        string cleanLine = removePunctuation(line);

        // Parse cleaned line into words
        istringstream stream(cleanLine);
        string word;
        while (stream >> word) {
            // Convert word to lowercase
            word = toLower(word);
            // Increment count of word in counter map
            counter[word]++;
        }
    }

    inputFile.close();

    // Convert counter map to vector to sort
    vector<pair<string, int>> vec(counter.begin(), counter.end());

    // sort
    mergeSort(vec, 0, vec.size() - 1);

    // Print sorted
    for (const auto& entry : counter) {
    //    cout << entry.first << ": " << entry.second << endl;
    }

    // Print top 5 words: ( WORD: FREQUENCY )
    cout << "\nTop 5 most frequent words:\n";
    int count = 0;
    for (const auto& entry : vec) {
        if (count < 5) {
            cout << toUpper(entry.first) << ": " << entry.second << endl;
            count++;
        } else {
            break;
        }
    }

    return 0;
}
