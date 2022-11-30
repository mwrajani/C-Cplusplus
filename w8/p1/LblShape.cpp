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
#include <string>
#include "LblShape.h"

using namespace std;
namespace sdds {
	char *LblShape::label() const {
		return m_label;
	}
	LblShape::LblShape(){
		m_label = nullptr;
	}
	void LblShape::getSpecs(istream& istr){
		string enter;
		getline(istr, enter, ',');
		istr.clear();
		if (m_label != nullptr) {
			delete[] m_label;
			m_label = nullptr;
		}
		m_label=new char[strlen(enter.c_str())+ 1];
		strcpy(m_label, enter.c_str());
	}
	LblShape::LblShape(const char* inStream){
		if (inStream != nullptr) {
			if (m_label != nullptr) {
				delete[] m_label;
				m_label = nullptr;
			}
			m_label = new char[strlen(inStream) + 1];
			strcpy(m_label,inStream);
		}
		else {
			m_label = nullptr;
		}
	}
	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}
}
