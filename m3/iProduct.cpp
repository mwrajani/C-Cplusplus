//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
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
#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include "iProduct.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds{
	ostream& operator<<(ostream& ostr, const iProduct& hc) {
		return hc.display(ostr);
	}
	istream& operator>>(istream& istr, iProduct& hc){
		return hc.read(istr);
	}
}