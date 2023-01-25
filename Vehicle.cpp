//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"
#include "Vehicle.h"
using namespace std;

namespace sdds {

	Vehicle::Vehicle()
	{
		setEmpty();
	}

	Vehicle::Vehicle(const char* licPlate, const char* makeAndModel) : m_pspot{ 0 } // 0 parking spot means vehicle is not parked.
	{
		if (licPlate && makeAndModel) {
			if (licPlate[0] && makeAndModel[0] && ut.strlen(licPlate) > 0 && ut.strlen(licPlate) < 9 && ut.strlen(makeAndModel) >= 2) {

				m_makeandModel = new char[ut.strlen(makeAndModel) + 1];
				ut.strcpy(m_makeandModel, makeAndModel);
				ut.strcpy(m_licPlate, licPlate);
			}
		}
		else
		{
			setEmpty();
		}
	}
	Vehicle::Vehicle(const Vehicle& copyVehicle)
	{
		*this = copyVehicle;
	}

	const int Vehicle::getParkingSpot() const
	{
		return m_pspot;
	}

	Vehicle& Vehicle::setParkingSpot(const int newPspot)
	{
		if (newPspot >= 0) {
			m_pspot = newPspot;
		}
		else {
			setEmpty();
		}
		return *this;
	}

	bool Vehicle::operator==(const char* licPlate) const
	{
		char licPlLower[8 + 1]{};
		char vehiclePlLower[8 + 1]{};

		if (ut.strlen(licPlate) == ut.strlen(this->m_licPlate)) {

			for (int i = 0; i < ut.strlen(licPlate); i++) {
				licPlLower[i] = ut.tolower(licPlate[i]);
				vehiclePlLower[i] = ut.tolower(this->m_licPlate[i]);
			}
		}
		else {
			ut.strcpy(vehiclePlLower, "X");
		}
		return (!(ut.strcmp(vehiclePlLower, licPlLower)));
	}

	bool Vehicle::operator==(const Vehicle& anotherVehicle) const
	{
		char anotherlicPlLower[8 + 1]{};
		char vehiclePlLower[8 + 1]{};

		if (ut.strlen(anotherVehicle.m_licPlate) == ut.strlen(this->m_licPlate)) {

			for (int i = 0; i < ut.strlen(anotherVehicle.m_licPlate); i++) {
				anotherlicPlLower[i] = ut.tolower(anotherVehicle.m_licPlate[i]);
				vehiclePlLower[i] = ut.tolower(this->m_licPlate[i]);
			}
		}
		return (!(ut.strcmp(vehiclePlLower, anotherlicPlLower)));
	}

