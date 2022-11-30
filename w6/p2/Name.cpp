//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 12 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Name.h"
#include <fstream>
#include <string>
using namespace std;
namespace sdds {
	void Name::setEmpty() {
		if (this->fName != nullptr) {
			delete[] this->fName;
			this->fName = nullptr;
		}
		if (this->mName != nullptr) {
			delete[] this->mName;
			this->mName = nullptr;
		}
		if (this->lName != nullptr) {
			delete[] this->lName;
			this->lName = nullptr;
		}
	}
	Name::operator bool() const {
		return this->fName != nullptr;
	}
	Name::Name()
	{
		this->setEmpty();
	}
	Name::Name(const char* fname)
	{
		this->setEmpty();
		if (fname != nullptr) {
			this->fName = new char[strlen(fname) + 1];
			strcpy(this->fName, fname);
		}
	}
	Name::Name(const char* fname, const char* lname)
	{
		this->setEmpty();
		if (fname != nullptr) {
			this->fName = new char[strlen(fname) + 1];
			strcpy(this->fName, fname);
		}
		if (lname != nullptr) {
			this->lName = new char[strlen(lname) + 1];
			strcpy(this->lName, lname);
		}
	}
	void Name::set(const char* fname = nullptr, const char* mname = nullptr, const char* lname = nullptr) {
		this->setEmpty();
		if (fname != nullptr) {
			if (fname != nullptr) {
				this->fName = new char[strlen(fname) + 1];
				strcpy(this->fName, fname);
			}
			if (lname != nullptr) {
				this->lName = new char[strlen(lname) + 1];
				strcpy(this->lName, lname);
				if (mname != nullptr) {
					this->mName = new char[strlen(mname) + 1];
					strcpy(this->mName, mname);
				}
			}
			else if (mname) {
				this->lName = new char[strlen(mname) + 1];
				strcpy(this->lName, mname);
			}
		}
	}
	Name::Name(const char* fname, const char* mname, const char* lname)
	{
		this->setEmpty();
		set( fname, mname,  lname);
	}
	Name::Name(const Name& hc) {
		if (&hc) {
			this->set(hc.fName, hc.mName, hc.lName);
		}
	}
	Name::~Name() {
		this->setEmpty();
	}
	Name& Name::operator=(const Name& hc) {
		this->setEmpty();
		if (&hc != this) {
			if (hc.fName != nullptr) {
				if (hc.fName != nullptr) {
					this->fName = new char[strlen(hc.fName) + 1];
					strcpy(this->fName, hc.fName);
				}
				if (hc.mName != nullptr) {
					this->mName = new char[strlen(hc.mName) + 1];
					strcpy(this->mName, hc.mName);
				}
				if (hc.lName != nullptr) {
					this->lName = new char[strlen(hc.lName) + 1];
					strcpy(this->lName, hc.lName);
				}
			}
		}
		return *this;
	}
	void Name::setShort(bool abbr) {
		char newchar[55] = {0};
		if (this->mName) {
			strncpy(newchar, this->mName, 1);
			newchar[1] = '.';
			if (abbr) {
				strcpy(this->mName, newchar);
			}
		}
	}
	Name& Name::operator+=(const char* hc) {
		bool doi = true;
		int j = strlen(hc);
		if (this->fName != nullptr && this->mName != nullptr && this->lName != nullptr) {
			doi = false;
			this->setEmpty();
		}
			for (int i = 0; i < j; i++)
			{
				if (hc[i] == ' ') {
					doi = false;
				}
			}
			if (strcmp(hc, "") == 0) {
				doi = false;
			}
			if (hc== nullptr) {
				doi = false;
			}
		if (doi) {
			if (this->fName == nullptr) {
				this->fName = new char[strlen(hc) + 1];
				strcpy(this->fName, hc);
			}
			else if (this->mName == nullptr) {
				this->mName = new char[strlen(hc) + 1];
				strcpy(this->mName, hc);
			}
			else if (this->lName == nullptr) {
				this->lName = new char[strlen(hc) + 1];
				strcpy(this->lName, hc);
			}
		}
		return *this;
	}
	ostream& Name::print(ostream& ostr) const{
		if (*this) {
			if (this->fName && this->mName && this->lName) {
				ostr << this->fName << ' ' << this->mName << ' ' << this->lName;
			}
			else if (this->fName && this->lName) {
				ostr << this->fName << ' ' << this->lName;
			}
			else if (this->fName && this->mName) {
				ostr << this->fName << ' ' << this->mName;
			}
			else {
				ostr << this->fName;
			}
		}
		else{
			ostr << "Bad Name";
		}
		return ostr;
	}
	void Name::extractChar(istream& istr, char ch) const {
		if (istr.peek() == ch) {
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}
	istream& operator>>(istream& istr, Name& hc) {
			string fname,mname,lname;
			hc.setEmpty();
			istr >> fname;
			if (istr.peek() == ' ') {
				istr >> mname;
				if (istr.peek() == ' ') {
					istr >> lname;
					if (istr.peek() == ' ') {
						hc.setEmpty();
					}
					else{
						hc.set(fname.c_str(), mname.c_str(), lname.c_str());
					}
				}
				else{
					hc.set(fname.c_str(), mname.c_str());
				}
			}
			else{
				hc.set(fname.c_str());
			}
			return istr;
	}
	ostream& operator<<(ostream& ostr, const Name& hc) {
		return hc.print(ostr);
	}
}
