//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Vehicle.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif