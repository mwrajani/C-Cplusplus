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
#include <algorithm>
#include <iterator>
#include "Utilities.h"
#include "Station.h"
using namespace std;
namespace sdds {
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 1;
    Station::Station(const string& record) {
       size_t next_pos=0;
       bool more;
       Utilities util;
       id = id_generator++;
       name = util.extractToken(record, next_pos, more);
       serialNum = stoi(util.extractToken(record, next_pos, more));
       inStock = stoi(util.extractToken(record, next_pos, more));
       if (m_widthField < util.getFieldWidth())
       {
           m_widthField = util.getFieldWidth();
       }
       desc = util.extractToken(record, next_pos, more);
    }
    const std::string& Station::getItemName() const {
        return name;
    }
    size_t Station::getNextSerialNumber() {
        return serialNum++;
    }
    size_t Station::getQuantity() const {
        return inStock;
    }
    void Station::updateQuantity() {
        if (inStock != 0) {
            inStock--;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        if (full)
        {
            os << setw(3) << setfill('0') << id << " | " << setw(m_widthField+1) << setfill(' ') << left << name << " | " << setw(6) << setfill('0') << right << serialNum << " | " << setw(4) << setfill(' ') << inStock << " | " << desc << endl;
        }
        else {
            os << setw(3) << setfill('0') << id << " | " << setw(m_widthField+1) << setfill(' ') << left << name << " | " << setw(6) << setfill('0') << right << serialNum << " | " << endl;
        }

    }
}