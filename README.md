# 42 C++ Piscine: From C Programmer to Object-Oriented Architect
## Modules 00–04: A Journey Through Modern C++

---

## 🚀 Executive Summary

This repository documents a comprehensive learning journey through **Object-Oriented Programming in C++**, following the rigorous curriculum of **42 School**. Starting from basic procedural thinking and gradually ascending to advanced architectural patterns, these five modules represent a **complete transformation** from a C programmer into an architect capable of designing robust, maintainable C++ systems.

**What makes this collection special:**
- ✅ **Strict C++98 compliance** – No modern shortcuts, pure fundamentals
- ✅ **Zero memory leaks** – Rigorous RAII principles applied throughout
- ✅ **From syntax to architecture** – Each module unlocks the next layer of understanding
- ✅ **Real-world patterns** – Orthodox Canonical Form, virtual inheritance, abstract interfaces

---

## 📋 The Progression Map

| Module | Theme | Core Achievement | Status |
|--------|-------|------------------|--------|
| **00** | The Basics | Classes, Namespaces, Leaving C Behind | ✅ |
| **01** | Memory & Logic | Pointers, References, Memory Management | ✅ |
| **02** | Ad-hoc Polymorphism | Operator Overloading, Fixed-Point Arithmetic | ✅ |
| **03** | Inheritance | Protected Members, Construction Chains | ✅ |
| **04** | Subtype Polymorphism | Virtual Functions, Abstract Classes, Interfaces | ✅ |

---

## 🎓 Module Deep Dives

---

## **Module 00: The Basics**
### *Namespaces, Classes, Member Functions, Streams*

#### The Paradigm Shift

This module marks the **departure from procedural C**. You're not just adding new syntax—you're adopting a fundamentally different way of thinking:
- Functions become **methods** (tied to objects)
- Data becomes **attributes** (encapsulated within classes)
- Output becomes a **stream** (`std::cout` instead of `printf`)

#### Core Concept: Encapsulation

**Encapsulation** is the bedrock of OOP. Data and behavior are bundled together, with access controlled through visibility modifiers:

```cpp
class Contact {
private:                    // Hidden from outside
    std::string firstName;
    std::string phoneNumber;
    
public:                     // Exposed interface
    Contact(std::string name);
    void display() const;
};
```

#### Key Insight: Why Classes Matter More Than You Think

Many programmers see classes as "just a way to organize code." But they're actually a **contract**. When you write `class Contact`, you're saying: "Here's an interface. You don't need to know *how* I store data—just use these public methods." This boundary enables:

- **Maintainability**: Change internals without breaking client code
- **Correctness**: Validation happens once, inside the class
- **Reusability**: The class is a self-contained, understandable unit

#### Key Code Snippet: The PhoneBook Pattern

```cpp
// PhoneBook.hpp - Circular buffer for fixed-size storage
class PhoneBook {
private:
    Contact contacts[8];       // Fixed array (no dynamic allocation)
    int nextIndex;             // Circular index
    
public:
    PhoneBook() : nextIndex(0) {}
    
    void addContact(const Contact& c) {
        contacts[nextIndex] = c;
        nextIndex = (nextIndex + 1) % 8;  // Wrap around
    }
};
```

**Why this matters**: You learn that C++ doesn't force you to use `new`/`delete`. Stack allocation, when possible, is simpler and safer.

#### Exercises Overview

| Exercise | Focus | Lesson |
|----------|-------|--------|
| **Ex00: Megaphone** | String manipulation, `std::cout` | Say goodbye to `printf()` |
| **Ex01: PhoneBook** | Classes, encapsulation, I/O | Design your first real class |
| **Ex02: Account** | Static members, initialization lists | Class-level data and timestamps |

#### Compilation

```bash
cd cpp-00 && make
```

---

## **Module 01: Memory & Logic**
### *Pointers, References, Memory Allocation, Switch Statements*

#### The Critical Insight: References vs Pointers

