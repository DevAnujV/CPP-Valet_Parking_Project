//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include "ReadWritable.h"
#include <iostream>

namespace sdds {

	class Vehicle : public ReadWritable {
		char m_licPlate[8 + 1]{};
		char* m_makeandModel{};
		unsigned int m_pspot{};
		virtual std::ostream& writeType(std::ostream& OS)const = 0;

	protected:

		bool isEmpty()const; // changed from protected to public to use in parking.cpp
		const char* getLicensePlate()const; // made public because needed in Parking.cpp 
		void setEmpty();
		const char* getMakeModel()const;
		void setMakeModel(const char* newMandM);
		std::istream& read(std::istream& cinRef);
		std::ostream& write(std::ostream& coutRef)const;
		
	public:

		Vehicle();
		Vehicle(const char* licPlate, const char* makeAndModel);
		Vehicle(const Vehicle& copyVehicle);
		Vehicle& operator=(const Vehicle& copyVehicle);
		Vehicle& setParkingSpot(const int newPspot);
		const int getParkingSpot()const;
		bool operator==(const char* licPlate)const;
		bool operator==(const Vehicle& anotherVehicle)const;
		virtual ~Vehicle(); // made virtual (not sure if needed)???? because parent class already virtual destructor

		//move the down things to protected!!!!!!!!!!!!

		



	};
}

#endif // !SDDS_VEHICLE_H
