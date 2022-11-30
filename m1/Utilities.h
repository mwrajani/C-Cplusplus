#pragma once
////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include<stdio.h>
#include<string>
using namespace std;
namespace sdds {
    class Utilities {
        size_t m_widthField = 1;
        static char m_delimiter;
    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();
    };
}
#endif 


