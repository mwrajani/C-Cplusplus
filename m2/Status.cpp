//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* Citation and Sources...
Final Project Milestone ?
Module: Status
Filename: Status.cpp
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
#include <cstring>
#include "Status.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	Status::Status(const char* Description) {
		this->code = 0;
		ut.alocpy(this->description, Description);
	}
	Status::~Status() {
		delete[] description;
		description = nullptr;
	}
	Status::Status(const Status& iStat) {
		*this = iStat;
	}
	Status& Status::operator=(const Status& inStat) {
		if (this != &inStat) {
			code = inStat.code;
			ut.alocpy(description, inStat.description);
		}
		return *this;
	}
	Status& Status::operator=(const int Code) {
		this->code = Code;
		return *this;
	}
	Status& Status::operator=(const char* Desc) {
		ut.alocpy(description, Desc);
		return *this;
	}
	Status::operator int() const {
		return code;
	}
	Status::operator const char* () const {
		return description;
	}
	Status::operator bool() const {
		bool ret = false;
		if (description == nullptr) {
			ret = true;
		}
		return ret;
	}
	Status& Status::clear() {
		if (description != nullptr) {
			delete[] description;
			description = nullptr;
		}
		code = 0;
		return *this;
	}
	ostream& operator<<(ostream& ostr, const Status& hc) {
		if (!hc) {
			if ((int)hc != 0) {
				ostr << "ERR#" << (int)hc << ": ";
			}
			ostr << (const char*)hc;
		}
		return ostr;
	}
}
