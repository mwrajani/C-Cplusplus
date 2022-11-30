//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 12 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	class Name
	{
		char* fName{};
		char* mName{};
		char* lName{};
	public:
		operator bool() const;
		Name();
		Name(const char* fname);
		Name(const char* fname, const char* lname);
		Name(const char* fname, const char* mname, const char* lname);
		Name(const Name& hc);
		~Name();
		void set(const char* fname, const char* mname, const char* lname);
		void setEmpty();
		Name& operator=(const Name& hc);
		Name& operator+=(const char *hc);
		void setShort(bool abbr);
		ostream& print(ostream& ostr) const;
		void extractChar(istream& istr, char ch) const;
	};
	istream& operator>>(istream& istr, Name& hc);
	ostream& operator<<(ostream& ostr, const Name& hc);
}
#endif