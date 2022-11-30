//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 31 / 2022
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
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	class Text
	{
		char* m_content = nullptr;
	protected:
		const char& operator[](int index)const;
	public:
		Text();
		~Text();
		Text(const Text& iStat);
		Text& operator=(const Text& iStat);
		virtual std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
	int getFileLength(std::istream& is);
	ostream& operator<<(ostream& ostr, const Text& hc);
	istream& operator>>(istream& istr, Text& hc);
}
#endif