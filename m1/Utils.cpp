//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 20 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

/* Citation and Sources...
Final Project Milestone ?
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Muhammad Wajih
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"
#include <string>
using namespace std;
namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if(day) *day = sdds_testDay;
         if(mon) *mon = sdds_testMon;
         if(year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13)-1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }
   void Utils::alocpy(char*& destination, const char* source) {
       int ii = 0;
       delete[] destination;
       destination = nullptr;
       if (source != nullptr) {
           ii = strlen(source)+1;
           destination = new char[ii];
           strcpy(destination,source);
       }
   }  
   int Utils::getint(const char* prompt) {
       int enter;
       if (prompt != nullptr) {
           cout << prompt;
       }
       cin >> enter;
           while (!enter) {
               cout << "Invalid Integer, retry: ";
               cin >> enter;
           }
       return enter;
   }
   int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
       int enter = getint(prompt);
       while (enter > max || enter < min) {
           if (errMes != nullptr) {
               cout << errMes << ", retry: ";
           }
           else {
               cout <<"Value out of range ["<<min<<"<=val<="<< max<<"]: ";
           }
           //int enter = getint(prompt);
       }
       return enter;
   }
}