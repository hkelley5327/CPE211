// ****************************************
// Program Title: Project 4
// Project File: Project_04.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 9/20/24
// Program description: given 4 string inputs,
// the program will output a password
// ****************************************

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  //variable definitions
  string name = "";
  string word1 = "";
  string word2 = "";
  string word3 = "";
  const string SPECIAL_CHAR_LIST = "!@#$%^&*(){}[]?";

  //password gen header
  cout << setw(60) << left << string(60, '*') << endl;
  cout << setw(40) << right << "Password Generator" << endl;
  cout << setw(60) << left << string(60, '*') << endl;

  //get name from user and echo print
  cout << "Enter user's first and last names separated by a space: ";
  getline(cin, name, '\n');
  cout << "\nname = " << name << "\n\n" ;
  int lenName = name.length();

  //get first word from user and echo print
  cout << "Enter the first word: ";
  getline(cin, word1, '\n');
  cout << "\nfirst word = " << word1 << "\n\n";
  int len1 = word1.length();

  //get second word from user and echo print
  cout << "Enter the second word: ";
  getline(cin, word2, '\n');
  cout << "\nsecond word = " << word2 << "\n\n";
  int len2 = word2.length();

  //get third word from user and echo print
  cout << "Enter the third word: ";
  getline(cin, word3, '\n');
  cout << "\nthird word = " << word3 << "\n\n";
  int len3 = word3.length();

  cout << setw(60) << string(60, '*') << endl;

  //end of user input section
  //----------------------------------------------------

  //word length table
  cout << left << setw(8) << "Word#" << setw(10) << "Length" << "Word" << endl;
  cout << left << setw(8) << string(5, '-') << setw(10) << string(6, '-') << string(4, '-') << endl;
  cout << left << setw(8) << "1" << setw(10) << len1 << word1 << endl;
  cout << left << setw(8) << "2" << setw(10) << len2 << word2 << endl;
  cout << left << setw(8) << "3" << setw(10) << len3 << word3 << endl;
  cout << left << setw(8) << string(5, '-') << setw(10) << string(6, '-') << string(4, '-') << endl << endl;

  float avg = ((float)len1 + (float)len2 + (float)len3) / 3;
  cout << fixed << setprecision(2) << "Average word length = " << avg << endl;

  //end of word table section
  //-----------------------------------------------

  //password generation section
  cout << "password = ";

  //uisng name variable
  cout << name.at(0) << name.at(name.find(" ") +1) << lenName;

  if (lenName > 14) {
    lenName -= 15;
  }

  cout << SPECIAL_CHAR_LIST.at(lenName);

  //using word1 variable
  cout << word1.at(0) << word1.at(len1 -1) << len1;

  if (len1 > 14) {
    len1 -= 15;
  }

  cout << SPECIAL_CHAR_LIST.at(len1);

  //using word 2 variable
  cout << word2.at(0) << word2.at(len2 -1) << len2;

  if (len2 > 14) {
    len2 -= 15;
  }

  cout << SPECIAL_CHAR_LIST.at(lenName);

  //using word3 variable
  cout << word3.at(0) << word3.at(len3 -1) << len3;

  if (len3 > 14) {
    len3 -= 15;
  }

  cout << SPECIAL_CHAR_LIST.at(len3);


  cout << endl << setw(60) << string(60, '*') << endl;

  //end of program

  return 0;
}
