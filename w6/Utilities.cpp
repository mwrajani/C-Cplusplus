//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Autoshop.h"
#include "Vehicle.h"
#include "Racecar.h"
#include "Car.h"
#include <sstream>
using namespace std;
namespace sdds {
	std::string& trimm(std::string& edit)
	{
		edit.erase(0, edit.find_first_not_of(' '));
		edit.erase(edit.find_last_not_of(' ') + 1);
		return edit;
	}
	Vehicle* createInstance(std::istream& in) {
		string tag;
		tag[0] = '\0';
		getline(in, tag, '\n');
		tag = trimm(tag);
		if (tag[0] == 'c' || tag[0] == 'C') {
			Vehicle* car = nullptr;
			stringstream inbuf(tag);
			car = new Car(inbuf);
			return car;
		}
		else if (tag[0] == 'r' || tag[0] == 'R') {
			Vehicle* car = nullptr;
			stringstream inbuf(tag);
			car = new Racecar(inbuf);
			return car;
		}
		else if (tag[0] != '\0')
		{
			throw tag[0];
		}
		else {
			return nullptr;
		}
	}
}