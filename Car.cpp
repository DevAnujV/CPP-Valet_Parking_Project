//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#include "Car.h"
#include "Utils.h"
#include <iostream>

using namespace std;
namespace sdds {

	Car::Car() : Vehicle()
	{

	}

	Car::Car(char* licPlate, char* makeAndModel) :Vehicle(licPlate, makeAndModel)
	{

	}

	Car::Car(const Car& C)
	{
		m_carwashFlag = C.m_carwashFlag;
		Vehicle::operator=(C); // caling to the assignment of vehcile class to take care of it.
	}

	Car& Car::operator=(const Car& C)
	{
		if (this != &C) {
			m_carwashFlag = C.m_carwashFlag;
			Vehicle::operator=(C); // caling to the assignment of vehcile class to take care
		}
		return *this;
	}

	Car::~Car()
	{
		
	}

	std::ostream& Car::writeType(std::ostream& OS) const
	{
		if (isCsv()) {
			OS << "C,";
		}
		else {
			OS << "Vehicle type: Car" << endl;
		}
		return OS;
	}

	std::istream& Car::read(std::istream& cinRef)
	{
		char userEnteredValue[1000]{};

		if (isCsv()) {
			Vehicle::read(cinRef);

			cinRef >> m_carwashFlag;
			cinRef.ignore(10000, '\n');
		}
		else {
			cout << endl << "Car information entry" << endl;
			Vehicle::read(cinRef);

			cout << "Carwash while parked? (Y)es/(N)o: ";

			cinRef.getline(userEnteredValue, 1000, '\n');

			while (((!(userEnteredValue[0] == 'Y' || userEnteredValue[0] == 'y' || userEnteredValue[0] == 'N' || userEnteredValue[0] == 'n') && ut.strlen(userEnteredValue) == 1)) || (ut.strlen(userEnteredValue) > 1)) {

				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

				userEnteredValue[0] = 0;

				cinRef >> userEnteredValue;
			}
			if (userEnteredValue[0] == 'y' || userEnteredValue[0] == 'Y') {
				m_carwashFlag = true;
			}
			else {
				m_carwashFlag = false;
			}
		}
		return cinRef;
	}

	std::ostream& Car::write(std::ostream& coutRef) const
	{
		if (isEmpty()) {
			coutRef << "Invalid Car Object" << endl;
		}
		else {
			Vehicle::write(coutRef);

			if (isCsv()) {
				coutRef << m_carwashFlag << endl; // chec!!!!!!!!!!!!
			}
			else {
				m_carwashFlag == true ? coutRef << "With Carwash" << endl : coutRef << "Without Carwash" << endl;
			}
		}
		return coutRef;
	}









}