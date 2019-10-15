#include "Contact.hpp"

Contact    add_call(int *nbContacts)
{
    Contact     contact;
    std::string data;

    std::cout << "Adding new contact..." << std::endl;
    for (int i = 0; i < MAX_CONTACT_FIELD; i++) {

        std::cout << Contact::findFieldNameById(i) << ": ";
        std::getline(std::cin, data);
        if (data == "") {
            std::cout << "Error: Field is invalid. empty" << std::endl;
            i--;
        }
        else {
            contact.setField(i, data);
        }
    }
    return contact;
}

void    search_call(Contact contacts[8], int nbContact)
{
    std::string cmd;
    int         index;

    index = 0;
    Contact::displayHeader(0, 2);
    for (int j = 0; j < nbContact; j++) {

        contacts[j].display(j, 0, 2);
    }
    if (!nbContact)
        return ;
    std::cout << "Select index: ";
    std::getline(std::cin, cmd);
    index = std::stoi(cmd);
    std::cout << index << std::endl;
    if (index > 0 && index <= nbContact)
    {
        for (int i = 0; i < MAX_CONTACT_FIELD; i++) {

            std::cout << Contact::findFieldNameById(i) << ": ";
            std::cout << contacts[index - 1].getField(i);
            std::cout << std::endl;
        }
    }
    else
        std::cout << "No such index in phonebook." << std::endl;
}

int     main()
{
    std::string cmd;
    Contact     contacts[8];
    bool        running = true;
    int         nbContact = 0;

    while (running)
    {
        std::cout << "phonebook: ";
        std::getline(std::cin, cmd);
        if (!std::cin.good())
            return 0;

        if (cmd == "EXIT")
            running = false;
        else if (cmd == "ADD" && nbContact < 8) {

            contacts[nbContact] = add_call(&nbContact);
            nbContact++;
        }
        else if (cmd == "ADD" && nbContact >= 8) {

            std::cout << "Contacts are full, can't add more contact." << std::endl;
        }
        else if (cmd == "SEARCH")
            search_call(contacts, nbContact);
        else
            std::cout << "No such command." << std::endl;
    }
    return 0;
}