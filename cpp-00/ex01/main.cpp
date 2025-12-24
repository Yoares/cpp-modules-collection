#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break;     
        
        // Handle each command
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else if (std::cin.eof()) {  // Ctrl+D
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}