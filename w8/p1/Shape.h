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
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	class Shape	
	{
		
	public:
	virtual void draw(ostream& ostr) const = 0;
	virtual void getSpecs(istream& istr) = 0;
	virtual ~Shape(){}
	};
	ostream& operator<<(ostream& ostr,const Shape& hc);
	istream& operator>>(istream& istr, Shape& hc);
}
#endif