After learning pointers in C, newcomers often ask: "Why would I ever use a reference?" The answer is **safety and clarity**:

| Feature | Pointer | Reference |
|---------|---------|-----------|
| **Can be null?** | Yes | ❌ No |
| **Can be reassigned?** | Yes | ❌ No |
| **Automatically dereferenced?** | ❌ No | Yes |
| **When to use** | Optional relationships | Mandatory relationships |

**The wisdom:** If your function requires an object to exist, take a `reference`. If it's optional, take a `pointer`. This simple rule prevents entire categories of bugs.

```cpp
// WRONG: What if weapon is null?
class HumanB {
private:
    Weapon* weapon;  // Could be nullptr
};

// RIGHT: weapon MUST exist
class HumanA {
private:
    Weapon& weapon;  // Cannot be null, cannot be reassigned
};
```

#### Core Concept: Stack vs Heap Allocation

Module 01 forces you to confront a fundamental decision: **Where does this object live?**

- **Stack**: Automatic, scoped, limited lifetime (`Zombie z("Mike");`)
- **Heap**: Manual, explicit, can escape function scope (`Zombie* z = new Zombie("Mike");`)

```cpp
// Stack: perfect for temporary objects
void randomChump(std::string name) {
    Zombie z(name);          // Lives on stack
    z.announce();
}                             // Automatically destroyed here

// Heap: needed when object outlives the function
Zombie* newZombie(std::string name) {
    return new Zombie(name);  // Caller must delete
}
```

#### Key Insight: Why "Delete What You New"

Memory leaks are insidious. They don't crash your program—they slowly consume resources until production systems fail mysteriously. C++ forces you to be explicit:

```cpp
Zombie* horde = new Zombie[N];
// ... use horde ...
delete[] horde;  // MUST use delete[] for arrays!
```

**The lesson transcends syntax**: You're learning that **freedom requires responsibility**. C++ gives you low-level control; you must wield it carefully.

#### Key Code Snippet: The Circular Dependency Pattern

```cpp
class Weapon {
private:
    std::string type;
public:
    const std::string& getType() const;  // Return by const reference
    void setType(const std::string& new_type);
};

class HumanA {
private:
    Weapon& weapon;  // Reference: always armed
public:
    HumanA(const std::string& name, Weapon& w) : weapon(w) {}
    void attack() const;
};

// This works beautifully because weapon's lifetime is guaranteed
```

#### Exercises Overview

| Exercise | Focus | Lesson |
|----------|-------|--------|
| **Ex00: BraiiiiiiinnnzzzZ** | Stack vs heap, destructors | Where should objects live? |
| **Ex01: Moar brainz!** | Array allocation, circular buffers | Dynamic arrays with scoped lifetimes |
| **Ex02: HI THIS IS BRAIN** | Pointers vs references | Why references are safer |
| **Ex03: Unnecessary violence** | Reference vs pointer relationships | Design patterns: mandatory vs optional |
| **Ex04: Sed is for losers** | File I/O, string manipulation | Real-world string processing |
| **Ex05: Harl 2.0** | Pointers to member functions | Advanced function pointers |
| **Ex06: Harl filter** | Switch statements, fall-through | Control flow optimization |

#### Compilation

```bash
cd cpp-01 && make
```

---

## **Module 02: Ad-hoc Polymorphism**
### *Operator Overloading, The Orthodox Canonical Form*

#### Core Concept: Ad-hoc Polymorphism

**Polymorphism** means "many forms." Ad-hoc polymorphism (also called overloading) lets the same operator *behave differently* depending on the operands:

```cpp
Fixed a(5.05f);
Fixed b(2);
Fixed c = a * b;  // Custom multiplication for Fixed-point numbers
```

The `*` operator isn't built for fixed-point math—you *teach* it to be. This is powerful but requires discipline.

#### Key Insight: The Orthodox Canonical Form (OCF)

By Module 02, you must master the **Orthodox Canonical Form**—a canonical set of member functions every class should implement:

