// ****************************************
// Program Title: Project 10
// Project File: Project_10.cpp
// Name: Hannah Kelley
// Course Section: CPE-211-02
// Lab Section: 3
// Due Date: 12/05/24
// Program description: constructors, transformers,
// and observers for a date class
// ****************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Project_10.h"

using namespace std;

// CONSTRUCTORS ----------------------------------------------------------------
//default constructor (12 Dec 2020)
Date::Date() {
  month = 12;
  day = 12;
  year = 2020;
}

//parameterized CONSTRUCTORS
Date::Date(int initMonth, int initDay, int initYear) {
  month = initMonth;
  day = initDay;
  year = initYear;
}

Date::Date(int initMonth, int initYear) {
  month = initMonth;
  day = 1;
  year = initYear;
}

Date::Date(int initYear) {
  month = 1;
  day = 1;
  year = initYear;
}

// TRANSFORMERS ----------------------------------------------------------------
void Date::SetDate(int m, int d, int y) {
  month = m;
  day = d;
  year = y;
}

void Date::IncrementDateDay() {
  day++;

  //check for more days than possible in a month
  if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7
    || month == 8 || month ==10 || month == 12)) {
    day = 1;
    month++;
  }
  else if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
    day = 1;
    month++;
  }
  else if (day > 28 && month == 2) {
    day = 1;
    month++;
  }

  //check for more months than possible in ayear
  if (month > 12) {
    month = 1;
    year++;
  }
}

void Date::IncrementDateMonth() {
  month++;

  //check for more months than possible in ayear
  if (month > 12) {
    month = 1;
    year++;
  }
}

void Date::IncrementDateYear() {
  year++;
}

void Date::IncrementDateDays(int days) {
  day += days;

  while (day > 0) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
      if (day > 30) {
        day -= 30;
        days -= 30;
        month++;
      }
      else {
        days = 0;
      }
    }
    else if (month == 2) {
      if (day > 28) {
        day -= 28;
        days -= 28;
        month++;
      }
      else {
        days = 0;
      }
    }
    else {
      if (day > 31) {
        day -= 31;
        days -= 31;
        month++;
      }
      else {
        days = 0;
      }
    }
    if (month > 12) {
      month = 1;
      year++;
    }
  }
}

// OBSERVERS -------------------------------------------------------------------
// mm/dd/yyyy format
void Date::WriteNumberFormat() const {
  cout << setfill('0') << right << setw(2) << month << '/' << setw(2)
    << day << '/' << setw(4) << year;
  cout << setfill(' ') << endl;
}

// month day, year format
void Date::WriteNameFormat() const {
  switch(month) {
    case 1:
      cout << "January ";
      break;
    case 2:
      cout << "February ";
      break;
    case 3:
      cout << "March ";
      break;
    case 4:
      cout << "April ";
      break;
    case 5:
      cout << "May ";
      break;
    case 6:
      cout << "June ";
      break;
    case 7:
      cout << "July ";
      break;
    case 8:
      cout << "August ";
      break;
    case 9:
      cout << "September ";
      break;
    case 10:
      cout << "October ";
      break;
    case 11:
      cout << "November ";
      break;
    case 12:
      cout << "December ";
  }
  cout << day << ", " << year << endl;
}
