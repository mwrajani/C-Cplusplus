/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------
Name: Muhammad Wajih Rajani
email : mwrajani@myseneca.ca
Student id : 142199207
Date : 2 / 19 / 2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
using namespace std;
namespace sdds {

	class Portfolio
	{
		double m_value = 0;
		char m_stock[16];
		char m_type;
	public:
		Portfolio();
		Portfolio(double value, const char* stock, char type);
		~Portfolio();
		void emptyPortfolio();
		void dispPortfolio() const;
		operator double() const;
		operator const char*() const;
		operator char() const;
		operator bool() const;
		bool operator~() const;
		Portfolio& operator+=(double add);
		Portfolio& operator-=(double sub);
		void operator<<(Portfolio& movFrom);
		void operator>>(Portfolio& movTo);
		ostream& display() const;
		};
    double operator + (Portfolio& left, Portfolio& right);
	double operator += (double& left, Portfolio& right);
}
#endif // SDDS_Portfolio_H_