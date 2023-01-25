//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {

		bool m_carwashFlag{};

		std::istream& read(std::istream& cinRef);
		std::ostream& write(std::ostream& coutRef)const;

	protected:
		std::ostream& writeType(std::ostream& OS)const;

	public:
		Car();
		Car(char* licPlate, char* makeAndModel);
		Car(const Car& C);
		Car& operator=(const Car& C);
		~Car();
	};
}

#endif // !SDDS_CAR_H