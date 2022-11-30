//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 20 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* Citation and Sources...
Final Project Milestone ?
Module: Status
Filename: Status.h
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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	class Status
	{
		char* description = nullptr;
		int code;
	public:
		Status(const char* = nullptr);
		Status(const Status& iStat);
		Status& operator=(const Status&);
		Status& operator=(const char* Desc);
		Status& operator=(const int code);
		operator int () const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
		~Status();
	};
	ostream& operator<<(ostream& ostr, const Status& hc);
}
#endif