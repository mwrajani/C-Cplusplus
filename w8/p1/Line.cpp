//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 24 / 2022
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
#include "Line.h"

using namespace std;
namespace sdds {
	Line::Line():LblShape(){
		m_length = 0;
	}
	Line::Line(const char* inStream, int length):LblShape(inStream){
		m_length = length;
	}
	void Line::getSpecs(istream& istr){
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(2000, '\n');
	}
	void Line::draw(ostream& ostr) const{
		if (label() != nullptr && m_length > 0)
		{
			ostr << label()<<endl;
			for (int i = 0; i < m_length;i++)
			{
				ostr <<'=';
			}
		}
	}
}
