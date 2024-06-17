#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 128; // ascii size

// To lowercase
char toLower(char c) {
    return tolower(static_cast<unsigned char>(c));
}

// Custom bubble sort
void bubbleSort(char chars[], int freq[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (freq[j] < freq[j + 1] || (freq[j] == freq[j + 1] && chars[j] > chars[j + 1])) {
                swap(freq[j], freq[j + 1]);
                swap(chars[j], chars[j + 1]);
            }
        }
    }
}

int main() {
    char fileName[100];
    cout << "Enter a file name: ";
    cin >> fileName;

    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        cerr << "Cannot open file: " << fileName << endl;
        return 1;
    }

    int counter[SIZE] = {0};
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isprint(ch) && !isspace(ch)) { // Ignore whitespace
            ch = toLower(ch);
            counter[ch]++;
        }
    }

    fclose(file);

    char chars[SIZE];
    int freq[SIZE];
    int size = 0;

    for (int i = 0; i < SIZE; ++i) {
        if (counter[i] > 0) {
            chars[size] = i;
            freq[size] = counter[i];
            size++;
        }
    }

    bubbleSort(chars, freq, size);

    cout << "10 most frequent characters:\n";
    for (int i = 0; i < 10 && i < size; ++i) {
        cout << i+1 << ") " << chars[i] << ": " << freq[i] << endl;
    }

    return 0;
}
