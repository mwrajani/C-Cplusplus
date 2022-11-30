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
using namespace std;
namespace sdds
{
    char Utilities::m_delimiter;
    std::string& trimm(std::string& edit)
    {
        edit.erase(0, edit.find_first_not_of(' '));
        edit.erase(edit.find_last_not_of(' ') + 1);
        return edit;
    }
    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }
    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        size_t pointBegin = str.find(getDelimiter(), next_pos);
        string returnVal;
        if (pointBegin == next_pos)
        {
            more = false;
            throw string("delimiter found at next_pos");
        }
        returnVal = str.substr(next_pos, pointBegin - next_pos);
        next_pos = pointBegin + 1;
        more = pointBegin != string::npos;
        returnVal = trimm(returnVal);
        if (m_widthField < returnVal.length())
        {
            m_widthField = returnVal.length();
        }
        return returnVal;
    }
    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}