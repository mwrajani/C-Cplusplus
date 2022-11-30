////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#include <chrono>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "TimedTask.h"
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
using namespace std;
namespace sdds {
    class ProteinDatabase {
        string *typeArray;
        int arraySize;
    public:
        ProteinDatabase();
        ~ProteinDatabase();
        ProteinDatabase(const char* tName);
        ProteinDatabase(ProteinDatabase&& moveIt);
        ProteinDatabase(const ProteinDatabase& copyIt);
        ProteinDatabase& operator=(const ProteinDatabase& copyIt);
        ProteinDatabase& operator=(ProteinDatabase&& moveIt);
        size_t size();
        std::string operator[](size_t);
    };
}
#endif 