	istream& Vehicle::read(std::istream& cinRef)
	{
		char upperCaseLicPlate[100]{};
		int i = 0;
		//	char makeAndModelRead[60+1]; 

		if (this->isCsv()) {

			cinRef.ignore(1, ',');

			cinRef >> this->m_pspot;
			cinRef.ignore(1, ',');
			cinRef.getline(upperCaseLicPlate, 8, ',');

			for (i = 0; upperCaseLicPlate[i] != '\0'; i++) {
				upperCaseLicPlate[i] = toupper(upperCaseLicPlate[i]);
			}

			if (m_licPlate[0]) {
				for (int y = 0; m_licPlate[y] != '\0'; y++) {
					m_licPlate[y] = '\0';
				};
			}
			for (int k = 0; upperCaseLicPlate[k] != '\0'; k++) {
				m_licPlate[k] = upperCaseLicPlate[k];
			}
			if (m_makeandModel) {
				if (m_makeandModel[0]) {
					delete[] m_makeandModel;
					m_makeandModel = nullptr;
				}
			}

			this->m_makeandModel = new char[60 + 1];
			cinRef.getline(m_makeandModel, 60, ',');

			if (!cin) {
				setEmpty();
			}

		}
		else {
			int j;
			m_pspot = 0; // parking spot is set to zero (above writeType (purevirtual) in notes.. so that later the parking spot can be set manually accoridng to available pointer in car.

			cout << "Enter License Plate Number: ";
			do {
				j = 0;
				upperCaseLicPlate[0] = 0;
				cinRef >> upperCaseLicPlate;

				for (j = 0; upperCaseLicPlate[j] != '\0'; j++) {
					upperCaseLicPlate[j] = toupper(upperCaseLicPlate[j]);
				}

			} while (j > 7 && cout << "Invalid License Plate, try again: "); // try , here instead of &&

			if (m_licPlate[0]) {
				for (int y = 0; m_licPlate[y] != '\0'; y++) {
					m_licPlate[y] = '\0';
				};
			}

			for (int k = 0; upperCaseLicPlate[k] != '\0'; k++) {
				m_licPlate[k] = upperCaseLicPlate[k];
			}

			cout << "Enter Make and Model: ";
			j = 0;

			if (m_makeandModel) {
				if (m_makeandModel[0]) {
					delete[] m_makeandModel;
					m_makeandModel = nullptr;
				}
			}

			this->m_makeandModel = new char[60 + 1];

			do {
				j = 0;
				m_makeandModel[0] = 0;
				cinRef.ignore(10000, '\n');
				cinRef.getline(m_makeandModel, 60, '\n');

				for (j = 0; m_makeandModel[j] != '\0'; j++) {}

			} while ((j < 2 || j > 60) && cout << "Invalid Make and model, try again: "); // try , here instead of &&

			if (!cin) {
				setEmpty();
			}
		}

		return cinRef;
	}

	ostream& Vehicle::write(std::ostream& coutRef) const
	{
		if (isEmpty()) {
			coutRef << "Invalid Vehicle Object" << endl;
		}
		else {
			writeType(coutRef);

			if (isCsv()) {
				coutRef << m_pspot << ',' << m_licPlate << ',' << m_makeandModel << ',';
			}
			else {
				coutRef << "Parking Spot Number: ";
				(m_pspot > 0) ? coutRef << m_pspot : coutRef << "N/A";
				coutRef << endl;
				coutRef << "License Plate: " << m_licPlate << endl;
				coutRef << "Make and Model: " << m_makeandModel << endl;
			}
		}
		return coutRef;
	}


	Vehicle& Vehicle::operator=(const Vehicle& copyVehicle)
	{
		if (this != &copyVehicle) {
			if (copyVehicle.m_makeandModel && copyVehicle.m_licPlate) {

				if (!(this->isEmpty())) {
					setEmpty();
				}

				m_pspot = copyVehicle.m_pspot;

				setCsv(copyVehicle.isCsv());

				ut.strcpy(m_licPlate, copyVehicle.m_licPlate);

				m_makeandModel = new char[ut.strlen(copyVehicle.m_makeandModel) + 1];
				ut.strcpy(m_makeandModel, copyVehicle.m_makeandModel);
			}
		}
		// setEmpty()????? check!!!!!!!
		return *this;
	}
	void Vehicle::setEmpty()
	{
		m_licPlate[0] = 0;

		if (m_makeandModel) {
			if (m_makeandModel[0]) {
				delete[] m_makeandModel;
			}
		}
		m_makeandModel = nullptr;
		m_pspot = -1;
	}

	bool Vehicle::isEmpty()const
	{
		return m_makeandModel == nullptr;
	}

	const char* Vehicle::getLicensePlate() const
	{
		return m_licPlate;
	}

	const char* Vehicle::getMakeModel() const
	{
		return m_makeandModel;
	}

	void Vehicle::setMakeModel(const char* newMandM)
	{
		if (newMandM && newMandM[0]) {
			if (m_makeandModel) {
				delete[] m_makeandModel;
				m_makeandModel = nullptr;
			}
			ut.strcpy(m_makeandModel, newMandM);
		}
		else {
			setEmpty();
		}

	}

	Vehicle::~Vehicle() {

		delete[] m_makeandModel;
	}



}
