//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022



#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"

#include "Car.h"//new
#include "Motorcycle.h"// new

#include <iostream>
#include <fstream>
#include "Utils.h"

using namespace std;

namespace sdds {

	Parking::Parking(const char* name, int noOfSpots) : m_noOfSpots{ noOfSpots }
	{
		if (m_noOfSpots < 10 || m_noOfSpots > m_maxParkingSpots) {
			m_fileName = nullptr;
		}

		if (name && name[0]) {
			m_fileName = new char[ut.strlen(name) + 1];
			ut.strcpy(m_fileName, name);
		}

		loadDataFile();
	}

	void Parking::displayparkingsOrCancel(const char* type)
	{
		//char typeof[50];
		cout << "---------------------------------" << endl;
		cout << type << endl;
		cout << "---------------------------------" << endl << endl;
	}

	Parking::~Parking()
	{
		saveDataFile();
		delete[] m_fileName;
		for (int i = 0; i <= m_noOfSpots; i++) {
			if (m_parkingSpotPointer[i]) {
				delete m_parkingSpotPointer[i];
			}
		}
	}

	bool Parking::loadDataFile()
	{
		//	bool firstTime = true; // added this!!!!!!
		bool fileLoaded = true;
		bool keepGoing = true;

		if (!isEmpty()) {

			fileLoaded = false;
			int X = 0; // new

			//Vehicle* newVehicle{};//

			char singleExtractedCharacter{}; // new

			if (m_fileName && m_fileName[0]) {

				ifstream file;
				file.open(m_fileName);

				if (file || file.is_open() || !file.fail()) {

					while (file.get(singleExtractedCharacter) && !file.eof() && keepGoing) { // new

						if (singleExtractedCharacter == 'M') {
							Motorcycle* newBike = nullptr;
							newBike = new Motorcycle; // !!!!!!!!!!!!!!!!!!!!!!!!! removed !!!!!!!!!!!!!!!!!!!!!!!!!

							newBike->setCsv(true);

							file >> *newBike;
							fileLoaded = true;
							m_parkingSpotPointer[newBike->getParkingSpot() - 1] = newBike;
							m_noOfParkedVehicles++;
							//m_parkingSpotPointer[newBike->getParkingSpot() - 1] = *newBike;
							//X = newBike->getParkingSpot() - 1;
						}
						else if (singleExtractedCharacter == 'C') {
							Car* newCar = nullptr;
							newCar = new Car; // !!!!!!!!!!!!!!!!!!!!!!!! removed !!!!!!!!!!!!!!!!!!!!!!

							newCar->setCsv(true);

							file >> *newCar;
							fileLoaded = true;
							m_parkingSpotPointer[newCar->getParkingSpot() - 1 ] = newCar;
							m_noOfParkedVehicles++;
							//X = newCar->getParkingSpot() - 1;
							//newVehicle = newCar;
							//m_parkingSpotPointer[counter] = newCar;
						}
						else {
							delete m_parkingSpotPointer[X];
							m_parkingSpotPointer[X] = nullptr;
							fileLoaded = false;
							keepGoing = false;
						}
					
						X++;
					}
				}
				else
				{
					fileLoaded = false;
				}
			}
		}
		return fileLoaded;
	}

		//	if (file) {
		//		cout << "---------------------------------" << endl << "loading data from " << m_fileName << endl << "---------------------------------";
		//		cout << endl << endl;

		//		fileLoaded = true;
		//		firstTime = false; // added this!!!!!!!!
		//	}
		//	else {
		//		cout << "Error in data file" << endl;
		//	}

		//}
		//else {
		//	cout << "Error in data file" << endl;
		//}

		bool Parking::isEmpty()
		{
			return (!m_fileName[0]); //++++++++++++++++++++++++ added [0] instead of asitis ++++++++++++++++++++++++++++++++++++++++++++++
		}

		void Parking::parkingStatus()
		{
			cout << "****** Valet Parking ******" << endl;
			cout << "*****  Available spots: ";
			cout.width(4);
			cout.setf(ios::left);
			cout << m_noOfSpots - m_noOfParkedVehicles;
			cout << " *****" << endl;
		}

