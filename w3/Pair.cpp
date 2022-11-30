////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "Pair.h"

using namespace std;
namespace sdds {
	Pair::Pair() {
	}
	bool Pair::operator==(const Pair& other) {
		return this->key == other.key;
	}
	const string& Pair::getKey()const { return key; }
	const string& Pair::getValue()const { return value; }
	Pair::Pair(const std::string& Key, const std::string& Value) : key{ Key }, value{ Value }{}
	std::ostream& operator<< (std::ostream& ostr, const Pair& pair) {
		ostr << setw(20) << right << pair.getKey() << ": " << pair.getValue();
		return ostr;
	}
}
