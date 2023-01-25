//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#include "ReadWritable.h"
namespace sdds {

	ReadWritable::ReadWritable()
	{
		m_csvflag = false;
	}

	ReadWritable::~ReadWritable()
	{
	}

	bool ReadWritable::isCsv() const
	{
		return m_csvflag;
	}

	void ReadWritable::setCsv(bool value)
	{
		m_csvflag = value;
	}

	std::ostream& operator<<(std::ostream& coutRef, const ReadWritable& Obj1)
	{
		Obj1.write(coutRef);
		return coutRef;
	}

	std::istream& operator>>(std::istream& cinRef, ReadWritable& Obj1)
	{
		Obj1.read(cinRef); // ask doubt here!!!!!
		return cinRef;
	}

}