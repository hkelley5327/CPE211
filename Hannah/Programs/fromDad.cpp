#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
    // Check for correct number of command line arguments
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    // Input and output file streams
    ifstream inputFile;
    ofstream outputFile;

    // Open input file
    while (!inputFile.is_open()) {
        cout << "Enter input file name: ";
        string inputFileName;
        cin >> inputFileName;
        inputFile.open(inputFileName);
        if (!inputFile.is_open()) {
            cerr << "Error opening input file: " << inputFileName << endl;
        }
    }
    cout << "Opening the input file...\n";

    // Open output file
    while (!outputFile.is_open()) {
        cout << "Enter output file name: ";
        string outputFileName;
        cin >> outputFileName;
        outputFile.open(outputFileName);
        if (!outputFile.is_open()) {
            cerr << "Error opening output file: " << outputFileName << endl;
        }
    }
    cout << "Opening the output file...\n";

    // Output column headings
    outputFile << setw(15) << left << "Line Number" << setw(10) << left << "Letters" << setw(10) << left << "Digits" << setw(10) << left << "Other" << " Total" << endl;
    outputFile << setw(15) << left << "-----------" << setw(10) << left << "-------" << setw(10) << left << "-------" << setw(10) << left << "-------" << " -----" << endl;

    // Initialize counters
    int lineNumber = 1;
    int totalLetters = 0;
    int totalDigits = 0;
    int totalOther = 0;
    int totalCharacters = 0;

    // Read and process input file line by line
    string line;
    while (getline(inputFile, line)) {
        int letters = 0;
        int digits = 0;
        int other = 0;

        for (char c : line) {
            if (isalpha(c)) {
                letters++;
            } else if (isdigit(c)) {
                digits++;
            } else {
                other++;
            }
        }

        totalLetters += letters;
        totalDigits += digits;
        totalOther += other;
        totalCharacters += letters + digits + other;

        // Output line results
        outputFile << setw(15) << left << lineNumber << setw(10) << left << letters << setw(10) << left << digits << setw(10) << left << other << " " << letters + digits + other << endl;

        lineNumber++;
    }

    // Output total and percentage lines
    outputFile << setw(15) << left << "Total" << setw(10) << left << totalLetters << setw(10) << left << totalDigits << setw(10) << left << totalOther << " " << totalCharacters << endl;
    outputFile << setw(15) << left << "Percent" << setw(10) << left << fixed << setprecision(2) << (double)totalLetters / totalCharacters * 100 << setw(10) << left << fixed << setprecision(2) << (double)totalDigits / totalCharacters * 100 << setw(10) << left << fixed << setprecision(2) << (double)totalOther / totalCharacters * 100 << " " << 100.0 << endl;

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
