#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Variable to hold the file name
    std::string fileName;

    // Ask the user for the file name
    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    // Create an input file stream
    std::ifstream inputFile(fileName);

    // Check if the file was opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return 1; // Exit with error code
    }

    // Read and print the contents of the file
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0; // Exit successfully
}