```cpp
class Fixed {
public:
    // The "Big Four"
    Fixed();                           // Default constructor
    Fixed(const Fixed& other);         // Copy constructor
    Fixed& operator=(const Fixed& rhs); // Assignment operator
    ~Fixed();                          // Destructor
};
```

**Why is this crucial?** Because C++ *automatically generates* defaults for these if you don't. And the defaults are often **wrong**:

- Default copy constructor does **shallow copy** (dangerous for pointers)
- Default assignment operator has no **self-assignment check**
- Default destructor doesn't run cleanup

Missing any of these four can create **undefined behavior** that's hard to debug.

```cpp
// WRONG: Shallow copy of pointer
class DangerousClass {
private:
    int* data;
public:
    DangerousClass(int size) {
        data = new int[size];
    }
    // No copy constructor!
};

DangerousClass a(10);
DangerousClass b = a;  // Both point to same data!
// When b is destroyed, it deletes the shared array
// a.data now points to garbage (use-after-free)

// RIGHT: Explicit deep copy
DangerousClass(const DangerousClass& other) {
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}
```

#### Key Code Snippet: Fixed-Point Multiplication

```cpp
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    long long temp = (long long)this->_fixedPointValue * other.getRawBits();
    result.setRawBits(temp >> 8);  // Shift right by fractional bits
    return result;
}
```

**Why this is elegant**: You're using bit manipulation (low-level) *wrapped in* operator overloading (high-level). This is C++ at its best—control + abstraction.

#### Exercises Overview

| Exercise | Focus | Lesson |
|----------|-------|--------|
| **Ex00: Fixed I** | Basic OCF, constructors | Learning the canonical form |
| **Ex01: Fixed II** | Comparison operators | Overloading for semantics |
| **Ex02: Fixed III** | Arithmetic operators, min/max | Complex fixed-point math |
| **Ex03: BSP (Point in Triangle)** | Geometry, math operators | Applying overloads to real problems |

#### Compilation

```bash
cd cpp-02 && make
```

---

## **Module 03: Inheritance**
### *Protected Members, Construction/Destruction Chains*

#### Core Concept: Inheritance as Specialization

Inheritance answers: "What if I have a base concept, and multiple specialized versions?"

```cpp
class ClapTrap {                    // Base: generic character
private:
    std::string name;
    int hitPoints;
    
public:
    void attack(std::string target);
};

class ScavTrap : public ClapTrap {  // Specialized: 4-legged robot
public:
    void guardGate();  // ScavTrap-specific ability
};
```

**Key principle**: `is-a` relationships use inheritance. A `ScavTrap` **is-a** `ClapTrap`.

#### Key Insight: The Construction/Destruction Chain

Inheritance creates a **chain of responsibility** during object creation and destruction:

```cpp
// Creating a ScavTrap involves:
// 1. ScavTrap constructor
// 2. Calls ClapTrap constructor
// 3. Initialize members

// Destroying a ScavTrap involves (reverse order):
// 1. ScavTrap destructor
// 2. Calls ClapTrap destructor
// 3. Clean up members
```

```cpp
class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name) : ClapTrap(name) {  // Initializer list!
        std::cout << "ScavTrap constructor" << std::endl;
    }
    
    ~ScavTrap() {
        std::cout << "ScavTrap destructor" << std::endl;
        // ClapTrap destructor runs automatically
    }
};
```

#### The Protected Keyword: The Inheritance Signal

Three access levels in C++:

| Level | Accessible inside class | Accessible by derived classes | Accessible from outside |
|-------|-------------------------|-------------------------------|------------------------|
| `public` | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ❌ |
| `private` | ✅ | ❌ | ❌ |

```cpp
class ClapTrap {
protected:                          // Derived classes can access
    int hitPoints;
    
    void gainHitPoints(int amount) {
        hitPoints += amount;
    }
};

class ScavTrap : public ClapTrap {
public:
    void repair() {
        gainHitPoints(10);  // ✅ Can access protected member
    }
};
```

