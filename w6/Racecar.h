//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Vehicle.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	class Racecar : public Car {
		double m_booster = 0;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif
