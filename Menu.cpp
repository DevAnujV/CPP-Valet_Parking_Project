//I have done all the coding by myself and only copied the code that my professor provided to complete my project milestones.
// Name - Anuj Verma
// Student Number - 180483216
// Student email - averma100@myseneca.ca
// Date Completed - 12/08/2022


#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds {

	MenuItems::MenuItems(int indent, const char* title, const char* name) {

		m_indentation = indent;

		if (title && title[0] && m_menuTitle && m_menuTitle[0]) {

			ut.strcpy(m_title, title);
			int count = 0;
			bool endit = false;
			int j;

			for (int i = 0; endit == false; i++) {
				for (j = 0; name[count] != ',' && name[count] != '.'; j++) {
					m_menuTitle[i][j] = name[count];
					count++;
				}
				if (name[count] == '.') {
					endit = true;
				}
				count++;
				m_itemCount++;
				m_menuTitle[i][j] = '\0';
			}
		}
	}

	void MenuItems::displayParkingMenu() const
	{
		char indent[4 + 1]{};
		if (m_indentation == 0) {
			ut.strcpy(indent, "");
		}
		else if (m_indentation == 1) {
			ut.strcpy(indent, "    ");
		}
		cout << indent << m_title << endl;
		for (int i = 0; i < this->m_itemCount; i++) {
			cout << indent << i + 1 << "- " << m_menuTitle[i] << endl;
		}
		cout << indent << "> ";
	}



}