#### Key Code Snippet: Multi-Level Inheritance Chain

```cpp
// Hierarchy: ClapTrap -> ScavTrap -> FragTrap
class ScavTrap : public ClapTrap {
protected:
    int guardGateCount;
    
public:
    ScavTrap(std::string name) : ClapTrap(name), guardGateCount(0) {}
};

class FragTrap : public ClapTrap {
private:
    int energy;
    
public:
    FragTrap(std::string name) : ClapTrap(name), energy(100) {}
    void highFiveGuys() { /* ... */ }
};
```

#### The Diamond Problem (Preview)

What happens with multiple inheritance?

```cpp
class A { public: virtual void speak() {} };
class B : public A { };
class C : public A { };
class D : public B, public C { };  // DANGER: Two copies of A!

D d;
d.speak();  // Which A::speak()?
```

C++98 doesn't solve this elegantly, but later versions use **virtual inheritance**. For now, understand that **multiple inheritance should be rare and explicit**.

#### Exercises Overview

| Exercise | Focus | Lesson |
|----------|-------|--------|
| **Ex00: ClapTrap** | Inheritance basics, protected members | The foundation of hierarchies |
| **Ex01: ScavTrap** | Method override, inheritance chains | Specialization through inheritance |
| **Ex02: FragTrap** | Multi-level hierarchy | Going deeper into specialization |

#### Compilation

```bash
cd cpp-03 && make
```

---

## **Module 04: Subtype Polymorphism**
### *Virtual Functions, Abstract Classes, Interfaces*

#### Core Concept: Subtype Polymorphism (Runtime Polymorphism)

Now we reach the **pinnacle of polymorphism**. Instead of compile-time overloading, we use **runtime dispatch** to call the right method:

```cpp
void fight(Character& c) {
    c.attack();  // Which attack()? Depends on c's *actual* type at runtime!
}

ClapTrap trap("Trap");
ScavTrap scav("Scav");

fight(trap);   // Calls ClapTrap::attack()
fight(scav);   // Calls ScavTrap::attack()
```

This is the **most powerful** polymorphism mechanism. It enables true open-closed design: you can add new character types *without modifying* the `fight()` function.

#### Key Insight: The V-Table (Virtual Function Table)

When you declare a method `virtual`, C++ creates a hidden structure called the **V-Table**:

```cpp
class Character {
public:
    virtual void attack() { }      // Marked virtual
    virtual ~Character() { }       // Destructors should ALWAYS be virtual!
};

class ClapTrap : public Character {
public:
    void attack() { std::cout << "Melee attack\n"; }  // Override
};

// Behind the scenes:
// Character* ptr = new ClapTrap();
// ptr->attack();
//
// 1. Check ptr's actual type: ClapTrap
// 2. Look up ClapTrap's V-Table
// 3. Find attack() → calls ClapTrap::attack()
```

**Why destructors must be virtual:**

```cpp
// WITHOUT virtual destructor
Character* c = new ClapTrap();
delete c;  // Calls Character::~Character(), not ClapTrap's cleanup!
           // Memory leaked!

// WITH virtual destructor
Character* c = new ClapTrap();
delete c;  // Calls ClapTrap::~ClapTrap(), then Character::~Character()
           // ✅ Correct!
```

#### Key Code Snippet: Abstract Classes as Interfaces

```cpp
// Abstract base class: defines contract, not implementation
class AWeapon {
public:
    virtual ~AWeapon() {}
    virtual void attack() const = 0;    // Pure virtual: MUST override
    virtual std::string getName() const = 0;
};

class Sword : public AWeapon {
private:
    std::string name;
public:
    Sword(std::string n) : name(n) {}
    void attack() const { std::cout << "Slash!\n"; }
    std::string getName() const { return name; }
};

// You CANNOT instantiate AWeapon:
// AWeapon w;  // ❌ Compiler error: cannot instantiate abstract class

// But you CAN use it as an interface:
AWeapon* weapon = new Sword("Excalibur");
weapon->attack();  // ✅ Calls Sword::attack()
delete weapon;     // ✅ Calls Sword destructor
```

#### Deep Copy vs Shallow Copy Revisited

Module 04 hammers home the importance of proper copying:

```cpp
class Character {
private:
    std::string name;
    Weapon* weapon;  // Pointer!
    
public:
    Character(const Character& other) {
        name = other.name;
        weapon = new Weapon(*other.weapon);  // Deep copy!
    }
    
    Character& operator=(const Character& rhs) {
        if (this == &rhs)  // Self-assignment guard
            return *this;
            
        delete weapon;     // Clean old
        weapon = new Weapon(*rhs.weapon);  // Deep copy
        return *this;
    }
};
```

#### Exercises Overview

| Exercise | Focus | Lesson |
|----------|-------|--------|
| **Ex00: Polymorphism** | Virtual functions, overrides | Runtime dispatch magic |
| **Ex01: WrongCat** | Deep copy errors, debugging | Why shallow copy fails |
| **Ex02: Abstract classes** | Pure virtual functions | Designing contracts |

#### Compilation

```bash
cd cpp-04 && make
```

---

## 🏛️ The Holy Trinity of OOP

This curriculum teaches the **three pillars of Object-Oriented Design**:

### 1. **Encapsulation** (Module 00)
Hide implementation details behind a public interface.

```cpp
class BankAccount {
private:
    double balance;  // Hidden
public:
    void deposit(double amount);   // Controlled access
    double getBalance() const;
};
```

**Why:** Users interact with *what*, not *how*. You can change internals without breaking code.

---

### 2. **Inheritance** (Module 03)
Create hierarchies of related types.

```cpp
class Vehicle { public: virtual void drive() {} };
class Car : public Vehicle { public: void drive() { /* wheels */ } };
class Boat : public Vehicle { public: void drive() { /* propeller */ } };
```

**Why:** Capture common behavior in base classes; specialize in derived classes. DRY principle applied to types.

---

### 3. **Polymorphism** (Modules 02 & 04)
One interface, many implementations.

```cpp
void transport(Vehicle& v) {
    v.drive();  // Works for Car, Boat, Helicopter, ...
}
```

**Why:** Write code that works with *categories* of types, not specific types. Enables extensibility.

---

## 🔧 Technical Specifications

### Compilation Standards

All projects strictly follow **C++98** and compile with:

```bash
c++ -Wall -Wextra -Werror -std=c++98 -c -o output.o source.cpp
```

**Flags explained:**
- `-Wall -Wextra -Werror`: Treat all warnings as errors (rigorous!)
- `-std=c++98`: No modern C++ (no smart pointers, no auto, no lambdas)
- `-c`: Compile to object files only
- `-o`: Output file name

### Memory Management: Zero Leaks Guaranteed

Every project is **valgrind-clean**:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./program
```

**Key discipline:**
- Every `new` has a corresponding `delete`
- Every `new[]` has a corresponding `delete[]`
- Destructors clean up dynamically allocated memory
- Copy constructors/assignment operators prevent double-frees

### Include Guards

Every header prevents double inclusion:

```cpp
#ifndef CLASSNAME_HPP
#define CLASSNAME_HPP

class ClassName { /* ... */ };

#endif  // CLASSNAME_HPP
```

---

## 📚 Module Progression Chart

```
Module 00: Classes, Streams          ← Learn syntax
     ↓
Module 01: Pointers, References      ← Manage memory
     ↓
Module 02: Operator Overloading      ← Make custom types feel natural
     ↓
Module 03: Inheritance               ← Organize hierarchies
     ↓
Module 04: Virtual Functions         ← Unlock polymorphism
     ↓
