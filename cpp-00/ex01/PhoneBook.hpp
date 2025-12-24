#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];  // Fixed array of 8 contacts
        int contactCount;     // How many contacts currently stored (0-8)
        int nextIndex;        // Where to add the next contact (0-7)
        std::string truncateString(const std::string& str);
        
    public:
        PhoneBook();          // Constructor
        
        // main methods
        void addContact();    // Handle ADD command
        void searchContact(); // Handle SEARCH command

        // Helper methods (optional)
        void displayContactTable();
        int getValidIndex();
        bool isValidPhone(const std::string& phoneNum);
};
