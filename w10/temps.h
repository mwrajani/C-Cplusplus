////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////4 / 10 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*------------------------------------------------------
Workshop 10 part 1
Module: Collection
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#ifndef SDDS_TEMPS_H_
#define SDDS_TEMPS_H_
#include "Collection.h"
using namespace std;
namespace sdds {
    template <class type>
    Collection<type> select(const type* array, int size, const type notArray) {
        int Size = 0, counter = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] == notArray)
            {
                Size++;
            }
        }
        Collection<type>Class(Size);
        for (int i = 0; i < size; i++)
        {
            if (array[i] == notArray)
            {
                Class[counter] = array[i];
                counter++;
            }
        }
        return Class;
    }

   template <class type>
   void printCollection(const Collection<type>& object, const char* title) {
       cout << title<< endl;
       for (int i = 0; i < object.size(); i++)
       {
           cout << object[i] << endl;
       }
    }
}
#endif