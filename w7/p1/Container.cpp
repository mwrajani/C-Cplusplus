//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 20 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include"Container.h"

using namespace std;
namespace sdds
{
    void Container::setEmpty() {
        Content[0] = '\0';
        Capacity = -1;
        contentVolume = 0;
    }
    int Container::capacity() {
        return Capacity;
    }
    int Container::volume() {
        return contentVolume;
    }
    int Container::operator += (int volume) {
        int difference = 0;
        if ((contentVolume + volume) > Capacity) {
            difference = Capacity - contentVolume;
            contentVolume = Capacity;
        }
        else {
            contentVolume += volume;
            difference = volume;
        }
        return difference;
    }
    int Container::operator -= (int volume) {
        int difference = 0;
        if ((contentVolume - volume) < 0) {
            difference = contentVolume;
            contentVolume = 0;
        }
        else {
            contentVolume -= volume;
            difference = volume;
        }
        return difference;
    }
    Container::operator bool() {
        return (Content[0] == '\0') ? false : true;
    }
    void Container::clear(int capacity, const char* desc) {
        if (desc[0] != '\0') {
            if (strlen(desc) > 49)
            {
                strncpy(Content, desc, 49);
                Content[49] = '\0';
            }
            else {
                strcpy(Content, desc);
            }
            Capacity = capacity;
        }
    }
    ostream& Container::print(ostream& ostr) {
        if (Content[0] != '\0') {
            ostr << Content << ": (" << contentVolume << "cc/" << Capacity<<')';
        }
        else {
            ostr << "****: (**cc/***)";
        }
        return ostr;
    }
    istream& Container::read(istream& is) {
        int enter = 0;
        if (*this) {
            //Add to Milk : (0cc / 250)
            cout << "Add to "<<Content << ": (" << contentVolume << "cc/" << Capacity << ')'<<endl;
            cout << "> ";
            if (Capacity > contentVolume) {
                is >> enter;
                while (enter > 220000 || enter < 1 || enter == 0) {
                    if (enter > 220000 || enter < 1) {
                        cout << "Value out of range [1<=val<=220000]: ";
                        is >> enter;
                    }
                    if (!is.good()) {
                        cout << "Invalid Integer, retry: ";
                        is >> enter;
                    }
                }
                cout << "Added " << (*this += enter) << " CCs" << endl;
            }
            else {
                cout << "Pack is full!, press <ENTER> to continue...";
                while (is.get() != '\n');
            }
        }
        else {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
        }
        return is;
    }
    Container::Container(const char* content, int capacity, int contentvolume) :Capacity(capacity), contentVolume(contentvolume) {
        if (content == nullptr || contentvolume > capacity) {
            setEmpty();
        }
        else {
            if (strlen(content) > 49)
            {
                strncpy(this->Content, content, 49);
            }
            else {
                strcpy(this->Content, content);
            }
        }
    }
    ostream& operator<<(ostream& ostr, Container& container) {
        container.print(ostr);
        return ostr;

    }
    istream& operator>>(istream& istr, Container& container) {
        container.read(istr);
        return istr;
    }
}