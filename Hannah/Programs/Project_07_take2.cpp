// ****************************************
// Program Title: Project 7
// Project File: Project_07.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 10/22/24
// Program description: take a user input in a menu and either
// approimates pi, flip a fair coin, roll a fair die, or exit the program
// ****************************************

//include necessary headers
#include <iostream>
#include <string>
#include <cstdlib>  // srand, rand, RAND_MAX
#include <climits> // INT_MAX
#include <iomanip> // setprecision
#include <cmath> // sqrt, pow

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

	//get and use seed for rng
	cout << "\nEnter in the seed(integer > 0) for the random number generator: ";
	cin >> seed;
	cout << seed << "\n\n";
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
				cout << "Exit selected.  Exiting the program now..." << "\n\n";
				break;
			default:  //integer not 1-4
				cout << string(15, '*') << " Invalid Integer " << string(15, '*') << endl;
				cout << "==> Invalid integer entered.\n";
				cout << "==> Please try again...\n";
				cout << string(47, '*') << "\n\n";
		}
	}
	while (selection!= 4);  //while selection is not exit

	return 0;
}

void printMenu() {
	cout << string(24, '*') << endl;
	cout << string(5, '*') << " Menu Options " << string(5, '*') << endl;
	cout << string(24, '*') << endl;
	cout << "1) Approximate PI" << endl;
	cout << "2) Flip a fair coin" << endl;
	cout << "3) Toss a fair 5-sided die" << endl;
	cout << "4) Exit" << endl;
	cout << string(24, '*') << endl << endl;
}

//need selection from user, then use/process it
void obtainInt(int& selection) {
	char invalidSel;

	cout << "Enter your choice: ";
	cin >> selection;

	//if selection is not an int, aka cin enters fail state
	while (cin.fail()) {

		//clear cin, especially errors and flags
		cin.clear();

		//read in the invalid selection for later use
		cin >> invalidSel;
		cout << invalidSel << "\n\n";

		//ignore all other inputs until new line
		cin.ignore(INT_MAX, '\n');

		//error message
		cout << string(14, '*') << " Invalid Character " << string(14, '*') << endl;
		cout << "==> Invalid character(s) entered.\n";
		cout << "==> Please try again...\n";
		cout << string(47, '*') << "\n\n";

		//print menu and try again
		printMenu();
		cout << "Enter your choice: ";
		cin >> selection;
	}

	//ignore all other inputs until new line
	cin.ignore(INT_MAX, '\n');

	//get selection
	cout << selection << "\n\n";
}

//uisng Monte Carlo method
void calculatePi()
{
	//varibale declarations
	double x, y;
	int iterations;
	int insideCircle;
	double approx;

	count_inside = 0;  // initialize counter to zero

	cout << "Monte Carlo Method for finding PI has been selected\n\n";

	//get number of iterations
	cout << "Number of iterations: ";
	cin >> iterations;
	cout << iterations << "\n\n";

	//for each iteration, find coordinates and test if inside circle
	for (int i = 0; i < iterations; i++) {
		//get random coordinate between 0 and 1
		x = double(rand())/double(RAND_MAX);
		y = double(rand())/double(RAND_MAX);

		//if coordinate is inside circle, increment counter
		if (sqrt(pow(x, 2) + pow(y, 2)) <= 1.0) {
			insideCircle++;
		}
	}

	//approximate pi
	pi_approx = 4 * (insideCircle / double(iterations));

	cout << fixed << setprecision(6) << string(10, '*') << " Option 1: Calculating PI " << string(10, '*') << endl;
	cout << "For " << iterations << " iterations, pi is about " << approx << endl;
	cout << string(46, '*') << "\n\n";
}

void coinFlip()
{
	int flips;
	double value;
	int heads = 0;
	double headsPer, tailsPer;

	cout << "Flipping of a fair coin has been selected\n\n";

	cout << "How many flips of the coin? ";
	cin >> flips;
	cout << flips << "\n\n";

	// for each coin flip
	for (int i = 0; i < flips; i++) {
		//random number between 0 and 1
		value = double(rand())/double(RAND_MAX);

		//if random number greater than 0.5, add one to head count
		if (value > 0.5) {
			heads++;
		}
	}

	//calculate percentages, should add to 100
	heads_perc = (heads / double(flips)) * 100;
	tails_perc = 100 - heads_perc;

	cout << fixed << setprecision(4);
	cout << string(10, '*') << " Option 2: Flipping a Coin " << string(10, '*') << endl;
	cout << "For " << flips << " flips of a fair coin:" << endl;
	cout << "Heads percentage: " << headsPer << endl;
	cout << "Tails percentage: " << tailPer_perc << endl;
	cout << string(47, '*') << "\n\n";
}

void dieToss()
{
	int rolls;
	double roll_value;  // random num from 0 to 1 representing dice roll
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;  // declare and initialize counters to 0
	double percent1;
	double percent2;
	double percent3;
	double percent4;
	double percent5;

	cout << "Tossing of a fair 5-sided die has been selected" << endl << endl;

	cout << "How many times do you want to roll the die? ";
	cin >> rolls;
	cout << rolls << endl << endl;

	for (int i = 0; i < rolls; i++) {  // for each dice roll
		roll_value = double(rand())/double(RAND_MAX);  // random num from 0 to 1
		if (roll_value < 0.2)  // values representing side 1
			count1++;
		else if (0.2 <= roll_value && roll_value < 0.4)  // values representing side 2
			count2++;
		else if (0.4 <= roll_value && roll_value < 0.6)  // values representing side 3
			count3++;
		else if (0.6 <= roll_value && roll_value < 0.8)  // values representing side 4
			count4++;
		else  // else, side 5 came up
			count5++;  // add one to corresponding counter variable
	}

	percent1 = count1 / double(rolls) * 100;
	percent2 = count2 / double(rolls) * 100;
	percent3 = count3 / double(rolls) * 100;
	percent4 = count4 / double(rolls) * 100;
	percent5 = count5 / double(rolls) * 100;  // calculate percentages using floating point division

	cout << fixed << setprecision(4);
	cout << string(10, '*') << " Option 3: Tossing a Die " << string(10, '*') << endl;
	cout << "For " << rolls << " rolls of a fair die:" << endl;
	cout << "Side 1 percentage: " << percent1 << endl;
	cout << "Side 2 percentage: " << percent2 << endl;
	cout << "Side 3 percentage: " << percent3 << endl;
	cout << "Side 4 percentage: " << percent4 << endl;
	cout << "Side 5 percentage: " << percent5 << endl;
	cout << string(45, '*') << endl << endl;
}
