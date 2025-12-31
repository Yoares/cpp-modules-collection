# C++ Module 01 - Memory Allocation, Pointers to Members, References and Switch Statements

## Overview
This module introduces fundamental concepts of memory management in C++, including:
- Dynamic memory allocation (heap vs stack)
- Pointers and references
- Memory leaks prevention
- Pointers to member functions
- Switch statements

## Table of Contents
- [Exercise 00: BraiiiiiiinnnzzzZ](#exercise-00-braiiiiiiinnnzzzz)
- [Exercise 01: Moar brainz!](#exercise-01-moar-brainz)
- [Exercise 02: HI THIS IS BRAIN](#exercise-02-hi-this-is-brain)
- [Exercise 03: Unnecessary violence](#exercise-03-unnecessary-violence)
- [Exercise 04: Sed is for losers](#exercise-04-sed-is-for-losers)
- [Exercise 05: Harl 2.0](#exercise-05-harl-20)
- [Exercise 06: Harl filter](#exercise-06-harl-filter)

---

## Exercise 00: BraiiiiiiinnnzzzZ

### Subject
Create a `Zombie` class with:
- A private `name` attribute
- An `announce()` function that prints: `<name>: BraiiiiiiinnnzzzZ...`
- Two functions:
  - `Zombie* newZombie(std::string name)` - creates a zombie on the heap
  - `void randomChump(std::string name)` - creates a zombie on the stack

### Key Concept: Stack vs Heap Allocation
The main goal is understanding **when to use stack vs heap allocation**:
- **Stack allocation** (automatic): For objects with limited scope (local variables)
- **Heap allocation** (dynamic): For objects that need to persist beyond their creation scope

### My Solution

**Zombie Class:**
```cpp
class Zombie {
private:
    std::string name;
public:
    Zombie(std::string n);
    ~Zombie();
    void announce() const;
};
```

**Key Implementation Details:**
- `newZombie()`: Allocates on the heap using `new`, returns a pointer so the zombie can be used outside the function scope
- `randomChump()`: Creates a zombie on the stack, announces itself, and is automatically destroyed when the function exits
- Destructor prints destruction message for debugging memory management

**When to use each:**
- Use `newZombie()` (heap) when you need the zombie to live beyond the function call
- Use `randomChump()` (stack) when you need a temporary zombie that's only used within the function

---

## Exercise 01: Moar brainz!

### Subject
Implement `Zombie* zombieHorde(int N, std::string name)` that:
- Allocates N Zombie objects in a **single allocation**
- Initializes each zombie with the given name
- Returns a pointer to the first zombie

### Key Concept: Array Allocation
This exercise teaches dynamic array allocation using `new[]` and proper deallocation with `delete[]`.

### My Solution

```cpp
Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for(int i = 0; i < N; i++) {
        horde[i].set_name(name);
    }
    return horde;
}
```

**Important Points:**
- Single allocation: `new Zombie[N]` allocates all zombies at once
- Must use `delete[]` (not `delete`) to deallocate the array
- Each zombie in the array needs to be initialized after allocation
- Proper cleanup prevents memory leaks

---

## Exercise 02: HI THIS IS BRAIN

### Subject
Demonstrate the relationship between pointers and references by:
- Creating a string variable
- Creating a pointer to the string
- Creating a reference to the string
- Printing memory addresses and values

### Key Concept: Understanding References
References are **aliases** to existing variables - they're essentially pointers with different syntax that:
- Cannot be null
- Cannot be reassigned
- Must be initialized at declaration
- Automatically dereference

### My Solution

```cpp
std::string str = "HI THIS IS BRAIN";
std::string* stringPTR = &str;
std::string& stringREF = str;

// Memory addresses (all identical)
std::cout << &str << "\n";
std::cout << stringPTR << "\n";
std::cout << &stringREF << "\n";

// Values (all show the string content)
std::cout << str << "\n";
std::cout << *stringPTR << "\n";
std::cout << stringREF << "\n";
```

**Takeaway:**
- All three refer to the same memory location
- References provide cleaner syntax than pointers for address manipulation
- References are safer as they can't be null and can't be reassigned

---

## Exercise 03: Unnecessary violence

### Subject
Create a `Weapon` class and two human classes (`HumanA` and `HumanB`) that:
- Have different relationships with weapons
- `HumanA`: Always has a weapon (passed in constructor)
- `HumanB`: May not have a weapon initially

### Key Concept: References vs Pointers
This exercise demonstrates **when to use references vs pointers**:
- **References**: When the object must always exist (can't be null)
- **Pointers**: When the object is optional (can be null)

### My Solution

**Weapon Class:**
```cpp
class Weapon {
private:
    std::string type;
public:
    const std::string& getType() const;
    void setType(const std::string& new_type);
};
```

**HumanA (always armed - uses reference):**
```cpp
class HumanA {
private:
    std::string name;
    Weapon& weapon;  // Reference: always has a weapon
public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};
```

**HumanB (optionally armed - uses pointer):**
```cpp
class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Pointer: can be null initially
public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};
```

**Why These Choices:**
- `HumanA` uses a **reference** because it MUST have a weapon at construction and keeps it
- `HumanB` uses a **pointer** because it may start without a weapon (null is valid)
- The `getType()` returns a const reference to avoid unnecessary string copying

---

## Exercise 04: Sed is for losers

### Subject
Create a program that:
- Takes 3 parameters: filename, s1 (search string), s2 (replacement)
- Reads the file content
- Replaces all occurrences of s1 with s2
- Writes to `<filename>.replace`
- Cannot use `std::string::replace()`

### Key Concept: File I/O and String Manipulation
Learn file handling with C++ streams and manual string replacement.

### My Solution

```cpp
// Read entire file
std::ifstream infile(filename.c_str());
std::string content;
std::string line;
while (getline(infile, line, '\n')) {
    content.append(line);
    if (!infile.eof())
        content += "\n";
}

// Replace all occurrences
size_t pos = 0;
size_t match = 0;
std::string output;
while ((match = content.find(s1, pos)) != std::string::npos) {
    output += content.substr(pos, match - pos);
    output += s2;
    pos = match + s1.length();
}
output += content.substr(pos);

// Write to output file
std::ofstream outfile(filename + ".replace");
outfile << output;
```

**Key Features:**
- Error handling for file operations
- Validation that s1 is not empty
- Preserves line breaks
- Handles multiple occurrences of s1
- Uses C++98 compatible file operations

---

## Exercise 05: Harl 2.0

### Subject
Create a `Harl` class that:
- Has four private member functions: `debug()`, `info()`, `warning()`, `error()`
- Has a public `complain(std::string level)` function
- Uses **pointers to member functions** (no if/else forest)

### Key Concept: Pointers to Member Functions
This exercise introduces function pointers to avoid repetitive conditional logic.

### Solution Approach

```cpp
class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    void complain(std::string level);
};
```

**Implementation Strategy:**
```cpp
void Harl::complain(std::string level) {
    // Array of function pointers
    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }
}
```

**Benefits:**
- Cleaner code without multiple if/else statements
- Easier to extend with new complaint levels
- Demonstrates C++ member function pointers syntax

---

## Exercise 06: Harl filter

### Subject
Create a program that:
- Takes a log level as parameter
- Displays messages from that level and above
- Uses a **switch statement**

### Key Concept: Switch Statements with Fall-through
Learn to use switch statements and intentional fall-through behavior.

### Solution Approach

```cpp
void filterComplaints(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int levelIndex = -1;
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            levelIndex = i;
            break;
        }
    }
    
    switch (levelIndex) {
        case 0:
            std::cout << "[DEBUG]" << std::endl;
            harl.complain("DEBUG");
            // Fall through
        case 1:
            std::cout << "[INFO]" << std::endl;
            harl.complain("INFO");
            // Fall through
        case 2:
            std::cout << "[WARNING]" << std::endl;
            harl.complain("WARNING");
            // Fall through
        case 3:
            std::cout << "[ERROR]" << std::endl;
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
```

**Key Points:**
- Intentional fall-through shows messages from specified level and above
- Switch statement is more efficient than multiple if statements for this use case
- Default case handles invalid input

---

## Key Takeaways from Module 01

1. **Memory Management:**
   - Stack: automatic, fast, limited scope
   - Heap: manual, flexible, requires cleanup with `delete`/`delete[]`

2. **References vs Pointers:**
   - References: safer, can't be null, can't be reassigned
   - Pointers: flexible, can be null, can be reassigned

3. **When to Use What:**
   - Use references for mandatory relationships
   - Use pointers for optional relationships
   - Use stack allocation for temporary objects
   - Use heap allocation for persistent objects

4. **Advanced Features:**
   - Pointers to member functions for cleaner code
   - Switch statements for efficient multi-way branching

## Compilation
All exercises use:
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```

Or simply use the provided Makefiles:
```bash
make
```