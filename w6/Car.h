//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef _SDDS_CAR_H
#define _SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	class Car : public Vehicle {
		std::string maker;
		char condit;
		double topspeed = 0;
	public:
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif