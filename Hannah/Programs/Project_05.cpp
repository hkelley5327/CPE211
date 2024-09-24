//include all necessary headers
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  //declare starting variables
  double a, b, c;
  string guess;
  string type;
  double area, perimeter;
  string filename;
  bool triangle;

  //code from Mr. Bowman, testing iostream file input name given?
  if(argc != 2) {
    cout << endl;
    cout << string(9,'*') << " Command Line Argument Error "
    << string(9,'*') << endl;
    cout << "==> Incorrect number of Command Line Arguments!\n";
    cout << "==> Command for running the program is:\n";
    cout << "==> ./Project_05 inputFileName\n";
    cout << string(47,'*') << endl << endl;
    return 1;
  }

  //header print
  cout <<endl << string(60, '*') << endl;
  cout << string(20, '*') << "  Triangle Checker  " << string(20, '*') << endl;
  cout << string(60, '*') << "\n\n";

  //io stream starting conditions
  ifstream inFile;
  string inFileName = argv[1];
  inFile.open(inFileName);

  //tell user which file is being read
  cout << "Opening input file: " << inFileName << "\n\n";

  //io stream test, code from project files
  if(inFile.fail() )
  {
    cout << string(15, '*') << " File Open Error "
    << string(15, '*') << endl;
    cout << "==> Input file failed to open properly!!\n";
    cout << "==> Attempted to open file: " << inFileName << endl;
    cout << "==> Terminating program!!!\n";
    cout << string(47, '*') << "\n\n";
    return 1;
  }

  if(inFile.good()) {
    cout << "Reading Values From Input File..." << "\n\n";
  }

  //reading side lenghts and guess from file
  int count = 0;

  while (count < 4) {
    
    //check for empty flie
    if ((count == 0) && !inFile.eof()) {
      cout << left << string(15, '*') << " Input File is Empty " << string(15, '*') << endl;
      cout << left << "==> No Information in the input file.\n";
      cout << left << "==> Terminating program now...\n";
      cout << left << string(47, '*');
    }

    char label;

    inFile >> label;
    if (label == 'a') {
      inFile >> a;
    }
    else if (label == 'b') {
      inFile >> b;
    }
    else if (label == 'c') {
      inFile >> c;
    }
    else {
      inFile >> guess;
    }



    /*if ((a == 0) && (b == 0) && (c == 0) {
      cout << left << string(15, '*') << " Input File is Empty " << string(15, '*') << endl;
      cout << left << "==> No Information in the input file.\n";
      cout << left << "==> Terminating program now...\n";
      cout << left << string(47, '*');

      return 1;
    }
    */

    if (a == 0) {
      cout << left << setfill(' ') << string(15, '*') << " File Read Error " << string(15, '*') << endl;
      cout << "==> Error reading data from input file.\n";
      cout << "==> Terminating program now...\n";
      cout << string(47, '*') << "\n\n";

      return 1;
    }

    count++;
  }

  //checking for negative input values
  if ((a < 0) || (b < 0) || (c < 0)) {
    cout << left << setfill(' ') << string(15, '*') << " File Data Error " << string(15, '*') << endl;
    cout << "==> Error: One or more side lengths are negative.\n";
    cout << "==> Terminating program now...\n";
    cout << string(47, '*') << "\n\n";

    return 1;
  }

  //checking for a triangle
  if ((a < b + c) && (b < a + c) && (c < a + b)) {
    triangle = true;

    //math using given inputs
    perimeter = a + b + c;
    double s = perimeter / 2;
    area = sqrt(s * (s-a) * (s-b) * (s-c));

    //checking type of triangle
    if ((a==b) && (b==c)) {
      type = "equilateral";
    }
    else if ((a==b) || (b==c) || (a==c)) {
        type = "isosceles";
    }
    else {
      type = "scalene";
    }
  }
  else {
    triangle = false;
    type = "not-triangle";
  }

  //summary of data and results
  cout << "Summary of Data Read...\n";
  cout << fixed << setprecision(2) << "Side A = " << a << endl;
  cout << fixed << setprecision(2) << "Side B = " << b << endl;
  cout << fixed << setprecision(2) << "Side C = " << c << endl;
  cout << "Guess  = " << guess << endl;
  cout << string(60, '*') << endl;
  cout << "Results From Data Read:\n";
  cout << left << setfill('.') << setw(13) << "Type" << type << endl;
  if (triangle) {
    cout << left << setfill('.') << setw(13) << "Area" << fixed << setprecision(2) << area << endl;
    cout << left << setfill('.') << setw(13) << "Perimeter" << fixed << setprecision(2) << perimeter << "\n\n";
  }
  else {
    cout << endl;
  }

  if (guess == type) {
    cout << "Congratulations!  Triangle specified is correct" << endl;
  }
  else {
    cout << "Sorry! Triangle specified is incorrect" << endl;
  }

  cout << string(60, '*') << "\n\n";

  inFile.close(inFileName);

return 0;
}