		void Parking::parkVehicle()
		{
			//int userSelection;
			//Vehicle* newVehicle = nullptr;

			if ((m_noOfSpots - m_noOfParkedVehicles) <= 0) {
				cout << "Parking is full";
			}
			else {

				int selectedOption = 0;
				//char enterResponse;
				bool continues = true;

				//switch (userSelection) {

				while ((selectedOption != 5) && continues == true) {
					parkingStatus();
					MainMenu.displayParkingMenu();
					cin >> selectedOption;
					switch (selectedOption) {

					case 1:
						SubMenu.displayParkingMenu();
						cin >> selectedOption;

						switch (selectedOption) {

						case 3: cout << "Parking Cancelled" << endl;
							break;

						case 1: {
							bool endloop = false;
							//newVehicle = newCar; // or Vehicle* newVehicle = newCar

							for (int i = 0; i < m_noOfSpots && !endloop; i++) {

								if (m_parkingSpotPointer[i] == nullptr) {

									Car* newCar = nullptr;
									newCar = new Car;
									newCar->setCsv(false);

									cin >> *newCar;
									m_parkingSpotPointer[i] = newCar;
									m_parkingSpotPointer[i]->setParkingSpot(i + 1);
									cout << endl << "Parking Ticket" << endl << *m_parkingSpotPointer[i];
									m_noOfParkedVehicles++; //added new!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
									m_parkingSpotPointer[i]->setCsv(true);

									//cin.ignore(10000, '\n');
									cout << endl << "Press <ENTER> to continue....";
									cin.get();
									endloop = true;
								}
							}

							break;
						}
						case 2: 
						{ 
							bool endloop = false;

							for (int i = 0; i < m_noOfSpots && !endloop; i++) {

							if (m_parkingSpotPointer[i] == nullptr) {

								Motorcycle* newBike = nullptr;
								newBike = new Motorcycle;
								newBike->setCsv(false);
								//Vehicle* newVehicle = newBike;

								cin >> *newBike;
								m_parkingSpotPointer[i] = newBike;
								m_parkingSpotPointer[i]->setParkingSpot(i + 1);
								cout << endl << "Parking Ticket" << endl << *m_parkingSpotPointer[i];
								m_parkingSpotPointer[i]->setCsv(true);
								m_noOfParkedVehicles++; //added new!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

								cin.ignore(10000, '\n');
								cout << endl << "Press <ENTER> to continue....";
								cin.get();
								endloop = true;
							}
						}

							break;
						}
						}// switch closing bracket!!
						break;

					case 2: returnVehicle();
						break;

					case 3: ListParkedVehicle();
						break;

					case 4: FindVehicle();
						break;

					case 5: closeParking();
						break;

					case 6: if (exitParking())
					{
						continues = false;
						break;
					}

					} //. main switch closing bracket
				}
				
			}
		}
		

		void Parking::returnVehicle()
		{
			//char typeof[50];
			//cout << "---------------------------------" << endl;
			//cout << "Returning Vehicle" << endl;
			//cout << "---------------------------------" << endl << endl;
			char upperCaseLicPlate[1000];
			int j;

			cout << "Return Vehicle" << endl;
			cout << "Enter License Plate Number: ";
			do {
				j = 0;
				upperCaseLicPlate[0] = 0;
				cin >> upperCaseLicPlate;

				for (j = 0; upperCaseLicPlate[j] != '\0'; j++) {
					upperCaseLicPlate[j] = toupper(upperCaseLicPlate[j]);
				}

			} while (j > 7 && j < 1 && cout << "Invalid License Plate, try again: "); // try , here instead of &&

			bool vehicleFound = false;
			int i = 0;

			for (i = 0; i < m_noOfParkedVehicles && vehicleFound == false; i++) {
				if (m_parkingSpotPointer[i]) {
					if (!(*m_parkingSpotPointer[i] == upperCaseLicPlate)) {
						vehicleFound = false;
					}
					else {
						vehicleFound = true;
					}
				}
			}
				
			if (vehicleFound == true) {
				cout << endl << "Returning:" << endl;
				m_parkingSpotPointer[i-1]->setCsv(false);
				cout << *m_parkingSpotPointer[i-1];
				m_parkingSpotPointer[i-1]->setCsv(true);
				delete m_parkingSpotPointer[i-1];
				m_parkingSpotPointer[i-1] = nullptr;

				m_noOfParkedVehicles--; // check this!!!!!!!!
			}
			else {
				cout << endl << "License plate " << upperCaseLicPlate << " Not found" << endl;
			}

			cin.ignore(10000, '\n');
			cout << endl << "Press <ENTER> to continue....";
			cin.get();
		}
		void Parking::ListParkedVehicle()
		{
			//char typeof[50];
			//cout << "---------------------------------" << endl;
			//cout << "Listing Parked Vehicles" << endl;
			//cout << "---------------------------------" << endl << endl;
			cout << "*** List of parked vehicles ***" << endl;
			for (int i = 0; i < m_noOfSpots; i++) {

				if (m_parkingSpotPointer[i]) {
					m_parkingSpotPointer[i]->setCsv(false); // added false and then on line 287 added true to make it back to original.!!!!!!!!!!!!!!!!!
					cout << *m_parkingSpotPointer[i] << "-------------------------------" << endl;
					m_parkingSpotPointer[i]->setCsv(true); // same as line 286.
					//m_parkingSpotPointer[i]->setCsv(false); // same as line 286.
				}
			}
			cin.ignore(10000, '\n');
			cout << "Press <ENTER> to continue....";
			cin.get();
		}
		void Parking::FindVehicle()
		{
			//char typeof[50];
			//cout << "---------------------------------" << endl;
			//cout << "Finding a Vehicle" << endl;
			//cout << "---------------------------------" << endl << endl;
			int j;
			char upperCaseLicPlate[1000];

			cout << "Vehicle Search" << endl;

			cout << "Enter License Plate Number: ";
			do {
				j = 0;
				upperCaseLicPlate[0] = 0;
				cin >> upperCaseLicPlate;

				for (j = 0; upperCaseLicPlate[j] != '\0'; j++) {
					upperCaseLicPlate[j] = toupper(upperCaseLicPlate[j]);
				}

			} while (j > 7 && j < 1 && cout << "Invalid License Plate, try again: "); // try , here instead of &&

			bool match = false;  
			int i;

			for (i = 0; i < m_noOfSpots && match == false; i++) {
				
				if (m_parkingSpotPointer[i]) {
					if (*m_parkingSpotPointer[i] == upperCaseLicPlate) {
						match = true;
					}
				}
			}
				if (match == true) {
					cout << endl << "Vehicle found:" << endl;
					m_parkingSpotPointer[i-1]->setCsv(false);
					cout << *m_parkingSpotPointer[i-1];
					m_parkingSpotPointer[i - 1]->setCsv(true);
				}
				else {
					cout << endl << "License plate " << upperCaseLicPlate << " Not found" << endl;
				}

				cin.ignore(10000, '\n');
				cout << endl << "Press <ENTER> to continue....";
				cin.get();
			
		}

