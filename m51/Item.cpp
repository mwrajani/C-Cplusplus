//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
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
#include <iomanip>
#include <string>
#include "Item.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	bool Item::linear() const {
		return isLinear;
	}
	Item::Item() {
		price = 0;
		quantityAvail = 0;
		quantityNeed = 0;
		descItem = nullptr;
		isLinear = false;
		objState = nullptr;
		stockNo = 0;

	}
	Item::Item(const Item& hc) {
		price = hc.price;
		quantityAvail = hc.quantityAvail;
		quantityNeed = hc.quantityNeed;
		if (hc.descItem != nullptr)
		{
			descItem = new char[strlen(hc.descItem) + 1];
			strcpy(descItem, hc.descItem);
		}
		else
		{
			descItem = nullptr;
		}
		isLinear = hc.isLinear;
		objState = hc.objState;
		stockNo = hc.stockNo;
	}
	Item::~Item() {
		delete[] descItem;
		descItem = nullptr;
	}
	Item& Item::operator=(const Item& hc) {
		
		if (hc.descItem != nullptr) {


			if (descItem != nullptr) {
				delete[] descItem;
				descItem = nullptr;
			}
			price = hc.price;
			quantityAvail = hc.quantityAvail;
			quantityNeed = hc.quantityNeed;
			descItem = new char[strlen(hc.descItem) + 1];
			strcpy(descItem, hc.descItem);
			isLinear = hc.isLinear;
			objState = hc.objState;
			stockNo = hc.stockNo;
		}
		return *this;
	}
	int Item::readSku(std::istream& istr) {
		cout << "SKU: ";
		istr >> stockNo;
		while (stockNo > 99999 || stockNo < 40000 || istr.fail()) {
			if (istr.fail()) {
				istr.clear();
				istr.ignore(2000, '\n');
				cout << "Invalid Integer, retry: ";
				istr >> stockNo;
			}
			if (stockNo > 99999 || stockNo < 40000)
			{
				cout << "Value out of range [40000<=val<=99999]: ";
				istr >> stockNo;
			}
		}
		return stockNo;
	}
	int Item::operator-=(int qty) {
		quantityAvail -= qty;
		if (quantityAvail < 0) {
			quantityAvail = 0;
		}
		return quantityAvail;
	}
	int Item::operator+=(int qty) {
		quantityAvail += qty;
		return quantityAvail;
	}
	Item::operator double()const {
		return price;
	}
	Item::operator bool()const {
		return objState.operator bool() && price != 0/*(objState) && stockNo != 0*/;
	}
	int Item::qtyNeeded()const {
		return quantityNeed;
	}
	int Item::qty()const {
		return quantityAvail;
	}
	void Item::clear() {
		objState.clear();
	}
	void Item::linear(bool isLinear) {
		this->isLinear = isLinear;
	}
	std::ofstream& Item::save(std::ofstream& ofstr) const{
		if (*this) {
			ofstr << stockNo << '\t' << descItem << '\t' << quantityAvail << '\t' << quantityNeed << '\t' << fixed << setprecision(2) << price;
		}
		return ofstr;
	}
	std::ifstream& Item::load(std::ifstream& ifstr) {
		if (descItem != nullptr)
		{
			delete[] descItem;
			descItem = nullptr;
		}
		price = 0;
		quantityAvail = 0;
		quantityNeed = 0;
		stockNo = 0;
		string description;
		ifstr >> stockNo;
		ifstr.ignore(2000, '\t');
		getline(ifstr, description, '\t');
		descItem = new char[strlen(description.c_str()) + 1];
		strcpy(descItem, description.c_str());
		ifstr >> quantityAvail;
		ifstr.ignore(2000, '\t');
		ifstr >> quantityNeed;
		ifstr.ignore(2000, '\t');
		ifstr >> price;
		ifstr.ignore();
		if (ifstr.bad()) {
			objState = "Input file stream read failed!";
		}
		return ifstr;
	}
	std::ostream& Item::display(std::ostream& ostr)const{
		double j = quantityNeed - quantityAvail;
		j *= price;
		if (*this) {
			if (linear()) {
				ostr.fill(' ');
				if (strlen(descItem) > 35) {
					char descOut[36] = { 0 };
					strncpy(descOut, descItem, 35);
					ostr << setw(5) << left << stockNo << " | " << setw(35) << descOut << " | " << setw(4) << right << quantityAvail << right << " | " << setw(4) << quantityNeed << right << " | " << fixed << setprecision(2) << setw(7) << price << " |";
				}
				else {
					ostr << setw(5) << left << stockNo << " | " << setw(35) << descItem << " | " << setw(4) << right << quantityAvail << right << " | " << setw(4) << quantityNeed << right << " | " << fixed << setprecision(2) << setw(7) << price << " |";
				}
			}
			else {
				ostr << "AMA Item:" << endl << stockNo << ": " << descItem << endl << "Quantity Needed: " << quantityNeed << endl << "Quantity Available: " << quantityAvail << endl << "Unit Price: $" << fixed << setprecision(2) << price << endl << "Needed Purchase Fund: $" << fixed << setprecision(2) << j << endl;
			}
		}
		else {
			ostr << (const char*)objState;
		}
		return ostr;
	}
	std::istream& Item::read(std::istream& istr) {
		if (descItem != nullptr)
		{
			delete[] descItem;
			descItem = nullptr;
		}
		string description;
		cout << "AMA Item:\n";
		cout << "SKU: "<< stockNo<<endl;
		cout << "Description: ";
		istr.ignore(2000, '\n');
		getline(istr, description, '\n');
		descItem = new char[strlen(description.c_str()) + 1];
		strcpy(descItem, description.c_str());
		cout << "Quantity Needed: ";
		istr >> quantityNeed;

		while (quantityNeed < 1 || quantityNeed > 9999 || istr.fail()) {
			if (!istr.fail() && (quantityNeed < 1 || quantityNeed > 9999))
			{
				cout << "Value out of range [1<=val<=9999]: ";
				istr >> quantityNeed;
			}
			if (istr.fail()) {
				istr.clear();
				istr.ignore(2000, '\n');
				cout << "Invalid Integer, retry: ";
				istr >> quantityNeed;
			}
		}
		cout << "Quantity On Hand: ";
		istr >> quantityAvail;
		while (quantityAvail < 0 || quantityAvail > quantityNeed || istr.fail()) {
			if (quantityAvail < 0 || quantityAvail > quantityNeed)
			{
				cout << "Value out of range [0<=val<=" << quantityNeed << "]: ";
				istr >> quantityAvail;
			}
			if (istr.fail()) {
				istr.clear();
				istr.ignore(2000, '\n');
				cout << "Invalid Integer, retry: ";
				istr >> quantityAvail;
			}
		}
		istr.ignore(2000, '\n');
		cout << "Unit Price: $";
		istr >> price;
		while (price < 0 || price > 9999 || istr.fail()) {
			if (price < 0 || price > 9999)
			{
				cout << "Value out of range [0.00<=val<=9999.00]: ";
				istr >> price;
			}
			if (istr.fail()) {
				istr.clear();
				istr.ignore(2000, '\n');
				cout << "Invalid number, retry: ";
				istr >> price;
			}
		}
		if (istr.fail()) {
			objState = "Console entry failed!";
		}
		return istr;
	}
	bool Item::operator==(int sku)const {
		return stockNo == sku;
	}
	bool Item::operator==(const char* description)const {
		return ((strstr(descItem, description) != NULL) ? true : false);
	}
}
