//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 10 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
#include <iostream>
#include <fstream>
using namespace std;
namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];
   public:
       bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
       void setEmpty();
       void allocateAndCopy(const char* name);
       void extractChar(istream& istr, char ch) const;
       ostream& printIDInfo(ostream& ostr) const;
       void set(const char* name, long long number, const char vCode[], const char sNumber[]);
       HealthCard(const char* name = nullptr, long long number = 0, const char vCode[0] = NULL, const char sNumber[0] = NULL);
       HealthCard(const HealthCard& hc);
       HealthCard& operator=(const HealthCard& hc);
       ~HealthCard();
       operator bool() const;
       ostream& print(ostream& ostr, bool toFile = true) const;
       istream& read(istream& istr);
   };

   ostream& operator<<(ostream& ostr, const HealthCard& hc);
   istream& operator>>(istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H


