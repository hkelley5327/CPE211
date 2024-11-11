// ****************************************
// Program Title: Project 9
// Project File: Project_09.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 11/17/24
// Program description:
// ****************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

typedef int BitArray[MAX_ROWS][MAX_COLS];

//function prototypes
void openInputFile(ifstream&);
void readData(ifstream&, int&, int&, BitArray, BitArray);
void printInputArrays(int&, int&, BitArray, BitArray);
void calcOutputArrays(int&, int&, BitArray, BitArray, BitArray, BitArray, BitArray);
void printOutputArrays(int&, int&, BitArray, BitArray, BitArray);
void printIntegerEquivalents(int&, int&, BitArray, BitArray, BitArray);

int main() {
  ifstream inFile;
  int numRows;
  int numCols;

  BitArray Array1, Array2; //input arrays
  BitArray orArray, andArray, xorArray; //output arrays

  //function calls
  openInputFile(inFile);
  readData(inFile, numRows, numCols, Array1, Array2);
  printInputArrays(numRows, numCols, Array1, Array2);
  calcOutputArrays(numRows, numCols, Array1, Array2, orArray, andArray, xorArray);
  printOutputArrays(numRows, numCols, orArray, andArray, xorArray);
  printIntegerEquivalents(numRows, numCols, orArray, andArray, xorArray);

  return 0;
}

//function definitions

void openInputFile(ifstream& inFile) {
  string inFileName;

  do {

    //ask for and read in input file name
    cout << "\nEnter the name of the input file: ";
    cin >> inFileName;
    cout << inFileName << "\n\n";

    inFile.open(inFileName.c_str());

    if(!inFile) {
      cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
  		cout << "==> Input file failed to open properly!!\n";
  		cout << "==> Attempted to open file: " << inFileName << endl;
  		cout << "==> Please try again...\n";
  		cout << string(47, '*') << "\n\n";
    }

  } while (!inFile);
}

void readData(ifstream& inFile, int& numRows, int& numCols, BitArray Array1, BitArray Array2) {
  int bit;

  inFile >> numRows;
  inFile.ignore(INT_MAX, '\n');
  inFile >> numCols;
  inFile.ignore(INT_MAX, '\n');

  //initial read, read in first bit
  inFile >> bit;

  while(inFile) {
    //read in first input array
    for (int row = 0; row < numRows; row++) {
      for (int col = 0; col < numCols; col++) {
        Array1[row][col] = bit;
        inFile >> bit; //read in next bit
      }
    }

    //read in second input array
    for (int row = 0; row < numRows; row++) {
      for (int col = 0; col < numCols; col++) {
        Array2[row][col] = bit;
        inFile >> bit; //read in next bit
      }
    }
  }
}

void printInputArrays(int& numRows, int& numCols, BitArray Array1, BitArray Array2) {
  int width;
  width = 2*numCols;

  cout << "Initial values of the arrays processed\n";
  cout << string(38, '-') << endl;
  cout << left << setw(width) << "Array 1    " << setw(width) << "Array 2\n";
  cout << setw(width) << string(7, '-') << "    " << setw(width) << string(7, '-') << endl;

  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      cout << Array1[row][col] << ' ';
    }

    cout << "    ";

    for (int col = 0; col < numCols; col++) {
      cout << Array2[row][col] << ' '; //print first array's value
    }

    cout << endl;
  }

  cout << endl;
}

void calcOutputArrays(int& numRows, int& numCols, BitArray Array1, BitArray Array2, BitArray orArray, BitArray andArray, BitArray xorArray) {
  int bitSum;

  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      //initilixe arrays
      orArray[row][col] = 0;
      andArray[row][col] = 0;
      xorArray[row][col] = 0;

      bitSum = Array1[row][col] + Array2[row][col];

      switch (bitSum) {
        case 0:
          orArray[row][col] = 0;
          andArray[row][col] = 0;
          xorArray[row][col] = 0;
          break;
        case 1:
          orArray[row][col] = 1;
          andArray[row][col] = 0;
          xorArray[row][col] = 1;
          break;
        case 2:
          orArray[row][col] = 1;
          andArray[row][col] = 1;
          xorArray[row][col] = 0;
          break;
      }
    }
  }
}

void printOutputArrays(int& numRows, int& numCols, BitArray orArray, BitArray andArray, BitArray xorArray) {
  int width = 2*numCols;

  cout << "OR, AND and XOR results\n";
	cout << string(23, '-') << endl;
	cout << left << setw(width) << "OR" << "    " << setw(width) << "AND" << "    " << setw(width) << "XOR\n";
	cout << setw(width) << "--" << "    " << setw(width) << "---" << "    " << setw(width) << "---\n";

  for (int row = 0; row < numRows; row++) {
    //output or array
    for (int col = 0; col < numCols; col++)
		{
			cout << orArray[row][col] << ' ';
		}

		cout << "    ";

    // output and array
		for (int col = 0; col < numCols; col++)
		{
			cout << andArray[row][col] << ' ';
		}

		cout << "    ";

    // output xor array
		for (int col = 0; col < numCols; col++)
		{
			cout << xorArray[row][col] << ' ';
		}
		cout << endl;
  }

  cout << "\n\n";
}

void printIntegerEquivalents(int& numRows, int& numCols, BitArray orArray, BitArray andArray, BitArray xorArray) {
  int base = 1; //start at 2^0 = 1
  int orResult = 0;
  int andResult = 0;
  int xorResult = 0;

  cout << "Integer Equivalents for the rows" << endl << "of the OR, AND and XOR arrays" << endl;
  cout << string(32, '-') << endl;
	cout << left << setw(8) << "OR" << setw(8) << "AND" << setw(8) << "XOR" << endl;
	cout << setw(8) << "--" << setw(8) << "---" << setw(8) << "---" << endl;

  for (int row = 0; row < numRows; row++) {
    for (int col = numCols - 1; col >= 0; col--) {
      orResult += base*orArray[row][col];
      andResult += base*orArray[row][col];
      xorResult += base*orArray[row][col];
      base *= 2;
    }
    cout << setw(8) << orResult << setw(8) << andResult << setw(8) << xorResult << endl;
  }
}