		bool Parking::closeParking()
		{
			bool returnedValue;
			char enterResponse;

			if (m_noOfParkedVehicles == 0) {
				cout << "Closing Parking" << endl;
				returnedValue = true;
			}
			else {

				cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
				cout << "Are you sure? (Y)es/(N)o: ";

				cin >> enterResponse;

				while (!(enterResponse == 'Y' || enterResponse == 'N' || enterResponse == 'y' || enterResponse == 'n')) {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> enterResponse;
				}

				if (enterResponse == 'N' || enterResponse == 'n') {
					returnedValue = false; // << endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << endl;
				}
				else {
					cout << "Closing Parking" << endl << endl;

					for (int i = 0; i <= m_noOfParkedVehicles; i++) {
						if (m_parkingSpotPointer[i]) {
							cout << "Towing request" << endl;
							cout << "*********************" << endl;
							m_parkingSpotPointer[i]->setCsv(false);
							if (i == m_noOfParkedVehicles) {
								cout << *m_parkingSpotPointer[i];
							}
							else {
								cout << *m_parkingSpotPointer[i] << endl;
							}
							m_parkingSpotPointer[i]->setCsv(true);
							delete m_parkingSpotPointer[i];
							m_parkingSpotPointer[i] = nullptr;
						}
					}
					returnedValue = true;
				}

				//return (enterResponse == 'Y' || enterResponse == 'y');
			}
			return returnedValue;
		}

		bool Parking::exitParking()
		{
			char enterResponse;
			//bool continues;

			cout << "This will terminate the program!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";

			cin >> enterResponse;

			while (!(enterResponse == 'Y' || enterResponse == 'N' || enterResponse == 'y' || enterResponse == 'n')) {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> enterResponse;
			}

			if (enterResponse == 'Y' || enterResponse == 'y') {
				//continues = false;
				cout << "Exiting program!" << endl;
			}

			return (enterResponse == 'Y' || enterResponse == 'y');
		}

		void Parking::saveDataFile()
		{
			ofstream owrite;
			owrite.open(m_fileName);

			if (owrite) { // if the file is opened....~~~~~~~~~~~~~~~~~~~~~~ OR if (owrite.is_open()) OR if (!owrite.fail())
				for (int i = 0; i < m_noOfSpots; i++) {
					if (m_parkingSpotPointer[i]) {
						owrite << *m_parkingSpotPointer[i];
					}
					else {
						owrite << "";
					}
				}
			}




			//if (!isEmpty()) {
			//	cout << "---------------------------------" << endl;
			//	cout << "Saving data into " << m_fileName << endl;
			//	cout << "---------------------------------" << endl;
			//}
		}


		int Parking::run()
		{
			if (!isEmpty()) {
				MenuItems MainMenu(0, "Parking Menu, select an action:", "Park Vehicle,Return Vehicle,List Parked Vehicles,Find Vehicle,Close Parking (End of day),Exit Program.");
				MenuItems SubMenu(1, "Select type of the vehicle:", "Car,Motorcycle,Cancel.");

				parkVehicle();
								
			}
			return isEmpty();
		}
}