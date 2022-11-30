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
#pragma once
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "Utils.h"
#include "Status.h"
#include "iProduct.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	class Item: public iProduct {
		double price;
		int quantityAvail;
		int quantityNeed;
		char* descItem;
		bool isLinear;
	protected:
		Status objState;
		int stockNo;
		bool linear() const;
	public:
		Item();
		Item(Item&);
		Item& operator=(Item&);
		~Item();
		int readSku(std::istream& istr);
		int operator-=(int qty);
		int operator+=(int qty);
		operator double()const;
		operator bool()const;
		int qtyNeeded()const;
		int qty()const;
		void clear();
		void linear(bool isLinear);
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
	};
	ostream& operator<<(ostream& ostr, const iProduct& hc);
	istream& operator>>(istream& istr, iProduct& hc);
}
#endif