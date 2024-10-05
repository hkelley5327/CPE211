// ****************************************
// Program Title: Project 6
// Project File: Project_06.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 10/10/24
// Program description: project will open and read
// an input file and display the number of letters,
// digits, and percentages of each in an output file
// ****************************************

//include necessary header files
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

  //variable declarations
  int lineChCount = 0;    //line totals
  int lineLetter = 0;
  int lineDigit = 0;
  int lineNeither = 0;

  int numLine = 0;

  int letterTotal = 0;    //global Totals
  int digitTotal = 0;
  int neitherTotal = 0;
  int totalChar = 0;

  string line;
  char ch;
  double letterPer, digitPer, neitherPer;

  //command line arguments present? right number?
  if(argc != 3) {
    cout << endl;
    cout << string(9,'*') << " Command Line Argument Error " << string(9,'*') << endl;
    cout << "==> Incorrect number of Command Line Arguments!\n";
    cout << "==> Command for running the program is:\n";
    cout << "==> ./Project_05 inputFileName\n";
    cout << string(47,'*') << endl << endl;
    return 1;
  }

  //iostream object declarations
  string inFileName = argv[1];
  string outFileName = argv[2];
  ifstream inFile;
  ofstream outFile;

  //open inFile and check status
  cout << "\nOpening the input file...\n\n";
  inFile.open(inFileName);
  getline(inFile, line, '\n');

  //if the end of the file is reached, the file is empty
  if (inFile.eof()) {
    cout << left << string(13, '*') << "Input File Is Empty" << string(13, '*');
    cout << "==> The input file is empty.";
    cout << "==> Terminating the program.";
    cout << string(47, '*') << "\n\n";

    return 1;
  }

  //if in fail state, run loop until no longer in fail state
  while (!inFile) {

    //input file error message
    cout << left << string(15, '*') << "File Open Error" << string(15, '*') << endl;
    cout << "==> Input file failed to open properly!!\n";
    cout << "==> Attempted to open file: " << inFileName << endl;
    cout << "==> Please try again...\n";
    cout << string(47,'*') << "\n\n";

    //clear input file stream
    inFile.clear();

    //prompt for and read in a different inFileName
    cout << "Enter in the name of the input file: ";
    cin >> inFileName;

    //open inFile and check status
    cout << "\nOpening the input file...\n";
    inFile.open(inFileName);
    getline(inFile, line, '\n');
  }

  //open outFile and check status
  cout << "Opening the output file...\n\n";
  outFile.open(outFileName.c_str());

  //test outFile with header
  outFile << left << setw(15) << "Line Number" << setw(10) << "Letters" << setw(10) << "Digits" << setw(10) << "Other" << "Total" << endl;

  //check status
  while (!outFile) {

    //output file error message
    cout << left << string(15, '*') << "File Open Error" << string(15, '*') << endl;
    cout << "==> Output file failed to open properly!!\n";
    cout << "==> Attempted to open file: " << outFileName << endl;
    cout << "==> Please try again...\n";
    cout << string(47,'*') << "\n\n";

    //prompt for and read in a different outFileName
    cout << "Enter in the name of the output file: ";
    cin >> outFileName;

    //open outFile and check status
    cout << "Opening the output file...\n\n";
    outFile.open(outFileName.c_str());

    //test outFile with header
    outFile << left << setw(15) << "Line Number" << setw(10) << "Letters" << setw(10) << "Digits" << setw(10) << "Other" << "Total" << endl;
  }

  //start outputting info to outFile

  //start of table
  outFile << left << setw(15) << string(11, '-') << setw(10) << string(7, '-') << setw(10) << string(7, '-') << setw(10) << string(5, '-') << string(5, '-') << endl;

  //while the end of the file has not been reached
  while (inFile.good()) {

    int i = 0;

    //reset line totals
    lineLetter = 0;
    lineDigit = 0;
    lineNeither = 0;
    lineChCount = 0;

    //add one to the total number of lines
    numLine++;

    while (i <= (line.lenght() - 1) && inFile.good()) {

      ch = line[i];

      //global totals
      lineChCount++;
      totalChar++;

      //line total
      lineChCount++;

      if (isalpha(ch)) {
        //line totals
        lineLetter++;
        letterTotal++;
      }
      else if (isdigit(ch)) {
        //line totals
        lineDigit++;
        digitTotal++;
      }
      else {
        //line totals
        lineNeither++;
        neitherTotal++;

        //for debugging purposes only
        //cout << numLine << "******" << endl << << "i- " << i << endl << lineLetter << endl << letterTotal << endl << lineChCount << endl << digitTotal << endl << lineNeither << endl << neitherTotal << endl << totalChar << endl << lineDigit << "\n\n";
      }

      i++;

    }

    //new line character isn't counted, so increment the total and line total by one to account for it
    lineNeither++;
    totalChar++;

    outFile << left << setw(15) << numLine << setw(10) << lineLetter << setw(10) << lineDigit << setw(10) << lineNeither <<  lineChCount << endl;

    //read in next line before looping back
    getline(inFile, line, '\n');
  }

  //calculate percentages
  letterPer = ((double)letterTotal/(double)totalChar) * 100;
  digitPer = ((double)digitTotal/(double)totalChar) * 100;
  neitherPer = ((double)neitherTotal/(double)totalChar) * 100;

  //total and percent row on tables
  outFile << string(50, '-') << endl;
  outFile << left << setw(15) << "Totals" << setw(10) << letterTotal << setw(10) << digitTotal << setw(10) << neitherTotal << totalChar << endl;
  outFile << left << fixed << setprecision(2) << setw(15) << "Percents" << setw(10) << letterPer << setw(10) << digitPer << setw(10) << neitherPer << "\n\n";

  //close input and output files
  inFile.close();
  outFile.close();

  //end of program
  return 0;
}
