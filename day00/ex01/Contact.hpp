#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

# define MAX_CONTACT_FIELD 12

class Contact {

    public:

        void                    display(size_t index, size_t start, size_t end);
        void                    displayField(std::string s);

        void                    setField(int i, std::string s);
        std::string             getField(int i);

        static int              findFieldIdByName(std::string s);
        static std::string      findFieldNameById(int i);
        static void             displayHeader(size_t start, size_t end);


    private:

        static std::string      _fieldName[MAX_CONTACT_FIELD];
        std::string             _data[MAX_CONTACT_FIELD];
};

#endif