# C++ - Module 00
## Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff

**Summary:** This document contains the exercises of Module 00 from C++ modules.

**Version:** 11.0

---

## Table of Contents

| Chapter | Title |
|---------|-------|
| I | [Introduction](#chapter-i-introduction) |
| II | [General Rules](#chapter-ii-general-rules) |
| III | [AI Instructions](#chapter-iii-ai-instructions) |
| IV | [Exercise 00: Megaphone](#chapter-iv-exercise-00-megaphone) |
| V | [Exercise 01: My Awesome PhoneBook](#chapter-v-exercise-01-my-awesome-phonebook) |
| VI | [Exercise 02: The Job Of Your Dreams](#chapter-vi-exercise-02-the-job-of-your-dreams) |
| VII | [Submission and peer-evaluation](#chapter-vii-submission-and-peer-evaluation) |

---

## Chapter I: Introduction

C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes" (source: Wikipedia).

The goal of these modules is to introduce you to **Object-Oriented Programming**. This will be the starting point of your C++ journey. Many languages are recommended for learning OOP. We decided to choose C++ since it's derived from your old friend C.

Since C++ is a complex language, and in order to keep things simple, your code will follow the **C++98 standard**.

We are aware modern C++ is way different in a lot of aspects. So if you want to become a proficient C++ developer, it's up to you to go further after the 42 Common Core!

You will discover new concepts step-by-step. The exercises will progressively increase in complexity.

---

## Chapter II: General Rules

### Compiling
- Compile your code with `c++` and the flags `-Wall -Wextra -Werror`
- Your code should still compile if you add the flag `-std=c++98`

### Formatting and naming conventions
- The exercise directories will be named this way: `ex00`, `ex01`, ..., `exn`
- Write class names in **UpperCamelCase** format
- Files containing class code will always be named according to the class name
  - Example: `ClassName.hpp`, `ClassName.cpp`
- Every output message must end with a newline character

### Allowed/Forbidden
- You are allowed to use almost everything from the standard library
- However, you can't use any other external library
- C++11 (and derived forms) and Boost libraries are **forbidden**
- The following functions are forbidden: `*printf()`, `*alloc()` and `free()`
- `using namespace <ns_name>` and `friend` keywords are **forbidden**
- You are allowed to use the STL **only in Modules 08 and 09**

### A few design requirements
- Avoid **memory leaks** when you allocate memory (using the `new` keyword)
- From Module 02 to Module 09, your classes must be designed in the **Orthodox Canonical Form**
- Any function implementation put in a header file (except for function templates) means **0 to the exercise**
- You must avoid the problem of double inclusion by adding **include guards**

> **Note:** You will have to implement a lot of classes. This can seem tedious, unless you're able to script your favorite text editor.

---

## Chapter III: AI Instructions

### Context
This project is designed to help you discover the fundamental building blocks of your ICT training. To properly anchor key knowledge and skills, it's essential to adopt a thoughtful approach to using AI tools and support.

### Main message
- ☛ Build strong foundations without shortcuts
- ☛ Really develop tech & power skills
- ☛ Experience real peer-learning, start learning how to learn and solve new problems
- ☛ The learning journey is more important than the result

### Learner rules
- Apply reasoning to your assigned tasks, especially before turning to AI
- Do not ask for direct answers to the AI
- Learn about 42 global approach on AI

> **Remember:** During exams, AI is not available — no internet, no smartphones, etc. You'll quickly realize if you've relied too heavily on AI in your learning process.

---

## Chapter IV: Exercise 00: Megaphone

### Exercise Requirements

**Turn-in directory:** `ex00/`  
**Files to turn in:** `Makefile`, `megaphone.cpp`  
**Forbidden functions:** None

Write a program that converts command-line arguments to uppercase:

```bash
$> ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$> ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$> ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

### Key Concepts

This introductory exercise teaches:
- **C++ I/O streams**: Using `std::cout` instead of `printf()`
- **String manipulation**: Working with `std::string` class
- **Command-line arguments**: Accessing `argc` and `argv`
- **C++ standard library functions**: Using `std::toupper()`

### My Solution Approach

```cpp
#include <iostream>
#include <string>

int main(int ac, char *av[])
{
    // No arguments - print default message
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return 0;
    }
    
    // Process each argument
    if (ac >= 2)
    {
        for(int i = 1; i < ac; i++)
        {
            // Convert each character to uppercase
            for(unsigned int j = 0; j < std::string(av[i]).length(); j++){
                std::cout << (char)std::toupper(av[i][j]);
            }
        }
    }
    std::cout << std::endl;
    return (0);
}
```

### Implementation Details

1. **Default behavior**: When no arguments are provided, print the "FEEDBACK NOISE" message
2. **Argument iteration**: Loop through all command-line arguments (starting from `av[1]`)
3. **Character conversion**: Use `std::toupper()` to convert each character
4. **C++ style**: Using `std::cout` and `std::string` instead of C functions

### Learning Outcomes
- First taste of C++ syntax vs C
- Understanding C++ streams (`std::cout`)
- Working with the `std::string` class
- Using standard library algorithms (`std::toupper`)

---

## Chapter V: Exercise 01: My Awesome PhoneBook

### Exercise Requirements

**Turn-in directory:** `ex01/`  
**Files to turn in:** `Makefile`, `*.cpp`, `*.{h, hpp}`  
**Forbidden functions:** None

Create a phonebook program with two classes:
- **PhoneBook**: Stores up to 8 contacts (replaces oldest when full)
- **Contact**: Represents a single contact

The program accepts three commands:
- **ADD**: Add a new contact
- **SEARCH**: Display and search contacts
- **EXIT**: Quit the program

### Key Concepts

This exercise introduces fundamental OOP concepts:
- **Classes and Objects**: First real class implementation
- **Encapsulation**: Private vs public members
- **Member functions**: Methods that operate on class data
- **Data validation**: Input checking and error handling
- **Formatted output**: Using `std::iomanip` for table formatting
- **Fixed-size arrays**: No dynamic allocation allowed
- **Circular buffer**: Replacing oldest entry when full

### My Solution Architecture

#### Contact Class

```cpp
class Contact {
private:
    std::string firstName;
    std::string lastName; 
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    
public:
    Contact();
    
    // Setters
    void setfirstname(std::string name);   
    void setlastname(std::string name);
    void setnickname(std::string name);
    void setphonenum(std::string num);
    void setdarkestsecret(std::string secret);
    
    // Getters
    std::string getfirstname();
    std::string getlastname();
    std::string getnickname();
    std::string getphonenum();
    std::string getdarkestsecret();
};
```

**Design Decisions:**
- **Private attributes**: Data is hidden from outside access (encapsulation)
- **Public getters/setters**: Controlled access to private data
- **String storage**: All fields stored as `std::string` for flexibility

#### PhoneBook Class

```cpp
class PhoneBook {
private:
    Contact contacts[8];    // Fixed array of 8 contacts
    int contactCount;       // Current number of contacts (0-8)
    int nextIndex;          // Index for next contact (circular buffer)
    
    // Private helper methods
    std::string truncateString(const std::string& str);
    bool isValidPhone(const std::string& phoneNum);
    
public:
    PhoneBook();
    
    // Main operations
    void addContact();
    void searchContact();
    
    // Helper methods
    void displayContactTable();
    int getValidIndex();
};
```

**Design Decisions:**
- **Fixed array**: `Contact contacts[8]` - no dynamic allocation
- **Circular buffer logic**: `nextIndex` tracks where to add next contact
- **Private helpers**: Utility functions hidden from main program
- **Initialization list**: Constructor initializes `contactCount(0), nextIndex(0)`

### Implementation Highlights

#### 1. Adding Contacts (with validation)

```cpp
void PhoneBook::addContact() {
    Contact newContact;
    std::string input;
    
    // Validate each field - no empty inputs allowed
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
    
    // Similar validation for other fields...
    
    // Add to circular buffer
    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;  // Wrap around after 8
    if (contactCount < 8)
        contactCount++;
}
```

**Key Points:**
- Input validation prevents empty fields
- EOF handling (`std::cin` check)
- Circular buffer: `nextIndex = (nextIndex + 1) % 8`
- Tracks actual contact count vs array size

#### 2. Phone Number Validation

```cpp
bool PhoneBook::isValidPhone(const std::string& phoneNum) {
    if (phoneNum.empty())
        return false;
        
    bool hasdigit = false;
    
    for (size_t i = 0; i < phoneNum.length(); i++) {
        char c = phoneNum[i];
        
        if (!std::isdigit(c) && c != ' ')
            return false;
            
        if (std::isdigit(c))
            hasdigit = true;
    }
    return hasdigit;
}
```

**Validation Rules:**
- Must contain at least one digit
- Only digits and spaces allowed
- Prevents empty or invalid inputs

#### 3. Formatted Display with iomanip

```cpp
std::string PhoneBook::truncateString(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayContactTable() {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
              
    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateString(contacts[i].getfirstname()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getlastname()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getnickname()) 
                  << std::endl;
    }
}
```

**Formatting Features:**
- `std::setw(10)`: Sets column width to 10 characters
- Right-aligned by default
- Truncation with dot if longer than 10 chars
- Pipe separators (`|`) between columns

#### 4. Main Program Loop

```cpp
int main() {
    PhoneBook phonebook;
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break;
            
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}
```

### Learning Outcomes

1. **Class Design**: Separating data (Contact) from operations (PhoneBook)
2. **Encapsulation**: Private data with public interfaces
3. **Constructors**: Initializing objects with default values
4. **Member Functions**: Methods operating on class data
5. **Input Validation**: Robust error checking
6. **Formatted I/O**: Using `<iomanip>` for table display
7. **Static Arrays**: Fixed-size storage without dynamic allocation
8. **Circular Buffer**: Efficient oldest-entry replacement

---

## Chapter VI: Exercise 02: The Job Of Your Dreams

### Exercise Requirements

**Turn-in directory:** `ex02/`  
**Files to turn in:** `Makefile`, `Account.cpp`, `Account.hpp`, `tests.cpp`  
**Forbidden functions:** None

Recreate the missing `Account.cpp` file based on:
- The header file `Account.hpp`
- A log file showing expected output
- The test file `tests.cpp`

### Key Concepts

This exercise teaches advanced OOP concepts:
- **Static members**: Class-level variables shared by all instances
- **Static methods**: Functions that work on static data
- **Private static variables**: Global class state
- **Initialization**: Understanding static variable initialization
- **Timestamps**: Working with C time functions
- **Reverse engineering**: Reading requirements from output logs

### Understanding Static Members

#### What are Static Members?

Static members belong to the **class itself**, not to individual objects:
- **One copy** shared by all instances
- Exist even before any objects are created
- Accessed via class name or any instance

```cpp
class Account {
private:
    // Instance variables (each object has its own)
    int _accountIndex;
    int _amount;
    int _nbDeposits;
    int _nbWithdrawals;
    
    // Static variables (shared by ALL accounts)
    static int _nbAccounts;
    static int _totalAmount;
    static int _totalNbDeposits;
    static int _totalNbWithdrawals;
};
```

### My Solution Approach

#### 1. Static Member Initialization

```cpp
// MUST be initialized outside the class in .cpp file
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
```

**Important Rules:**
- Static members are declared in `.hpp`
- Static members are **defined and initialized** in `.cpp`
- They exist before any objects are created
- Shared across all instances

#### 2. Constructor Implementation

```cpp
Account::Account(int initial_deposit)
{
    // Assign unique index to this account
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;  // Increment total count
    
    // Initialize instance variables
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    
    // Update global totals
    Account::_totalAmount += initial_deposit;
    
    // Log creation
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}
```

**Constructor Tasks:**
1. Assign unique index (using static counter)
2. Initialize instance variables
3. Update static/global totals
4. Display creation log with timestamp

#### 3. Timestamp Generation

```cpp
void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);        // Get current time
    std::tm *ptm = std::localtime(&now);      // Convert to struct
    
    std::cout << '['
              << (ptm->tm_year + 1900)        // Year (tm_year is since 1900)
              << std::setfill('0') << std::setw(2) << (ptm->tm_mon + 1)  // Month
              << std::setw(2) << ptm->tm_mday   // Day
              << '_'
              << std::setw(2) << ptm->tm_hour   // Hour
              << std::setw(2) << ptm->tm_min    // Minute
              << std::setw(2) << ptm->tm_sec    // Second
              << "] ";
}
```

**Time Formatting:**
- Uses `<ctime>` and `<iomanip>` headers
- Format: `[YYYYMMDD_HHMMSS]`
- `std::setfill('0')`: Pads with zeros
- `std::setw(2)`: Sets width to 2 digits

#### 4. Static Getter Methods

```cpp
int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }
```

**Why Static Methods?**
- Can be called without an instance: `Account::getNbAccounts()`
- Access static members directly
- Provide class-level information

#### 5. Display Global Information

```cpp
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}
```

**Purpose:**
- Show global statistics across all accounts
- Called as class method: `Account::displayAccountsInfos()`
- Demonstrates static method usage

#### 6. Destructor

```cpp
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
}
```

**Notes:**
- Destructor order may vary by compiler
- Updates instance variables, not static (accounts already closed)
- Logs account closure

### Understanding the Log File

The log file shows expected output format:
```
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
```

**What to analyze:**
- Timestamp format
- Output message structure
- Order of operations
- How static vs instance data is displayed

### Learning Outcomes

1. **Static Members**: Understanding class-level vs instance-level data
2. **Static Initialization**: How to properly initialize static variables
3. **Static Methods**: Functions that operate on class data
4. **Time Manipulation**: Using `<ctime>` for timestamps
5. **Formatting**: Advanced output formatting with `<iomanip>`
6. **Reverse Engineering**: Deducing implementation from requirements
7. **Const Correctness**: Using `const` for methods that don't modify state
8. **Scope Resolution**: Using `::` operator for static members

### The Difference: Static vs Instance

| Feature | Instance Members | Static Members |
|---------|-----------------|----------------|
| **Ownership** | Each object has its own copy | One copy shared by all objects |
| **Access** | Through object: `obj.member` | Through class: `Class::member` |
| **Creation** | Created with each object | Created once, before any objects |
| **Usage** | Object-specific data | Class-wide information |
| **Example** | `_amount` (each account's balance) | `_nbAccounts` (total number of accounts) |

---

## Chapter VII: Submission and peer-evaluation

Submit your assignment to your Git repository as usual. Only the work inside your repository will be evaluated during the defense. Don't hesitate to double-check the names of your files to ensure they are correct.

During the evaluation, you may be asked to make brief modifications to verify your understanding. This could involve:
- A minor behavior change
- Writing or rewriting a few lines of code
- Adding an easy feature

**Note:** Completing exercise 02 is **not mandatory** to pass this module.

---

## Key Takeaways from Module 00

### C++ Fundamentals Learned

1. **Goodbye C, Hello C++**
   - `std::cout` instead of `printf()`
   - `std::string` instead of `char*`
   - `std::getline()` instead of `gets()` or `scanf()`

2. **Object-Oriented Programming Basics**
   - Classes and objects
   - Public vs private members
   - Constructors and destructors
   - Member functions (methods)
   - Encapsulation principles

3. **Advanced Concepts**
   - Static members and methods
   - Const correctness
   - Initialization lists
   - Formatted I/O with `<iomanip>`

4. **Best Practices**
   - Input validation
   - Error handling
   - Clean separation of concerns
   - Proper encapsulation

### Compilation

All exercises compile with:
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```

Or use the provided Makefiles:
```bash
make
```

---

## Resources

- [cplusplus.com/reference/string](http://www.cplusplus.com/reference/string/string/)
- [cplusplus.com/reference/iomanip](http://www.cplusplus.com/reference/iomanip/)

---

**Good luck with your C++ journey! 🚀**
