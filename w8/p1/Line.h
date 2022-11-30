#pragma once
#pragma once
//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 24 / 2022
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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Shape.h"
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Line : public LblShape
	{
		int m_length;
	public:
		Line();
		Line(const char* inStream, int length);
		void getSpecs(istream& istr);
		void draw(ostream& ostr) const;
	};
}
#endif

