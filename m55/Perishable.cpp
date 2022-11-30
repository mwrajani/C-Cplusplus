////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////3 / 21 / 2022
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 //Citation and Sources...
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
#include <iomanip>
#include <string>
#include "Item.h"
#include "Utils.h"
#include "Date.h"
#include "Perishable.h"

using namespace std;
namespace sdds {
	Perishable::Perishable():Item(),expiryDate(){
		instructions = nullptr;
	}
	Perishable::~Perishable(){
		delete[] instructions;
	}
	Perishable::Perishable(const Perishable& iStat) :Item(iStat)
	{
		*this = iStat;
	}
	Perishable& Perishable::operator=(const Perishable& iStat){
		
		(Item&)*this = iStat;
		if (iStat.instructions != nullptr)
		{
			instructions = new char[strlen(iStat.instructions) + 1];
			strcpy(instructions, iStat.instructions);
		}
		else
		{
			instructions = nullptr;
		}
		expiryDate = iStat.expiryDate;
		return *this;
	}
	const Date& Perishable::expiry() const{
		return this->expiryDate;
	}
	int Perishable::readSku(std::istream& istr){
		cout << "SKU: ";
		istr >> stockNo;
		while (stockNo > 39999 || stockNo < 10000 || istr.fail()) {
			if (istr.fail()) {
				istr.clear();
				istr.ignore(2000, '\n');
				cout << "Invalid Integer, retry: ";
				istr >> stockNo;
			}
			if (stockNo > 39999 || stockNo < 10000)
			{
				cout << "Value out of range [10000<=val<=39999]: ";
				istr >> stockNo;
			}
		}
		return stockNo;
	}
	std::ifstream& Perishable::load(std::ifstream& ifstr) {
		Item::load(ifstr);
		if (instructions != nullptr) {
			delete[] instructions;
		}
		string Instructions;
		getline(ifstr, Instructions, '\t');
		if (Instructions[0] != '\0')
		{
			instructions = new char[strlen(Instructions.c_str()) + 1];
			strcpy(instructions, Instructions.c_str());
		}
		else
		{
			instructions = nullptr;
		}

		expiryDate.read(ifstr);
		if (ifstr.bad()) {
			objState = "Input file stream read failed!";
		}
		ifstr.ignore(2000, '\n');
		return ifstr;
	}
	std::ostream& Perishable::display(std::ostream& ostr) const{
		if (Item::operator bool()) {
		
			if (this->linear() == true) {
				Item::display(ostr);
				if (instructions != nullptr)
				{
					ostr << '*';
				}
				else {
					ostr << ' ';
				}
				ostr << expiryDate;
			}
			else {
				ostr << "Perishable ";
				Item::display(ostr); 
				ostr << "Expiry date: ";
				ostr << expiryDate;
				if (instructions != nullptr)
				{
					ostr << "\nHandling Instructions: ";
					ostr << instructions;
				}
				ostr << '\n';
			}
		}

		return ostr;
	}
	std::istream& Perishable::read(std::istream& istr){
		Item::read(istr);
		delete[] instructions;
		instructions = nullptr;
		cout << "Expiry date (YYMMDD): ";
		expiryDate.read(istr);
		istr.ignore(2000, '\n');
		cout<< "Handling Instructions, ENTER to skip: ";
		if (istr.peek() != '\n') {
			string Instructions;
			getline(istr, Instructions, '\n');
			instructions = new char[strlen(Instructions.c_str()) + 1];
			strcpy(instructions, Instructions.c_str());
		}
		else {
			cout << '\n';
			instructions = nullptr;
		}
		if (istr.fail()) {
				objState = "Perishable console date entry failed!";
			}
			return istr;
	}
	std::ofstream& Perishable::save(std::ofstream& ofstr) const{
		if (Item::operator bool())
		{
			Item::save(ofstr);
			ofstr << '\t';
			if (instructions != nullptr)
			{
				ofstr << instructions;
			}
			ofstr << '\t';
			Date newDate = expiryDate;
			newDate.formatted(false);

			ofstr << newDate;
		}
		ofstr << '\n';
		return ofstr;
	}
}

