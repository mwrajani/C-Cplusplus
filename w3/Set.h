////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////4 / 10 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#include <cmath>
#include <string>
#include "Collection.h"
#include "Pair.h"
#ifndef SDDS_Set_H_
#define SDDS_Set_H_
namespace sdds {
	template<typename T>
	class Set : public Collection<T, 100>
	{
	public:
		bool add(const T& item) override{
			//bool returnVal = true;
			for (int i = 0; i < this->size(); i++) {
				if ((*this)[i] == item)
				{
					//returnVal = false;
					return false;
				}
			}
			//if (returnVal != false)
			//{
				//returnVal = Collection<T, 100>::add(item);
				return Collection<T, 100>::add(item);;
			//}
			//return returnVal;
		}
	};
	template<>
	bool Set<double>::add(const double& item) {
		for (auto i = 0; i < this->size(); i++)
		{
			if (std::fabs((*this)[i] - item) <= 0.01)
			{
				return false;

			}
		}
		return Collection::add(item);
	};
}
#endif
