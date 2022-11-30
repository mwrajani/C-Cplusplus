//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* Citation and Sources...
Final Project Milestone ?
Module: Date
Filename: Date.cpp
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
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include "Date.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	bool Date::validate() {
		bool ret = false;
		int year;
		int month;
		int day;
		ut.getSystemDate(&year, &month, &day);
		if (this->myear < year || this->myear > maximum_year_value) {
			this->State = "Invalid year in date";
			this->State = 1;
		}
		else if (this->m_month < 1 || this->m_month > 12) {
			this->State = "Invalid month in date";
			this->State = 2;
		}
		else if (this->mday < 1 || this->mday > ut.daysOfMon(this->m_month, this->myear)) {
			this->State = "Invalid day in date";
			this->State = 3;
		}
		else {
			this->State.clear();
			ret = true;
		}
		return ret;
	}
	int Date::uniqueDateValue() const {
		return myear * 372 + m_month * 31 + mday;
	}
	Date::Date() {
		ut.getSystemDate(&myear, &m_month, &mday);
	}
	Date::Date(int year, int month, int day) {
		myear = year;
		m_month = month;
		mday = day;
		this->validate();
	}
	bool Date::operator==(const Date& date) {
		bool ret = false;
		if (this->uniqueDateValue() == date.uniqueDateValue()) {
			ret = true;
		}
		return ret;
	}
	bool Date::operator!=(const Date& date) {
		bool ret = false;
		if (this->uniqueDateValue() != date.uniqueDateValue()) {
			ret = true;
		}
		return ret;
	}
	bool Date::operator>(const Date& date) {
		bool ret = false;
		if (this->uniqueDateValue() > date.uniqueDateValue()) {
			ret = true;
		}
		return ret;
	}
	bool Date::operator<(const Date& date) {
		bool ret = false;
		if (this->uniqueDateValue() < date.uniqueDateValue()) {
			ret = true;
		}
		return ret;
	}
	bool Date::operator>=(const Date& date) {
		bool ret = false;
		if (this->uniqueDateValue() >= date.uniqueDateValue()) {
			ret = true;
		}
		return ret;
	}
	bool Date::operator<=(const Date& date) {
		bool ret = false;
		if (this->uniqueDateValue() <= date.uniqueDateValue()) {
			ret = true;
		}
		return ret;
	}
	const Status& Date::state()const {
		return this->State;
	}
	Date& Date::formatted(bool val) {
		mformatted = val;
		return *this;
	}
	Date::operator bool() const {
		return State;
	}
	ostream& Date::write(ostream& ostr) const {
		if (mformatted) {
			ostr << myear << '/';
			ostr.fill('0');
			ostr.width(2);
			ostr << m_month << '/';
			ostr.fill('0');
			ostr.width(2);
			ostr << mday;
		}
		else {
			ostr << myear - 2000;
			ostr.fill('0');
			ostr.width(2);
			ostr << m_month;
			ostr.fill('0');
			ostr.width(2);
			ostr << mday;
		}
		return ostr;
	}

	int digits(int n) {
		int count = 0;
		while (n != 0) {
			n /= 10;
			count++;
		}
		return count;
	}
	istream& Date::read(istream& istr) {
		int enter = 0;
		int year;
		int month;
		int day;
		ut.getSystemDate(&year, &month, &day);
		int noDigits = 0;
		istr >> enter;
		int div = enter;
		if (istr.good()) {
			while (div >= 1) {
				div /= 10;
				noDigits++;
			}
			if (noDigits == 4) {
				myear = year;
				m_month = enter / 100;
				mday = enter % 100;
			}
			else if (noDigits == 6)
			{
				myear = enter / 10000 + 2000;
				enter %= 10000;
				m_month = enter / 100;
				mday = enter % 100;
			}
			else {
				myear = year;
				m_month = 0;
				mday = 0;
			}
			if (!this->validate()) {
				istr.setstate(std::ios::badbit);
			}
		}
		else {
			cout << "Invalid date value";
		}
		return istr;
	}
	Date::~Date() {}

	ostream& operator<<(ostream& ostr, const Date& date) {
		date.write(ostr);
		return ostr;

	}
	istream& operator>>(istream& istr, Date& date) {
		date.read(istr);
		return istr;
	}
}