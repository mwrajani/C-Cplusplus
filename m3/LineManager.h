#pragma once
////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_LINEMANAGER_H_
#define SDDS_LINEMANAGER_H_
#include<stdio.h>
#include<string>
#include <deque>
#include <vector>
#include "Station.h"
#include "CustomerOrder.h"
#include "Workstation.h"
using namespace std;
namespace sdds {
    class LineManager {
        std::vector<Workstation*> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;
    public:
        LineManager(const string& file, const vector<Workstation*>& stations);
        void reorderStations();
        bool run(ostream& os);
        void display(ostream& os) const;
    };
}
#endif