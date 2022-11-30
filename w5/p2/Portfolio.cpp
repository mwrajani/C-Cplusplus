/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------
Name: Muhammad Wajih Rajani
email : mwrajani@myseneca.ca
Student id : 142199207
Date : 2 / 19 / 2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    Portfolio::~Portfolio() {}

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }
    Portfolio::operator double() const {
        return this->m_value;
    }

    Portfolio::operator const char* () const {
        return this->m_stock;
    }
    Portfolio::operator char() const {
        return this->m_type;
    }
    Portfolio::operator bool() const {
        return this->m_type == 'G' || this->m_type == 'V' || this->m_type == 'I';
    }
    Portfolio& Portfolio::operator+=(double add) {
        if (*this) {
            if (add > 0) {
                this->m_value += add;
            }
        }
        return *this;
    }
    Portfolio& Portfolio::operator-=(double sub) {
        if (*this) {
            if (sub > 0) {
                this->m_value -= sub;
            }
        }
        return *this;
    }
    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    bool Portfolio::operator~() const {
        bool ret = false;
        if (this->m_value < 0) {
            ret = true;
        }
        return ret;
    }
    ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    void Portfolio::operator<<(Portfolio& movFrom) {
        if (this->m_stock != movFrom.m_stock) {
            if (*this) {
                if (movFrom) {
                    this->m_value += movFrom.m_value;
                    movFrom.emptyPortfolio();
                }
            }
        }
    }
    void Portfolio::operator>>(Portfolio& movTo) {
        if (this->m_stock != movTo.m_stock) {
            if (*this) {
                if (movTo) {
                    movTo.m_value += this->m_value;
                    this->emptyPortfolio();
                }
            }
        }
    }
    double operator + (Portfolio& left, Portfolio& right) {
        double ret = 0;
        if (left) {
            if (right) {
                ret = double(right) + double(left);
            }
        }
        return ret;
    }
    double operator += (double& left, Portfolio& right) {
        if (right) {
          left += double(right);
        }
    return left;
    }
}
