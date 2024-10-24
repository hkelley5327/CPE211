// ****************************************
// Program Title: Project 8
// Project File: Project_08.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 11/03/24
// Program description: using input file stream, read in and record data
// to a structure
// ****************************************

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//structures
struct Person {
  string lastName;
  string firstName;
  string phoneNum;
};

struct Address {
  string street;
  string city;
  string state;
  int zipCode;
};

struct Record {
  Person person;
  Address address;
};

//function prototypes
void printHeader(ofstream& outputFile);
void openInputFile(ifstream& inputFile);
void openOutputFile(ofstream& outputFile);
bool readInfo(ifstream& inputFile, Record& record);
void printInfo(Record& record, ofstream& outputFile);

int main() {
  //io stream variable declarations
  ifstream inputFile;
  ofstream outputFile;

  //open io streams
  openInputFile(inputFile);
  openOutputFile(outputFile);

  //declare record structure
  Record record;

  printHeader(outputFile);

  cout << "Processing information. Please Wait....\n\n";

  //while readInfo function returns true
  while (readInfo(inputFile, record)) {
    //print info for each entry
    printInfo(record, outputFile);
  }

  //if we made it to the eof
  if(inputFile.eof()) {
    outputFile << setw(7) << string(5, '-') << setw(20) << string(9, '-') << setw(15) << string(10, '-') << setw(20) << string(4, '-') << string(12, '-') << endl;
    cout << "Program has finished execution.\n\n";
  }
  return 0;
}

//function definitions
void printHeader(ofstream& outputFile) {
  outputFile << left << setw(7) << "Entry" << setw(20) << "Last Name" << setw(15) << "First Name" << setw(20) << "City" << "Phone Number\n";
  outputFile << setw(7) << string(5, '-') << setw(20) << string(9, '-') << setw(15) << string(10, '-') << setw(20) << string(4, '-') << string(12, '-') << endl;
}

void openInputFile(ifstream& inputFile) {
  string inputFileName;

  //ask for and read in input file name
  cout << "\nEnter the name of the input file: ";
  cin >> inputFileName;
  cout << inputFileName << "\n\n";

  //open input file
  inputFile.open(inputFileName.c_str());

  //while in the fail state
  while(inputFile.fail()) {
    //error message
    cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
    cout << "==> Input file failed to open properly!!\n";
    cout << "==> Attempted to open file: " << inputFileName << endl;
    cout << "==> Please try again...\n";
    cout << string(47, '*') << "\n\n";

    //clear input file stream
    inputFile.clear();

    //ask for new file name
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << inputFileName << "\n\n";

    //attempt to open new file name
    inputFile.open(inputFileName.c_str());
  }
}

void openOutputFile(ofstream& outputFile) {
  string outputFileName;

  //ask for output file name
  cout << "Enter the name of the output file: ";
  cin >> outputFileName;
  cout << outputFileName << "\n\n";

  //attempt to open output file stream
  outputFile.open(outputFileName.c_str());

  //while output file stream in the fail state
  while(outputFile.fail()) {
    //error message
    cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
    cout << "==> Output file failed to open properly!!!\n";
    cout << "==> Attempted to open file: " << outputFileName << endl;
    cout << "==> Please try again...\n";
    cout << string(47, '*') << "\n\n";

    //clear output file stream
    outputFile.clear();

    //ask for different output file name
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;
    cout << outputFileName << "\n\n";

    //attempt to open new file name
    outputFile.open(outputFileName.c_str());
  }
}

bool readInfo(ifstream& inputFile, Record& record) {
  inputFile >> record.person.phoneNum;
  inputFile >> record.person.lastName;
  inputFile.ignore(); //ignore the newline character
  getline(inputFile, record.address.street); //contains whitespace
  getline(inputFile, record.address.city);   //contains whitespace
  getline(inputFile, record.address.state);  //contains whitespace
  inputFile >> record.address.zipCode;
  inputFile >> record.person.firstName;

  //after read, if in fail state
  if(inputFile.fail()) {
    //if not at the eof
    if(!inputFile.eof()) {
      //error message
      cout << string(15, '*') << " File Read Error " << string(15, '*') << endl;
      cout << "==> An error has occured while reading\n==> the input file.  Error in file content.\n";
      cout << "==> Terminating program!!!\n";
      cout << string(47, '*') << "\n\n";
    }

    return false;
  }

  return true;
}

void printInfo(Record& record, ofstream& outputFile) {
  //set entry number to zero, then increment each time the function is called
  static int entry = 0;
  entry++;

  //print entry data
  outputFile << left << setw(7) << entry << setw(20) << record.person.lastName << setw(15) << record.person.firstName << setw(20) << record.address.city << record.person.phoneNum << endl;
}
