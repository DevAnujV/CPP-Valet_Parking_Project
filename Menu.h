//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022



#ifndef SDDS_MENU_H
#define SDDS_MENU_H


#include <iostream>

namespace sdds {

	class MenuItems {
		friend class Parking;
		int m_indentation{};
		char m_title[100]{};
		char m_menuTitle[6][100]{};
		int m_itemCount = 0;
		MenuItems(int indent, const char* title, const char* name);
		void displayParkingMenu()const;
	};
}

#endif // !SDDS_MENUITEM_H
