#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Variables to hold the file names
    std::string inputFileName;
    std::string outputFileName;
    std::string additionalText;

    // Ask the user for the input file name
    std::cout << "Enter the name of the file to read from: ";
    std::cin >> inputFileName;

    // Create an input file stream
    std::ifstream inputFile(inputFileName);

    // Check if the input file was opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << inputFileName << std::endl;
        return 1; // Exit with error code
    }

    // Ask the user for the additional text to add to the file content
    std::cout << "Enter the text to add to the file content: ";
    std::cin.ignore(); // Ignore the newline character left by std::cin
    std::getline(std::cin, additionalText);

    // Ask the user for the output file name
    std::cout << "Enter the name of the file to save the new content: ";
    std::cin >> outputFileName;

    // Create an output file stream
    std::ofstream outputFile(outputFileName);

    // Check if the output file was opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create file " << outputFileName << std::endl;
        return 1; // Exit with error code
    }

    // Read the input file and write its content to the output file
    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    // Write the additional text to the output file
    outputFile << additionalText << std::endl;

    // Close both files
    inputFile.close();
    outputFile.close();

    std::cout << "File content has been read from " << inputFileName
              << " and saved to " << outputFileName << " with the additional text." << std::endl;

    return 0; // Exit successfully
}
