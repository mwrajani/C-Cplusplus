//#pragma once
//#pragma once
////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////3 / 24 / 2022
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
///* Citation and Sources...
//Final Project Milestone ?
//Module: Status
//Filename: Status.h
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
//#pragma once
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Item.h"
#include "Utils.h"
#include "Date.h"
using namespace std;
namespace sdds {
	class Perishable : public Item
	{
		Date expiryDate;
		char* instructions;
	public:
		Perishable();
		~Perishable();
		Perishable(const Perishable& iStat);
		Perishable& operator=(const Perishable& iStat);
		const Date& expiry() const;
		int readSku(std::istream& istr);
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr) const;
	};
}
#endif

