#pragma once
////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_WORKSTATION_H_
#define SDDS_WORKSTATION_H_
#include<stdio.h>
#include<string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"
using namespace std;
extern std::deque<sdds::CustomerOrder> g_pending;
extern std::deque<sdds::CustomerOrder> g_completed;
extern std::deque<sdds::CustomerOrder> g_incomplete;
namespace sdds {
    class Workstation : public Station {
        std::deque<CustomerOrder> m_orders;
        Workstation* m_pNextStation;
    public:
        Workstation(const std::string& String) : Station{ String } {};
        void fill(ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
        bool isEmpty() const;
    };
}
#endif