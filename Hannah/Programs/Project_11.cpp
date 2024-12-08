// ****************************************
// Program Title: Project 11
// Project File: Project_11.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 12/08/24
// Program description: statistics calcs using
// an array
// ****************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

void opneInputFile(ifstream&);

int main() {
  ifstream inFile;

  int numEntries;
  int width;

  openInputFile(inFile);

  inFile >> numEntries >> width;

  float array[numEntries] = {};

  //read in values
  for (int i = 0; i < numEntries; i++) {
    inFile >> floatNum;
    array[i] = floatNum;
  }

  //sort array from low to high
  sort(array, numEntries);

  float sum = 0;

  //calculate sum of all entries
  for (int i : array) {
    sum += array[i];
  }

  //calculate average
  float avg = sum / (float)numEntries;

  float median;
  //calculate median
  if (n % 2 != 0) {
    // If odd, return the middle element
    median = arr[n / 2];
  }
  else {
    // If even, return the average of the two middle elements
    median = (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
  }

  int varSum = 0
  //calculate variance
  for (int i : array) {
    varSum += pow((arr[i] - avg), 2);
  }
  float variance = varSum/(float)numEntries;

  //calculate standard deviation
  float standDev = sqrt(variance);

  //print out calculations
  cout << string(15, '*') << " File Statistics " << string(15, '*') << endl;
  cout << string(47, '*') << endl;
  cout << fixed << setfill('.') << setw(width) <<setprecision(3) << "Average" << avg << endl;
  cout << fixed << setfill('.') << setw(width) <<setprecision(3) << "Median" << median << endl;
  cout << fixed << setfill('.') << setw(width) <<setprecision(3) << "Variance" << variance << endl;
  cout << fixed << setfill('.') << setw(width) <<setprecision(3) << "Standard Deviation" << standDev << endl;
  cout << string(47, '*') << endl;

}

//copy paste from previous project. should work fine
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
