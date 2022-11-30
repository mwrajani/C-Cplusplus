/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
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
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/14/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    Flight::operator bool() const { 
        double reqFuel = this->m_passengers;
        reqFuel = reqFuel *600;
        bool ret = false;
        if (this->m_passengers > 0 && m_fuel >= reqFuel) {
            ret = true; 
        }
        return ret;
    }

    Flight::operator int() const {
        return this->m_passengers;
    }
    Flight::operator double() const {
        return this->m_fuel;
    }
    Flight::operator const char* () const {
        return this->m_title;
    }
    bool Flight::operator ~() const {
        return this->m_passengers == 0;
    }
    Flight& Flight::operator = (Flight& copy) {
        this->m_passengers = copy.m_passengers;
        this->m_fuel = copy.m_fuel;
        strcpy(this->m_title, copy.m_title);
        copy.emptyPlane();
        return *this;
    }
    Flight& Flight::operator = (int copyI) {
        if (copyI > 0 && copyI <= Boen747Capacity) {
            this->m_passengers = copyI;
        }
        return *this;
    }
    Flight& Flight::operator = (double copyD) {
        if (copyD > 0 && copyD < FuelTankCapacity) {
            this->m_fuel = copyD;
        }
        return *this;
    }
    Flight& Flight::operator += (int addI){
        int total = 0;
        if (addI > 0) {
            total = this->m_passengers + addI;
            if (total <= Boen747Capacity && total >0){
                this->m_passengers = total;
            }
            else {
                this->m_passengers = Boen747Capacity;
            }
        }
        return *this;
    }
    Flight& Flight::operator += (double addD){
      double total = 0;
        if (addD > 0) {
            total = this->m_fuel + addD;
            if (total <= FuelTankCapacity && total > 0) {
                this->m_fuel = total;
            }
            else {
                this->m_fuel = FuelTankCapacity;
            }
        }
        return *this;
    }
    Flight& Flight::operator -= (int remI) {
        int total = 0;
        if (remI > 0) {
            total = this->m_passengers - remI;
            if (total <= Boen747Capacity && total > 0) {
                this->m_passengers = total;
            }
            else {
                this->m_passengers = 0;
            }
        }
        return *this;
    }
    Flight& Flight::operator -= (double remD) {
        double total = 0;
        if (remD > 0) {
            total = this->m_fuel - remD;
            if (total <= FuelTankCapacity && total > 0) {
                this->m_fuel = total;
            }
            else {
                this->m_fuel = 0;
            }
        }
        return *this;
    }
    Flight& Flight::operator << (Flight& copy) {
        int total = 0;
        if (copy) {
            if (*this) {
                if (copy.m_passengers > 0) {
                    total = this->m_passengers + copy.m_passengers;
                    if (total <= Boen747Capacity && total > 0) {
                        this->m_passengers = total;
                        copy.m_passengers = 0;
                    }
                    else {
                        this->m_passengers = Boen747Capacity;
                        copy.m_passengers = total - Boen747Capacity;
                    }
                }
            }
        }
        return *this;
    }
    Flight& Flight::operator >> (Flight& copied) {
        int total = 0;
        if (copied) {
            if (*this) {
                if (this->m_passengers > 0) {
                    total = this->m_passengers + copied.m_passengers;
                    if (total <= Boen747Capacity && total > 0) {
                        copied.m_passengers = total;
                        this->m_passengers = 0;
                    }
                    else {
                        copied.m_passengers = Boen747Capacity;
                        this->m_passengers = total - Boen747Capacity;
                    }
                }
            }
        }
        return *this;
    }
    int operator + (Flight& left, Flight& right) {
        int total = 0;
        if (left) {
            if (right) {
                total = int(left) + int(right);
            }
        }
        return total;
    }
    int operator += (int& left, Flight& right) {
        left = left + int(right);
        return left;
    }
}