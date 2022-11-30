#pragma once
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
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Text.h"
using namespace std;
namespace sdds {
	class HtmlText: public Text
	{
		char* m_title = nullptr;
	public:
		HtmlText(const HtmlText& iStat);
		HtmlText& operator=(const HtmlText& iStat);
		HtmlText(const char* title = nullptr);
		~HtmlText();
		std::ostream& write(std::ostream& ostr)const;
	};
}
#endif
