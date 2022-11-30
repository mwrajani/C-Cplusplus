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
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Shape.h"
using namespace std;
namespace sdds {
	class LblShape : public Shape
	{	
		char* m_label = nullptr;
	protected:
		char* label() const;
	public:
		LblShape();
		void getSpecs(istream& istr);
		LblShape(const char* inStream);
		LblShape(LblShape&) = delete;
		LblShape& operator =(LblShape&) = delete;
		~LblShape();
	};
}
#endif
