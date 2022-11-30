#pragma once
////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_STATION_H_
#define SDDS_STATION_H_
#include<stdio.h>
#include<string>
using namespace std;
namespace sdds {
    class Station {
        int id;
        string name;
        string desc;
        size_t serialNum;
        size_t inStock;
        static size_t m_widthField;
        static size_t id_generator;
    public:
        Station(const string&);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}
#endif