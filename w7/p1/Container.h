//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 20 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include<iostream>
#include<cstring>
using namespace std;
namespace sdds {

	class Container
	{
		char Content[50];
		int Capacity;
		int contentVolume = 0;

	protected:
		void setEmpty();
		int capacity();
		int volume();
	public:
		Container(const char* Content, int Capacity, int contentVolume = 0);
		int operator += (int volume);
		int operator -= (int volume);
		operator bool();
		void clear(int num, const char* desc);
		istream& read(istream& is);
		ostream& print(ostream& ostr);
	};
	ostream& operator<<(ostream& ostr, Container& Container);
	istream& operator>>(istream& istr, Container& Container);
}
#endif