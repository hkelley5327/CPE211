// ****************************************
// Program Title: Project 7
// Project File: Project_07.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 10/22/24
// Program description: take a user input in a menu and either
// approimate pi, flip a fair coin, roll a fair die, or exit the program
// ****************************************

#include <iostream>   //for cin, cout, endl
#include <cmath>      //for sqrt(), pow()
#include <iomanip>    //for fixed, setprecision()
#include <cstdlib>    //for rng stuff
#include <string>     //for string()
#include <climits>    //for INT_MAX

using namespace std;

//function prototypes
void printMenu();
void obtainInt(int& selection);
void calcPi();
void coinFlip();
void tossDie();

int main() {

  //variable declarations
  int seed;
  int selection;

  //seed initilization
  cout << "Enter in the seed(integer > 0) for the random number generator: ";
  cin >> seed;
  cout << seed << "\n\n";

  //srand
  srand(seed);

  do {
    printMenu();
    obtainInt(selection);
    switch(selection) {
      case 1:
        calcPi();
        break;
      case 2:
        coinFlip();
        break;
      case 3:
        tossDie();
        break;
      case 4:
        cout << "Exit selected. Exiting the program now...\n\n";
        break;
      default:
        cout << string(15, '*') << " Invalid Integer " << string(15, '*') << "\n\n";
        cout << "==> Invalid integer entered.\n";
        cout << "==> Please try again...\n";
        cout << string(47, '*') << "\n\n";
    }
  }

  //while selection is not exit
  while (selection != 4);

  return 0;
}

void printMenu () {
  int choice;

  cout << string(24, '*') << endl;
  cout << string(5, '*') << " Menu Options " << string(5, '*') << endl;
  cout << string(24, '*') << endl;
  cout << "1) Approximate PI" << endl;
  cout << "2) Flip a fair coin" << endl;
  cout << "3) Toss a fair 5-sided die" << endl;
  cout << "4) Exit" << endl;
  cout << string(24, '*') << "\n\n";

  cout << "Enter your choice: ";
  cin >> choice;
  cout << "\n" << choice;
}

//need to get selection from user and then use it
void obtainInt(int& selection) {
  char invalid;

  cout << "Enter your choice: ";
  cin >> selection;

  //while selection is not an integer aka not valid
  while (cin.fail()) {

    //clear input stream and read in invalid value
    cin.clear();
    cin >> invalid;
    cout << invalid << "\n\n";

    //ignore all other values until a new line
    cin.ignore(INT_MAX, '\n');

    //error message
    cout << string(14, '*') << " Invalid Character " << string(14, '*');
    cout << "==> Invalid character(s) entered.\n";
    cout << "==> Please try again...\n";
    cout << string(47, '*') << "\n\n";

    //back to print menu
    printMenu();
  }

  //ignore all other inputs
  cin.ignore(INT_MAX, '\n');
  cout << selection << "\n\n";
}

//using Monte Carlo method
void calcPi() {

  //varaible declarations
  double x, y;
  int i;
  int insideCircle = 0;
  double approx;

  cout << "Monte Carlo Metho for finding PI has been selected\n\n";

  //get number of iterations
  cout << "Number of iterations: ";
  cin >> i;
  cout << i << "\n\n";

  //for each iteration specified by user
  for (int j = 0; j < i; j++) {

    //get random numbers between 0 and 1
    x = double(rand())/double(RAND_MAX);
    y = double(rand())/double(RAND_MAX);

    //if coordinate is insdie circle
    if (sqrt(pow(x, 2) + pow(y, 2)) <= 1.0)
      //increment inside counter
      insideCircle++;
  }

  //approximate pi
  approx = 4 *(insideCircle / double(i));

  cout << fixed << setprecision(6) << string(10, '*') << " Option 1: Calculating PI " << string(10, '*') << endl;
  cout << "For " << i << " iterations, pi is about " << approx << endl;
  cout << string(46, '8') << "\n\n";
}

void coinFlip() {
  int flips;
  double value;
  int heads = 0;
  double headsPer, tailsPer;

  cout << "Flipping a fair coin has been selected\n\n";

  //get number of flips
  cout << "How mnay flips of the coin? ";
  cin >> flips;
  cout << flips << "\n\n";

  //for each flip
  for (int i = 0; i < flips; i++) {

    //get random number between 0 and 1
    value = double(rand())/double(RAND_MAX);
    if (value > 0.5) {
      //increment heads counter, we only care about heads because we know if it ins't heads it must be tails
      heads++;
    }

    //calculate percentages, must add to 100%
    headsPer = (heads / double(flips)) * 100;
    tailsPer = 100 - headsPer;

    //print values
    cout << fixed << setprecision(4) << string(10, '*') << " Option 2: Flipping a Coin " << string(10, '*') << endl;
    cout << "For " << flips << " flips of a fair coin:\n";
    cout << "Heads percentage: " << headsPer << endl;
    cout << "Tails percentage: " << tailsPer << endl;
    cout << string(47, '*') << "\n\n";
  }
}

void tossDie() {
  int rolls;
  double value;
  int count1, count2, count3, count4, count5;
  double per1, per2, per3, per4, per5;

  cout << "Tosing a fair 5-sided die has been selected\n\n";

  //get number of rolls
  cout << "How many times do you want to roll the die? ";
  cin >> rolls;
  cout << rolls << "\n\n";

  //for each roll
  for (int i = 0; i < rolls; i++) {
    value = double(rand()) / double(RAND_MAX);

    //if value represents side 1
    if (value < 0.2) {
      count1++;
    }
    //else if value represents side 2
    else if (0.2 <= value && value < 0.4) {
      count2++;
    }
    //else if value represents side 3
    else if (0.4 <= value && value < 0.6) {
      count3++;
    }
    else if (0.6 <= value && value < 0.8) {
      count4++;
    }
    else {
      count5++;
    }
  }

  //calculate percents
  per1 = (count1 / double(rolls)) * 100;
  per2 = (count2 / double(rolls)) * 100;
  per3 = (count3 / double(rolls)) * 100;
  per4 = (count4 / double(rolls)) * 100;
  per5 = (count5 / double(rolls)) * 100;

  //print values
  cout << fixed << setprecision(4) << string(10, '*') << " Option 3: Tossing a Die " << string(10, '*') << endl;
  cout << "For " << rolls << " rolls of a fair die:\n";
  cout << "Side 1 percentage: " << per1 << endl;
  cout << "Side 2 percentage: " << per2 << endl;
  cout << "Side 3 percentage: " << per3 << endl;
  cout << "Side 4 percentage: " << per4 << endl;
  cout << "Side 5 percentage: " << per5 << endl;
  cout << string(45, '*') << "\n\n";
}
