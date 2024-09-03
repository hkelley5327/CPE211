// ****************************************
// Program Title: Sample header file
// Project File: Cpp_header.cpp
// Name: Ron Bowman  replace with your name
// Course Section: CPE-211-01  Replace with your course section
// Lab Section: 4  replace with your lab section
// Due Date: 01/19/05  Edit as necessary
// program description: Description of  Edit as necessary
// What the program does.
// ****************************************

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// constant definitions
const double PI = 3.14159265;
const double G = 9.80665;

// initial varibal edefinitions
float timeToMaxHeight = 0;
float timeToMaxDis = 0;
float maxHeight = 0;
float maxDis = 0;
float maxHorRange = 0;
float initialVel = 0;
float startingAngleDeg = 0;
float startingAngleRad = 0;

// start of Program
int main() {
  //set blank character to * instead of space
  cout << setfill('*');

  // projectile motion header set up
  cout << left << setw(30) << endl;
  cout << left << setw(30) << " Projectile Motion" << string(5, '*') << endl;
  cout << left << setw(30) << endl << endl;

  //set blank character back to namespace
  cout << setfill(' ');

  //ask for initial velocity, then print user value
  cout << "Enter in the intial velocity (in meters/sec): ";
  cin >> initialVel;
  cout << initialVel << endl;

  //ask for angle in degrees, then print user value
  cout << "Enter in the starting Angle (in degrees)";
  cin >> startingAngleDeg;
  cout << startingAngleDeg << endl;
  //convert angle from degrees to radians
  startingAngleRad = startingAngleDeg * PI / 180.0;

  //time to reach maximum height calculation
  timeToMaxHeight = (initialVel * sin(startingAngleRad)) / G;

  //time to maximum distance calculation
  timeToMaxDis = (2 * initialVel * sin(startingAngleRad)) / G;

  //maximum height calculation
  maxHeight = (pow(initialVel, 2) * (pow(sin(startingAngleRad), 2)) / (2 * G);

  //maximum distance calculation
  maxDis = initialVel * timeToMaxDis * cos(startingAngleRad);

  //maximum possible horizontal range calculation
  maxHorRange = (pow(initialVel, 2)) / G;
  
  //print out desired calculated numbers
  cout << "Time to max height: /t" << timeToMaxHeight << endl;
  cout << "Time to max distance: /t" << timeToMaxDis << endl;
  cout << "Maximum height: /t" << maxHeight << endl;
  cout << "Maximum distance : /t" << maxDis << endl;
  cout << "Maximum range: /t" << maxHorRange << endl;

  return 0;
}
