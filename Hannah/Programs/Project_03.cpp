// ****************************************
// Program Title: Project 3
// Project File: Project_03.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 09/13/24
// Program description: calculate several projectile motion
// formulas using given inputs
// ****************************************

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// constant definitions
const double PI = 3.14159265;
const double G = 9.80665;

// start of Program
int main() {
  // initial varibal edefinitions
  float timeToMaxHeight = 0;
  float timeToMaxDis = 0;
  float maxHeight = 0;
  float maxDis = 0;
  float maxHorRange = 0;
  float initialVel = 0;
  float startingAngleDeg = 0;
  float startingAngleRad = 0;
  //set blank character to * instead of space
  cout << setfill('*');

  // projectile motion header set up
  cout << left << string(30, '*') << endl;
  cout << left << setw(30) << "*****Projectile Motion" << endl;
  cout << left << string(30, '*') << endl << endl;

  //set blank character back to namespace
  cout << setfill(' ');

  //ask for initial velocity, then print user value
  cout << "Enter in the intial velocity (in meters/sec): ";
  cin >> initialVel;
  cout << initialVel << endl << endl;

  //ask for angle in degrees, then print user value
  cout << "Enter in the starting Angle (in degrees): ";
  cin >> startingAngleDeg;
  cout << startingAngleDeg << endl << endl;
  //convert angle from degrees to radians
  startingAngleRad = startingAngleDeg * PI / 180.0;

  //time to reach maximum height calculation
  timeToMaxHeight = (initialVel * sin(startingAngleRad)) / G;

  //time to maximum distance calculation
  timeToMaxDis = (2 * initialVel * sin(startingAngleRad)) / G;

  //maximum height calculation
  maxHeight = (pow(initialVel, 2) * (pow(sin(startingAngleRad), 2)) / (2 * G));

  //maximum distance calculation
  maxDis = initialVel * timeToMaxDis * cos(startingAngleRad);

  //maximum possible horizontal range calculation
  maxHorRange = (pow(initialVel, 2)) / G;

  //print out desired calculated numbers
  cout << setw(25) << "Time to max height: " << setw(7) << fixed << setprecision(3) << timeToMaxHeight << "seconds" << endl;
  cout << setw(25) << "Time to max distance: " << setw(7) << fixed << setprecision(3) << timeToMaxDis << "seconds"<< endl;
  cout << setw(25) << "Maximum height: " << setw(8) << maxHeight << "meters"<< endl;
  cout << setw(25) << "Maximum distance : " << setw(8) << maxDis << " meters"<< endl;
  cout << setw(25) << "Maximum range: " << setw(8) << maxHorRange << " meters"<< endl;

  return 0;
}
