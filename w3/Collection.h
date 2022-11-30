////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////4 / 10 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include "Pair.h"
#include <string>

namespace sdds
{
    template<class T, int CAPACITY>
    class Collection
    {
    protected:
        T aray[CAPACITY];
        int noTrans{ 0 };
	    T dummy{};

    public:
		virtual ~Collection() = default;
          		Collection() {
		}
		int size() const{
			return noTrans;
		}
		void display(std::ostream& os = std::cout) const{
			os << "----------------------\n| Collection Content |\n----------------------" << std::endl;
			for (int i = 0; i < noTrans; i++)
			{
				os << aray[i] << std::endl;
			}
			os << "----------------------" << std::endl;
		}
        	virtual bool add(const T& item) {
        			bool returnVal = false;
        			if (noTrans < CAPACITY)
        			{
        				aray[noTrans++] = item;
        				returnVal = true;
        			}
        			return returnVal;
        	}
        T operator[](int index){
			T returnVal;
			if (index < noTrans) 
				returnVal = aray[index];
				//return aray[index];
			else			
			//	return dummy;
				returnVal = dummy;
			
			return returnVal;
		}
	};
   	template <>
	Pair Collection<Pair, 100>::operator[](int index){
		Pair returnVal;
		dummy = Pair("No Key", "No Value");
		if (size() > 0 && index >= 0 && index <= size() - 1) {
			returnVal = aray[index];
		}
		else
		{
			returnVal = dummy;
		}
		return returnVal;
	}
}
#endif