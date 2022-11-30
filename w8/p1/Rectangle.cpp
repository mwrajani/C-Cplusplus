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
#include "Rectangle.h"

using namespace std;
namespace sdds {
	Rectangle::Rectangle():LblShape() {
		m_height = 0;
		m_width = 0;
	}
	Rectangle::Rectangle(const char* inStream, int width, int height) : LblShape(inStream) {
		int j = (strlen(label()) + 2);
		if (height < 3 || width < j) {
			m_height = 0;
			m_width = 0;
		}
		else {
			m_height = height;
			m_width = width;
		}
	}
	void Rectangle::getSpecs(istream& istr){
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore();
		istr >> m_height;
		istr.ignore(2000, '\n');
		}
	void Rectangle::draw(ostream& ostr) const {
		int j = ((m_width - 2) - strlen(label()));
		if (m_height!=0 && m_width!=0) {
			ostr << '+';
			for (int i = 0; i < m_width -2; i++)
			{
				ostr << '-';
			}
			ostr << '+'<<endl;
			ostr << '|'<<label();
			for (int i = 0; i < j; i++)
			{
				ostr << ' ';
			}
			ostr << '|' << endl;
			for (int i = 0; i < (m_height - 3); i++)
			{
				ostr << '|';
				for (int i = 0; i < (m_width - 2); i++)
				{
					ostr << ' ';
				}
				ostr << '|'<<endl;
			}
			ostr << '+';
			for (int i = 0; i < m_width - 2; i++)
			{
				ostr << '-';
			}
			ostr << '+';
		}
	}
}
