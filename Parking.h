//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include "Menu.h"
#include "Vehicle.h"

#include <iostream>

namespace sdds {

	class Parking {

		const int m_maxParkingSpots = 100;
		int m_noOfSpots{};
		Vehicle* m_parkingSpotPointer[100]{};
		int m_noOfParkedVehicles{};

		char* m_fileName{};
		bool loadDataFile();
		bool isEmpty();
		Parking(const Parking&) = delete;
		Parking& operator=(const Parking&) = delete;
		void parkingStatus();
		void parkVehicle();
		void returnVehicle();
		void ListParkedVehicle();
		void FindVehicle();
		bool closeParking();
		bool exitParking();
		void displayparkingsOrCancel(const char* type);
		void saveDataFile();
		MenuItems MainMenu{ 0, "Parking Menu, select an action:", "Park Vehicle,Return Vehicle,List Parked Vehicles,Find Vehicle,Close Parking (End of day),Exit Program." };
		MenuItems SubMenu{ 1, "Select type of the vehicle:", "Car,Motorcycle,Cancel." };

	public:
		int run();
		Parking(const char* name, int noOfSpots);
		virtual ~Parking();
	};


}
#endif // !SDDS_PARKING_H
