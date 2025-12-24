#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

std::string PhoneBook::truncateString(const std::string& str){
    if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}

bool PhoneBook::isValidPhone(const std::string& phoneNum){
	if (phoneNum.empty())
		return false;

	bool hasdigit = false;

	for (size_t i = 0; i < phoneNum.length() ; i++){
		char c = phoneNum[i];

		if (!std::isdigit(c) && c != ' ')
			return false;

		if (std::isdigit(c))
            hasdigit = true;
	}
	return (hasdigit);
}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;
    
    // Get First Name
    while (true) {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input))
            return;

        if (!input.empty() && input.find_first_not_of(" \t") != std::string::npos) {
            newContact.setfirstname(input);
            break;
        }
        std::cout << "First name cannot be empty!" << std::endl;
    }
    
    while (true) {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input))
            return;
        if (!input.empty() && input.find_first_not_of(" \t") != std::string::npos) {
            newContact.setlastname(input);
            break;
        }
        std::cout << "Last name cannot be empty!" << std::endl;
    }

    while (true) {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, input))
            return;
        if (!input.empty() && input.find_first_not_of(" \t") != std::string::npos) {
            newContact.setnickname(input);
            break;
        }
        std::cout << "Nickname cannot be empty!" << std::endl;
    }
    
    while (true) {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input))
            return;
        if (isValidPhone(input)) {
            newContact.setphonenum(input);
            break;
        }
        std::cout << "Invalid phone number! Use only digits and spaces." << std::endl;
    }
    
    // Get Darkest Secret (same pattern as names)
    while (true) {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input))
            return;
        if (!input.empty() && input.find_first_not_of(" \t") != std::string::npos) {
            newContact.setdarkestsecret(input);
            break;
        }
        std::cout << "Darkest secret cannot be empty!" << std::endl;
    }
    
    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8; // Wrap around after 8
    
    if (contactCount < 8)
        contactCount++;
    
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContactTable(){
    // Print header
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    
    // Print separator line (optional but nice)
    std::cout << std::string(43, '-') << std::endl;
    
    // Print each contact
    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateString(contacts[i].getfirstname()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getlastname()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getnickname()) << std::endl;
    }
}

int	PhoneBook::getValidIndex(){
	std::string input;
	int index;

	while(true){
		std::cout << "Enter index: ";
		if (!std::getline(std::cin, input))
            return -1; // EOF

		bool isNum = true;
		if (input.empty())
			isNum = false;

		for (size_t i = 0; i < input.length(); i++){
			if (!std::isdigit(input[i])){
				isNum = false;
				break;
			}
		}

		if (isNum == false){
			std::cout << "Invalid input! Enter a number." << std::endl;
            continue;
		}

		std::stringstream ss(input);
        ss >> index;
		
		if (index >= 0 && index < contactCount)
			return index;
		
		std::cout << "Index out of range! (0-" << (contactCount - 1) << ")" << std::endl;
	}
}

void PhoneBook::searchContact() {

	if (contactCount == 0){
		std::cout << "Phonebook is empty!" << std::endl;
        return;
	}

	displayContactTable();
	int index = getValidIndex();

	if (index == -1)
		return ;

	std::cout << "\n--- Contact Details ---" << std::endl;
    std::cout << "First Name: " << contacts[index].getfirstname() << std::endl;
    std::cout << "Last Name: " << contacts[index].getlastname() << std::endl;
    std::cout << "Nickname: " << contacts[index].getnickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getphonenum() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getdarkestsecret() << std::endl;
}