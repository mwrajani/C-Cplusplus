/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/14/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char* () const;
      bool operator ~() const;
      Flight& operator = (Flight& copy);
      Flight& operator = (int copyI);
      Flight& operator = (double copyD);
      Flight& operator += (int copyI);
      Flight& operator += (double copyD);
      Flight& operator -= (int copyI);
      Flight& operator -= (double copyD);
      Flight& operator << (Flight& copy);
      Flight& operator >> (Flight& copied);
      std::ostream& display()const;
   };
   int operator + (Flight& left, Flight& right);
   int operator += (int & left, Flight& right);
}
#endif // SDDS_FLIGHT_H