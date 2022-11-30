////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////3 / 31 / 2022
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
///* Citation and Sources...
//Final Project Milestone ?
//Module: Status
//Filename: Status.cpp
//Version 1.0
//Author	Muhammad Wajih
//Revision History
//-----------------------------------------------------------
//Date      Reason
//2020/?/?  Preliminary release
//2020/?/?  Debugged DMA
//-----------------------------------------------------------
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
//-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Text.h"

namespace sdds
{
	Text::Text() {
		m_content = nullptr;
	}
		Text::Text(const Text& hc) {
		if (this != &hc)
		{
			*this = hc;
		}else{
			m_content = nullptr;
		}
	}
		Text& Text::operator=(const Text& hc) {
		if (m_content != nullptr) {
			delete[] m_content;
			m_content = nullptr;
		}
		if ( this != &hc && hc.m_content != nullptr) {
			m_content = new char[strlen(hc.m_content) + 1];
			strcpy(m_content, hc.m_content);
		}
		else {
			m_content = nullptr;
		}
		return *this;
	}
		Text::~Text() {
			delete[] m_content;
			m_content = nullptr;
		}
	std::istream& Text::read(std::istream& istr) {
	int i = 0;
	delete[] m_content;
	m_content = nullptr;
	m_content = new char[getFileLength(istr) + 1];
	while (!istr.eof())
	{
			istr.get(m_content[i]);
			i++;
	}
	m_content[i-1] = '\0';
	if (m_content!= nullptr) {
		istr.clear();
	}
	return istr;
}	
	std::ostream& Text::write(std::ostream& ostr)const{
	if (m_content!= nullptr) {
		ostr << m_content;
	}
	return ostr;
}
		const char& Text::operator[](int index)const{
		return m_content[index];
		}
		int getFileLength(std::istream& is) {
			int len{};
			if (is) {
				// save the current read position
				std::streampos cur = is.tellg();
				// go to the end
				is.seekg(0, ios::end);
				// let what is the positions (end position = size)
				len = is.tellg();
				// now go back to where you were.
				is.seekg(cur);
			}
			return len;
		}
		ostream& operator<<(ostream& ostr, const Text& hc) {
			return hc.write(ostr);
		}
		istream& operator>>(istream& istr, Text& hc) {
			return hc.read(istr);
		}	
}	