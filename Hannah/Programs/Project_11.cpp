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

int main() {
  ifstream inFile;

  int n;
  int width;

  string inFileName;

  //open input file
  do {
    //ask for and read in input file name
    cout << "\nEnter the name of the input file (ctrl-c to exit): ";
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

  inFile >> n >> width;

  float array[n];

  float floatNum;
  //read in values
  for (int i = 0; i < n; i++) {
    inFile >> floatNum;
    array[i] = floatNum;
  }

  //sort array from low to high
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        float temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }

  double sum = 0;

  //calculate sum of all entries
  for (int i = 0; i < n; i++) {
    sum += array[i];
  }

  //calculate average
  float avg = sum / (float)n;

  float median;
  //calculate median
  if (n % 2 != 0) {
    // If odd, return the middle element
    median = array[n / 2];
  }
  else {
    // If even, return the average of the two middle elements
    median = (array[(n - 1) / 2] + array[n / 2]) / 2.0;
  }

  float varSum = 0;
  //calculate variance
  for (int i = 0; i < n; i++) {
    varSum += pow((array[i] - avg), 2);
  }
  float variance = varSum/(float)n;

  //calculate standard deviation
  float standDev = sqrt(variance);

  //print out calculations
  cout << string(15, '*') << " File Statistics " << string(15, '*') << endl;
  cout << string(47, '*') << endl;
  cout << left << fixed << setfill('.') << setw(width) <<setprecision(3) << "Average" << avg << endl;
  cout << fixed << setfill('.') << setw(width) <<setprecision(3) << "Median" << median << endl;
  cout << fixed << setfill('.') << setw(width) <<setprecision(3) << "Variance" << variance << endl;
  cout << fixed << setfill('.') << setw(width) <<setprecision(3) << "Standard Deviation" << standDev << endl;
  cout << string(47, '*') << endl;

}
