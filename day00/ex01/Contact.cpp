#include "Contact.hpp"

std::string Contact::_fieldName[MAX_CONTACT_FIELD] = {
    "first name",
    "last name",
    "nickname",
    "login",
    "postal address",
    "email",
    "phone number",
    "birthday date",
    "favorite",
    "meal",
    "underwear color",
    "darkest secret"
};

int Contact::findFieldIdByName(std::string s) {

    for (int i = 0; i < MAX_CONTACT_FIELD; i++) {

        if (s.compare(Contact::_fieldName[i]) == 0)
            return i;
    }
    return -1;
}

std::string Contact::findFieldNameById(int i) {

    if (i >= 0 && i < MAX_CONTACT_FIELD)
        return Contact::_fieldName[i];
    return "";
}

void    Contact::setField(int i, std::string s) {

    if (i >= 0 && i < MAX_CONTACT_FIELD) {

        this->_data[i] = s;
    }
}

std::string Contact::getField(int i) {

    if (i >= 0 && i < MAX_CONTACT_FIELD) {

        return this->_data[i];
    }
    return "";
}

void    Contact::display(size_t index, size_t start, size_t end) {

    if (start > end)
        return;
    displayField("1");
    for (int i = 0; i < MAX_CONTACT_FIELD; i++) {

        if (i >= start && i <= end) {

            displayField(this->getField(i));
        }
    }
    std::cout << std::endl;
}

void    Contact::displayHeader(size_t start, size_t end) {

    Contact c;

    if (start > end)
        return;
    
    c.displayField("index");
    for (int i = 0; i < MAX_CONTACT_FIELD; i++) {

        if (i >= start && i <= end) {

            c.displayField(Contact::findFieldNameById(i));
        }
    }
    std::cout << std::endl << std::setw((end - start + 2) * 10 + (end - start + 2)) << std::setfill('-') << '-' << std::endl;
    std::cout << std::endl;
}

void    Contact::displayField(std::string s) {

    if (s.size() > 10)
		std::cout << std::setw(9) << std::setfill('.') << s;
	else
		std::cout << std::setw(10) << std::right << std::setfill(' ') << s;

	std::cout << '|';
}