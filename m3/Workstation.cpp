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
#include "Workstation.h"
using namespace sdds;
using namespace std;
deque<CustomerOrder> g_pending{};
deque<CustomerOrder> g_completed{};
deque<CustomerOrder> g_incomplete{};
bool Workstation::isEmpty() const {
    return m_orders.empty();
}
void Workstation::fill(ostream& os) {
    if (m_orders.size()) {
        m_orders.front().fillItem(*this, os);
    }
}

bool Workstation::attemptToMoveOrder() {
        bool returnVal;
        if (!m_orders.size()) {
            returnVal = true;
        }
        else if (m_orders.front().isItemFilled(getItemName()) || !this->getQuantity()) {
            if (!m_pNextStation) {
                if (m_orders.front().isOrderFilled()) {
                    g_completed.push_back(move(m_orders.front()));
                }
                else {
                    g_incomplete.push_back(move(m_orders.front()));
                }
            }
            else {
                (*m_pNextStation) += move(m_orders.front());
            }
            m_orders.pop_front();
            returnVal = true;
        }
        else {
            returnVal = false;
        }
        return returnVal;
}
void Workstation::setNextStation(Workstation* station) {
    m_pNextStation = station;
}
Workstation* Workstation::getNextStation() const {
    return m_pNextStation;
}
void Workstation::display(ostream& os) const {
    os << getItemName() << " --> ";
    if (!m_pNextStation) {
        os << "End of Line" << endl;
    }
    else {
        os << m_pNextStation->getItemName() << endl;
    }
}
Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
    m_orders.push_back(move(newOrder));
    return *this;
}