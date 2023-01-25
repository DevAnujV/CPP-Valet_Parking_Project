//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Motorcycle : public Vehicle {

		bool m_hasSideCar;

		std::istream& read(std::istream& cinRef);
		std::ostream& write(std::ostream& coutRef)const;

	protected:
		std::ostream& writeType(std::ostream& OS)const;

	public:
		Motorcycle();
		Motorcycle(char* licPlate, char* makeAndModel);
		Motorcycle(const Motorcycle& M);
		Motorcycle& operator=(const Motorcycle& M);
		~Motorcycle();
	};
}

#endif // !SDDS_CAR_H