//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#include "Motorcycle.h"
#include "Utils.h"
#include <iostream>

using namespace std;
namespace sdds {

	Motorcycle::Motorcycle() : Vehicle()
	{

	}

	Motorcycle::Motorcycle(char* licPlate, char* makeAndModel) :Vehicle(licPlate, makeAndModel)
	{

	}

	Motorcycle::Motorcycle(const Motorcycle& M)
	{
		m_hasSideCar = M.m_hasSideCar;
		Vehicle::operator=(M); // caling to the assignment of vehcile class to take care of it.
	}

	Motorcycle& Motorcycle::operator=(const Motorcycle& M)
	{
		if (this != &M) {
			m_hasSideCar = M.m_hasSideCar;
			Vehicle::operator=(M); // caling to the assignment of vehcile class to take care
		}
		return *this;
	}

	Motorcycle::~Motorcycle()
	{

	}

	std::ostream& Motorcycle::writeType(std::ostream& OS) const
	{
		if (isCsv()) {
			OS << "M,";
		}
		else {
			OS << "Vehicle type: Motorcycle" << endl;
		}
		return OS;
	}

	std::istream& Motorcycle::read(std::istream& cinRef)
	{
		char userEnteredValue[1000];

		if (isCsv()) {
			Vehicle::read(cinRef);

			cinRef >> m_hasSideCar;
			cinRef.ignore(10000, '\n');
		}
		else {
			cout << endl << "Motorcycle information entry" << endl;
			Vehicle::read(cinRef);

			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

			cinRef.getline(userEnteredValue, 1000, '\n');


			while (((!(userEnteredValue[0] == 'Y' || userEnteredValue[0] == 'y' || userEnteredValue[0] == 'N' || userEnteredValue[0] == 'n') && ut.strlen(userEnteredValue) == 1)) || (ut.strlen(userEnteredValue) > 1)) {

				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

				userEnteredValue[0] = 0;

				cinRef >> userEnteredValue;
			}
			if (userEnteredValue[0] == 'y' || userEnteredValue[0] == 'Y') {
				m_hasSideCar = true;
			}
			else {
				m_hasSideCar = false;
			}

		}
		return cinRef;
	}

	std::ostream& Motorcycle::write(std::ostream& coutRef) const
	{
		if (isEmpty()) {
			coutRef << "Invalid Motorcycle Object" << endl;
		}
		else {
			Vehicle::write(coutRef);

			if (isCsv()) {
				coutRef << m_hasSideCar << endl; // chec!!!!!!!!!!!!
			}
			else {
				if (m_hasSideCar) coutRef << "With Sidecar" << endl;
			}
		}
		return coutRef;
	}









}