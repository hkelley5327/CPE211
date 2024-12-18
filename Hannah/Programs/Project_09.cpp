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
  		cout << string(47, '*') << "\n";
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
	width = 2*numCols;  // establish width for header as two times the number of columns

	cout << "Initial values of the arrays processed" << endl;
	cout << string(38, '-') << endl;
	cout << left << setw(width) << "Array 1" << "    " << "Array 2" << endl;
	cout << setw(width) << string(7, '-') << "    " << string(7, '-') << endl;

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++)	{
			cout << Array1[row][col] << ' ';
		}  // output first input array

		cout << "    ";

		for (int col = 0; col < numCols; col++) {
			cout << Array2[row][col] << ' ';
		}  // output second input array

		cout << endl;
	}

	cout << endl;
}

void calcOutputArrays(int& numRows, int& numCols, BitArray Array1, BitArray Array2, BitArray orArray, BitArray andArray, BitArray xorArray) {
  int bitSum;

  for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++)	{
			orArray[row][col] = 0;
			andArray[row][col] = 0;
			xorArray[row][col] = 0;  // initialize entries

			bitSum = Array1[row][col] + Array2[row][col];  // sum of corresponding bit in each input array

			switch (bitSum)
			{
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
      }
    }
  }
}

void printOutputArrays(int& numRows, int& numCols, BitArray orArray, BitArray andArray, BitArray xorArray) {
  int width;
	width = 2*numCols;

	cout << "OR, AND and XOR results" << endl;
	cout << string(23, '-') << endl;
	cout << left << setw(width) << "OR" << "    " << setw(width) << "AND" << "    " << "XOR" << endl;
	cout << setw(width) << "--" << "    " << setw(width) << "---" << "    " << "---" << endl;

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			cout << orArray[row][col] << ' ';
		}  // output or array
		cout << "    ";

		for (int col = 0; col < numCols; col++) {
			cout << andArray[row][col] << ' ';
		}  // output and array

		cout << "    ";

		for (int col = 0; col < numCols; col++)	{
			cout << xorArray[row][col] << ' ';
		}  // output xor array

		cout << endl;
	}

	cout << "\n\n";
}

void printIntegerEquivalents(int& numRows, int& numCols, BitArray orArray, BitArray andArray, BitArray xorArray) {
  int base;
	int orResult;
	int andResult;
	int xorResult;  // declare variables for decimal equivalents

	cout << "Integer Equivalents for the rows" << endl << "of the OR, AND and XOR arrays" << endl;
	cout << string(32, '-') << endl;
	cout << left << setw(8) << "OR" << setw(8) << "AND" << "XOR" << endl;
	cout << left << setw(8) << "--" << setw(8) << "---" << "---" << endl;

	for (int row = 0; row < numRows; row++)
	{
		base = 1;  // 2^0 = 1
		orResult = 0;
		andResult = 0;
		xorResult = 0;  // initialize variables

		for (int col = numCols - 1; col >= 0; col--)
		{
			orResult += base*orArray[row][col];
			andResult += base*andArray[row][col];
			xorResult += base*xorArray[row][col];
			base *= 2;
		}  // convert rows from decimal to binary
		cout << setw(8) << orResult << setw(8) << andResult << xorResult << endl;
  }
}
