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
#include <iostream>             // for cout and cin
#include <iomanip>              // for setw and justifications
#include <cctype>               // for isalpha() and isdigit()
#include <fstream>              // for reading from i/o files
#include <string>               // for length()

using namespace std;

int main(int argc, char *argv[]) {

  //variable declarations
  int lineChCount = 0;    //line totals
  int lineLetter = 0;
  int lineDigit = 0;
  int lineNeither = 0;

  int lineIndex = 0;        //Totals
  int totalLetters = 0;
  int totalDigits = 0;
  int totalNeither = 0;
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
    cout << "==> ./Project_06 inputFileName outputFileName\n";
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

  //if in fail state, run loop until no longer in fail state
  while (!inFile) {

    //input file error message
    cout << left << string(15, '*') << " File Open Error " << string(15, '*') << endl;
    cout << "==> Input file failed to open properly!!\n";
    cout << "==> Attempted to open file: " << inFileName << endl;
    cout << "==> Please try again...\n";
    cout << string(47,'*') << "\n\n";

    //clear input file stream
    inFile.clear();

    //prompt for and read in a different inFileName
    cout << "Enter in the name of the input file: ";
    cin >> inFileName;
    cout << inFileName << "\n\n";

    //open inFile and check status
    inFile.open(inFileName);
    getline(inFile, line, '\n');
  }

  //if the end of the input file is reached, the file is empty
  if (inFile.eof()) {
    cout << left << string(13, '*') << " Input File Is Empty " << string(13, '*') << endl;
    cout << "==> The input file is empty." << endl;
    cout << "==> Terminating the program." << endl;
    cout << string(47, '*') << endl << endl;

    return 1;
  }

  //open outFile and check status
  cout << "Opening the output file...\n\n";
  outFile.open(outFileName.c_str());

  //test outFile with header
  outFile << left << setw(15);

  //while in fail state, loop until no longer in fail state
  while (!outFile) {

    //output file error message
    cout << left << string(15, '*') << " File Open Error " << string(15, '*') << endl;
    cout << "==> Output file failed to open properly!!\n";
    cout << "==> Attempted to open file: " << outFileName << endl;
    cout << "==> Please try again...\n";
    cout << string(47,'*') << "\n\n";

    //prompt for and read in a different outFileName
    cout << "Enter in the name of the output file: ";
    cin >> outFileName;
    cout << outFileName << "\n\n";

    //open outFile and check status
    outFile.open(outFileName.c_str());

    //test outFile with header
    outFile << left << setw(15);
  }

  //start outputting info to outFile

  //start of table
  outFile << left << setw(15) << "Line Number" << setw(10) << "Letters" << setw(10) << "Digits" << setw(10) << "Other" << "Total" << endl;
  outFile << left << setw(15) << string(11, '-') << setw(10) << string(7, '-') << setw(10) << string(6, '-') << setw(10) << string(5, '-') << string(5, '-') << endl;

  //while the end of the file has not been reached
  while (inFile.good()) {

    int i = 0;

    //reset line totals
    lineLetter = 0;
    lineDigit = 0;
    lineNeither = 0;
    lineChCount = 0;

    //add one to the total number of lines
    lineIndex++;

    while ((i < line.length()) && inFile.good()) {

      ch = line[i];

      if (isalpha(ch)) {
        //line totals
        lineLetter++;

        //global totals
        totalChar++;
      }
      else if (isdigit(ch)) {
        //line totals
        lineDigit++;

        //gloabl totals
        totalChar++;
      }
      else {
        //line totals
        lineNeither++;

        //gloabl totals
        totalChar++;
      }

      i++;

    }

    //new line character isn't counted, so increment the total and line total by one to account for it
    lineNeither++;
    totalChar++;

    // Update overall totals
    totalLetters += lineLetter;
    totalDigits += lineDigit;
    totalNeither += lineNeither;

    //output to table
    outFile << left << setw(15) << lineIndex << setw(10) << lineLetter << setw(10) << lineDigit << setw(10) << lineNeither <<  (lineLetter + lineDigit + lineNeither) << endl;

    //read in next line before looping back
    getline(inFile, line, '\n');
  }

  //calculate percentages
  letterPer = ((double)totalLetters/(double)totalChar) * 100;
  digitPer = ((double)totalDigits/(double)totalChar) * 100;
  neitherPer = ((double)totalNeither/(double)totalChar) * 100;

  //total and percent row on tables
  outFile << string(50, '-')<< endl;
  outFile << left << setw(15) << "Totals" << setw(10) << totalLetters << setw(10) << totalDigits << setw(10) << totalNeither << totalChar << endl;
  outFile << left << fixed << setprecision(2) << setw(15) << "Percent" << setw(10) << letterPer << setw(10) << digitPer << neitherPer << "\n\n";

  //close input and output files
  inFile.close();
  outFile.close();

  //end of program
  return 0;
}
