//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <string>
#include "Car.h"
#include "Vehicle.h"
using namespace std;
namespace sdds {
std::string& trimmer(std::string& edit)
{
	edit.erase(0, edit.find_first_not_of(' '));
	edit.erase(edit.find_last_not_of(' ') + 1);
	return edit;
}
	Car::Car(std::istream& istr) {
		string tag;
		bool isSpace = true;
		getline(istr, tag, ',');
			getline(istr, maker, ',');
			maker = trimmer(maker);
			size_t pointBegin = tag.find(",");
			tag.erase(0, pointBegin + 1);
			getline(istr, tag, ',');
			tag = trimmer(tag);
			for (size_t i = 0; i < tag.length(); i++)
			{
				if (tag[i] != ' ' && isSpace == true)
				{
					condit = tag[i];
					isSpace = false;
				}
			}
			if (isSpace == true)
			{
				condit = 'n';
			}
			if (condit != 'n' && condit != 'b' && condit != 'u')
			{
				throw "Invalid record!";
			}
			pointBegin = tag.find(",");
			tag.erase(0, pointBegin + 1);
			trimmer(tag);
			istr >> topspeed;
			if (istr.fail()) {
				istr.clear();
				istr.ignore(2000, '\n');
				throw "Invalid record!";
			}
	}
	std::string Car::condition() const {
		if (condit == 'n')
		{
			return "new";
		}
		else if (condit == 'u') {
			return "used";
		}
		return "broken";
	}
	double Car::topSpeed() const {
		return topspeed;
	}
	void Car::display(std::ostream& out) const {

		out << "| " << right << setw(10) << maker << " | " << left << setw(6) << condition() << " | " << fixed << setprecision(2) << setw(6) << topspeed << " |";
	}
}