RESULT: Full OOP Architect! 🎓
```

---

## 🎯 Key Learning Outcomes

By the end of this journey, you will understand:

| Outcome | Module | Evidence |
|---------|--------|----------|
| How to design classes with proper encapsulation | 00 | PhoneBook with private/public |
| When to use pointers vs references | 01 | HumanA/HumanB weapon patterns |
| Why the OCF is non-negotiable | 02 | Fixed-point class with all four |
| How constructors chain in inheritance | 03 | ClapTrap → ScavTrap → FragTrap |
| How V-Tables enable runtime dispatch | 04 | Abstract weapon classes |
| RAII and zero-leak design | All | Every destructor counts |

---

## 📖 How to Use This Repository

### Explore Individual Modules

Each module has its own `README.md` with exercise-by-exercise breakdowns:

```bash
cat cpp-00/README.md  # Module 00 details
cat cpp-01/README.md  # Module 01 details
# ... etc
```

### Compile and Test

```bash
cd cpp-00 && make && ./executable_name
cd cpp-01 && make && ./executable_name
# ... etc
```

### Study the Code

Each exercise demonstrates progressive complexity:
- **Simple exercises**: Understand the concept
- **Medium exercises**: Apply the concept
- **Advanced exercises**: Combine multiple concepts

---

## 💡 A Few Philosophical Insights

### 1. "New" Isn't Mandatory

Many C++ newcomers think dynamic allocation is necessary. It's not. **Use the stack by default**. Only use `new` when you must manage object lifetime beyond function scope.

```cpp
// ✅ Good: Stack allocation
void demo() {
    Vector v(10);
    v.sort();
}

// ❌ Avoid: Unnecessary heap
void demo() {
    Vector* v = new Vector(10);
    v->sort();
    delete v;  // Why the extra work?
}
```

### 2. Const is Your Friend

`const` doesn't just prevent mistakes—it documents intent:

```cpp
// This method doesn't change state
void display() const { std::cout << name << "\n"; }

// This reference can't be changed
const std::string& getName() const;

// This parameter won't be modified
void process(const Data& input);
```

### 3. Destructors Are the Most Important Method

If you write only one method carefully, make it the destructor. It's where bugs live:

```cpp
class Resource {
private:
    int* data;
public:
    ~Resource() {
        if (data)              // Check for null
            delete[] data;     // Use delete[] for arrays
        data = nullptr;        // Prevent use-after-free
    }
};
```

---

## 🏆 Final Reflection

This journey from Module 00 to Module 04 is more than syntax. You're learning **how to think** as a systems architect:

- **Module 00** teaches you to *organize* code
- **Module 01** teaches you to *manage resources*
- **Module 02** teaches you to *extend behavior*
- **Module 03** teaches you to *structure hierarchies*
- **Module 04** teaches you to *design contracts*

Together, they're the foundation for writing C++ that's:
- **Correct**: No leaks, no undefined behavior
- **Clear**: Easy to understand and modify
- **Extensible**: New features don't require rewriting everything
- **Maintainable**: Future developers can reason about your code

---

## 📝 Project Information

- **School:** 42 School
- **Curriculum:** C++ Piscine (Modules 00–04)
- **Language:** C++98
- **Total Exercises:** 21
- **Memory Leaks:** 0
- **Code Quality:** Rigorous

---

## 🔗 Quick Links

- [Module 00: The Basics](./cpp-00/README.md)
- [Module 01: Memory & Logic](./cpp-01/README.md)
- [Module 02: Ad-hoc Polymorphism](./cpp-02/README.md)
- [Module 03: Inheritance](./cpp-03/README.md)
- [Module 04: Subtype Polymorphism](./cpp-04/README.md)

---

**Author:** Yoares  
**Repository:** [cpp-modules-collection](https://github.com/Yoares/cpp-modules-collection)  
**Last Updated:** January 2026

---

*"The mastery of C++ is not in knowing every feature, but in knowing which features to use and when. This collection represents the careful, deliberate study of fundamentals."* — A Mentor at 42
