//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Autoshop.h"
#include "Vehicle.h"
#include "Car.h"
using namespace std;
namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto ptr = m_vehicles.begin(); ptr < m_vehicles.end(); ptr++) {
			(*ptr)->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;
	}
	Autoshop::~Autoshop() {
		for (size_t i = 0; i < m_vehicles.size(); i++)
		{
			delete m_vehicles[i];
		}
	}
}