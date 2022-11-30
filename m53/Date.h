//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* Citation and Sources...
Final Project Milestone ?
Module: Date
Filename: Date.h
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
#pragma once
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Utils.h"
#include "Status.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
using namespace std;
namespace sdds {
	const int maximum_year_value = 2030;
	class Date
	{
		int myear;
		int m_month;
		int mday;
		Status State;
		bool mformatted = true;
	public:
		Date();
		Date(int year, int month, int day);
		~Date();
		bool validate();
		int uniqueDateValue() const;
		bool operator==(const Date& date);
		bool operator!=(const Date& date);
		bool operator>(const Date& date);
		bool operator<(const Date& date);
		bool operator>=(const Date& date);
		bool operator<=(const Date& date);
		Status& state();
		Date& formatted(bool val);
		operator bool() const;
		ostream& write(ostream& ostr)const;
		istream& read(istream& istr);
	};
	istream& operator>>(istream& istr, Date& hc);
	ostream& operator<<(ostream& ostr, const Date& hc);
}
#endif
