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
#include <string.h>
#include "HtmlText.h"

namespace sdds
{
	HtmlText::HtmlText(const char* title) {
				if (title != nullptr) {
					m_title = new char[strlen(title)+1];
					strcpy(m_title,title);
				}
				else {
					m_title = nullptr;
				}
			}
		HtmlText::HtmlText(const HtmlText& iStat): Text(iStat){
		if (this != &iStat)
		{
			*this = iStat;
		}
		else {
			m_title = nullptr;
		}
	}
	HtmlText& HtmlText::operator=(const HtmlText& iStat){
		if (m_title != nullptr) {
			delete[] m_title;
			m_title = nullptr;
		}
			(Text&)*this = iStat;
			m_title = new char[strlen(iStat.m_title) + 1];
			strcpy(m_title, iStat.m_title);
		return *this;
	}
		HtmlText::~HtmlText(){
		delete[] m_title;
		m_title = nullptr;
	}
	std::ostream& HtmlText::write(std::ostream& ostr)const{
		bool ms = false;
		int i = 0;
		ostr << "<html><head><title>";
		if (m_title != nullptr) {
			ostr << m_title;
		}
		else {
			ostr << "No Title";
		}
		ostr << "</title></head>\n<body>\n";
		if (m_title != nullptr) {
			ostr << "<h1>" << m_title << "</h1>\n";
		}
		while ((*this)[i] != '\0')
		{
			if ((*this)[i] == ' ') {
				if (ms)
				{
					ostr << "&nbsp;";
				}
				else {
					ms = true;
					ostr << ' ';
				}
			}
			else if ((*this)[i] == '<') {
					ostr << "&lt;";
					ms = false;
			}
			else if ((*this)[i] == '>') {
				ostr << "&gt;";
				ms = false;
			}
			else if ((*this)[i] == '\n') {
				ostr << "<br />\n";
				ms = false;
			}
			else {
				ms = false;
				ostr << (*this)[i];
			}
			i++;
		}
		ostr << "</body>\n</html>";
		return ostr;
	}
}
