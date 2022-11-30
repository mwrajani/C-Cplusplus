//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef _SDDS_AUTOSHOP_H
#define _SDDS_AUTOSHOP_H
#include "Vehicle.h"
#include <vector>
#include <iostream>
#include <list>
#include <fstream>
#include <cstring>
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template <class T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (size_t i = 0; i < m_vehicles.size(); i++) {
				if (test(m_vehicles[i])) {
					vehicles.push_back(m_vehicles[i]);
				}
			}
		}
	};
}
#endif