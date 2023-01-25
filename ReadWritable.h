//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#ifndef SDDS_READWRITEABLE_H
#define SDDS_READWRITEABLE_H

#include <iostream>

namespace sdds {
	class ReadWritable {

		bool m_csvflag;

	protected:
		bool isCsv()const;

	public:

		ReadWritable();
		void setCsv(bool value);
		virtual std::istream& read(std::istream& cinRef) = 0;
		virtual std::ostream& write(std::ostream& coutRef)const = 0;
		virtual ~ReadWritable();

	};

	std::ostream& operator<<(std::ostream& coutRef, const ReadWritable& Obj1);
	std::istream& operator>>(std::istream& cinRef, ReadWritable& Obj1);
}

#endif // !SDDS_READWRITEABLE_H
