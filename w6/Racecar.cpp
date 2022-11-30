//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Car.h"
#include "Vehicle.h"
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in) :Car(in) {
		string edit;
		getline(in, edit, '\n');
		edit = edit.substr(edit.find_last_of(',') + 1, edit.length());
		stringstream str(edit);
		str >> m_booster;
	}
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << '*';
	}
	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}
