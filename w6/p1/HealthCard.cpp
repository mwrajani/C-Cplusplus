//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 10 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HealthCard.h"
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		bool ret = name != nullptr && name != NULL && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9;
		return ret;
	} 
	void HealthCard::setEmpty() {
		this->m_name = nullptr;
		this->m_number = 0;
		this->m_vCode[0] = {0};
		this->m_sNumber[0] = { 0 };
	}
	void HealthCard::allocateAndCopy(const char* name) {
		delete[] this->m_name;
		setEmpty();
		this->m_name = new char[strlen(name)+1];
		strcpy(this->m_name, name);
	}
	void HealthCard::extractChar(istream& istr, char ch) const {
		if (istr.peek() == ch) {
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}
	ostream& HealthCard::printIDInfo(ostream& ostr)const {
		ostr << this->m_number << '-' << this->m_vCode << ", " << this->m_sNumber;
		return ostr;
	}
	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (this->validID(name, number, vCode, sNumber)) {
			allocateAndCopy(name);
			this->m_number = number;
			strcpy(this->m_vCode, vCode);
			strcpy(this->m_sNumber, sNumber);
		}
		else {
			delete[] this->m_name;
			this->setEmpty();
		}
	}
	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
		this->set(name, number, vCode, sNumber);
	}
	HealthCard::HealthCard(const HealthCard& hc) {
		if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			this->set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
	}
	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (&hc != this) {
				this->set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}
	HealthCard::~HealthCard() {
		delete[] this->m_name;
	}
	HealthCard::operator bool() const {
		return this->m_name != nullptr;
	}
	ostream& HealthCard::print(ostream& ostr, bool toFile) const {
		if (*this) {
			if (this->validID(this->m_name, this->m_number, this->m_vCode, this->m_sNumber)) {
				if (toFile) {
					ostr << this->m_name << ',';
					this->printIDInfo(ostr);
					ostr << endl;
				}
				else {
					ostr.fill('.');
					ostr.width(50);
					ostr.setf(ios::left);;
					ostr << this->m_name;
					this->printIDInfo(ostr);
				}
			}
		}
		return ostr;
	}
	istream& HealthCard::read(istream& istr) {
		char name[MaxNameLength];
		int num;
		char code[3];
		char snum[10];
		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> num;
		extractChar(istr, '-');
		istr.get(code, 3, ',');
		extractChar(istr, ',');
		istr.get(snum, 10, '\n');
		extractChar(istr, '\n');
		if (!istr.fail()) {
			this->set(name, num, code, snum);
		}
		else {
			istr.clear();
			istr.ignore(1000, '\n');
		}
		return istr;
	}
	ostream& operator<<(ostream& ostr, const HealthCard& hc) {
		if (hc) {
		 hc.print(ostr, false);
		}
		else {
			cout << "Invalid Health Card Record";
		}
		return ostr;
	}
	istream& operator>>(istream& istr, HealthCard& hc) {
		return hc.read(istr);
	}
}