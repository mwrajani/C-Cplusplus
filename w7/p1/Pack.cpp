//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 20 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Container.h"
#include "Pack.h"

using namespace std;

namespace sdds
{
    Pack::Pack(const char* content, int size, int unitsize, int numunits) :Container(content, size* unitsize, unitsize* numunits) {
        if (unitsize > 0) {
            unitSize = unitsize;
        }
        else {
            unitSize = 0;
            setEmpty();
        }
    }
    int Pack::operator += (int add) {
        int ret = (Container::operator+= (add * unitSize)) / unitSize;
        return ret;
    }
    int Pack::operator -= (int remove) {
        int ret = (Container::operator-= (remove * unitSize)) / unitSize;
        return ret;
    }

    int Pack::unit() {
        return unitSize;
    }
    int Pack::noOfUnits() {
        return volume() / unitSize;
    }
    int Pack::size() {
        return capacity() / unitSize;
    }
    void Pack::clear(int packsize, int unitsize, const char* desc) {
        if (unitsize > 0) {
            Container::clear(packsize * unitsize, desc);
        }
        unitSize = unitsize;
    }
    ostream& Pack::print(ostream& ostr) {
        Container::print(ostr);
        if (Container::operator bool()) {
            cout << ", " << noOfUnits() << " in a pack of " << size();
        }
        return ostr;
    }
    istream& Pack::read(istream& is) {
        int enter = 0;
        if (Container::operator bool()) {
            if (size() > noOfUnits()) {
                cout << "Add to ";
                print(cout);
                cout << endl<<"> ";
                is >> enter;
                while (!enter || enter < 1 || enter >(size() - noOfUnits())) {
                    if (!enter) {
                        is.clear();
                        cout << "Invalid Integer, retry: ";
                        is >> enter;
                    }
                    if (enter < 1 || enter >(size() - noOfUnits())) {
                        is.clear();
                        cout << "Value out of range [1<=val<=" << size() - noOfUnits() << "]: ";
                        is >> enter;
                    }
                }
                cout << "Added " << (*this += enter) << endl;
            }
            else {
                cout << "Pack is full!, press <ENTER> to continue..." << endl;
                is.clear();
                while (is.get() != '\n');
            }
        }
        else {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            is.clear();
            while (is.get() != '\n');
        }
        return is;
    }
    ostream& operator<<(ostream& ostr, Pack& Pack) {
        return Pack.print(ostr);
    }
    istream& operator>>(istream& istr, Pack& Pack) {
        return Pack.read(istr);
    }
}
