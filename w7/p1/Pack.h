//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 20 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include<cstring>
#include"Container.h"
using namespace std;
namespace sdds {

	class Pack : public Container
	{
		int unitSize = 0;
	public:
		Pack(const char* content, int size, int unitsize = 330, int numunits = 0);
		int operator += (int volume);
		int operator -= (int volume);
		int unit();
		int noOfUnits();
		int size();
		void clear(int packSize, int unitsize, const char* desc);
		istream& read(istream& is);
		ostream& print(ostream& ostr);
	};
	ostream& operator<<(ostream& ostr, Pack& Pack);
	istream& operator>>(istream& istr, Pack& Pack);
}
#endif