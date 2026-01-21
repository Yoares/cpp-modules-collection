# C++ Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces

## Project Overview

C++ Module 04 is a deep dive into **Object-Oriented Programming (OOP)** fundamentals that form the backbone of scalable, maintainable C++ applications. This module explores how to design flexible class hierarchies, enforce contracts through interfaces, and leverage dynamic dispatch to write extensible code.

By the end of this module, you will understand:
- How virtual functions enable subtype polymorphism
- Why abstract classes prevent incomplete implementations
- How interfaces define behavioral contracts
- Why deep copying is essential for memory safety
- Common design patterns like the Prototype Pattern (Clone)

---

## Core Concepts: The "Why"

### 1. Subtype Polymorphism & Virtual Functions

**What is Polymorphism?**

Polymorphism means "many forms." In C++, it allows a pointer to a base class to reference objects of derived classes, and call the appropriate derived class method at runtime.

**Example from Ex00:**

```cpp
Animal* dog = new Dog();
dog->makeSound();  // Calls Dog::makeSound(), not Animal::makeSound()
```

**Why This Matters:**

Without polymorphism, you would need type-checking code everywhere:

```cpp
// ❌ Bad: Fragile, unmaintainable
if (typeid(*animal) == typeid(Dog)) {
    Dog* d = dynamic_cast<Dog*>(animal);
    d->makeSound();
} else if (typeid(*animal) == typeid(Cat)) {
    Cat* c = dynamic_cast<Cat*>(animal);
    c->makeSound();
}
```

With virtual functions:

```cpp
// ✅ Good: Clean, extensible
animal->makeSound();  // Calls the correct method automatically
```

**How It Works (Dynamic Dispatch):**

Each class with virtual functions maintains a **Virtual Method Table (vTable)**. At runtime, the program looks up which method to call based on the actual object type, not the pointer type. This is determined by the **Virtual Table Pointer (vptr)** stored in every polymorphic object.

```
Animal* ptr = new Dog();
ptr->makeSound();

// Runtime dispatch:
// 1. Follow vptr in the Dog object
// 2. Look up makeSound() in Dog's vTable
// 3. Call Dog::makeSound()
```

---

### 2. Abstract Classes & Pure Virtual Functions

**What is an Abstract Class?**

An abstract class is a class that cannot be instantiated. It serves as a blueprint for derived classes and forces them to implement specific methods.

**Pure Virtual Functions:**

A pure virtual function is declared with `= 0` and has no implementation in the base class:

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual function
    virtual ~Animal();
};

// ❌ This won't compile:
// Animal a;  // Error: cannot instantiate abstract class

// ✅ This works:
Animal* ptr = new Dog();  // Dog must implement makeSound()
```

**Why Use Abstract Classes?**

1. **Enforce the contract**: Derived classes MUST implement the pure virtual methods
2. **Prevent incomplete implementations**: You can't accidentally create an Animal without a sound
3. **Design clarity**: The code explicitly says "this is an interface that must be implemented"
4. **Compiler protection**: The compiler catches violations at compile-time, not runtime

**Ex02 Example:**

In Exercise 02, the `Animal` class becomes abstract with a pure virtual `makeSound()` method. This prevents code like this:

```cpp
Animal a;  // ❌ Compile error: cannot instantiate abstract class Animal
```

But allows:

```cpp
Animal* dog = new Dog();  // ✅ Works: Dog implements makeSound()
```

---

### 3. Interfaces in C++98

**What is an Interface?**

In C++98 (before C++11), an interface is a class with **only** pure virtual functions and no data members. It defines a "contract" that any implementing class must follow.

**The ICharacter Interface (Ex03):**

```cpp
class ICharacter {
public:
    virtual ~ICharacter();
    virtual const std::string& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

This interface says: "Any class that inherits from ICharacter MUST provide these four methods."

**Why Interfaces Matter:**

1. **Loose Coupling**: Code depends on the interface, not concrete implementations
2. **Extensibility**: Add new character types (Warrior, Mage, Thief) without changing existing code
3. **Testability**: You can create mock implementations for testing
4. **Clear Contracts**: Developers know exactly what methods must be implemented

**Real-World Analogy:**

An interface is like a job contract. It specifies what duties an employee must perform, but not how they perform them. Different employees (implementations) perform the duties differently, but all fulfill the contract.

---

### 4. Deep Copy vs. Shallow Copy & Memory Leaks

**The Problem: Shallow Copy**

Consider a class with a pointer member:

```cpp
class Brain {
private:
    std::string* ideas;
public:
    Brain() {
        ideas = new std::string[100];
    }
    // Shallow copy constructor (BAD):
    Brain(const Brain& other) {
        ideas = other.ideas;  // ❌ Just copies the pointer!
    }
    ~Brain() {
        delete[] ideas;  // ❌ Only one object should delete!
    }
};
```

**What Goes Wrong:**

```cpp
Brain b1;
Brain b2 = b1;  // Shallow copy: b1.ideas and b2.ideas point to SAME memory

// When they go out of scope:
// b2 destructor: delete[] ideas  ✅
// b1 destructor: delete[] ideas  ❌ Double Free Error! Crash!
```

**The Solution: Deep Copy**

```cpp
class Brain {
private:
    std::string* ideas;
public:
    Brain() {
        ideas = new std::string[100];
    }
    // Deep copy constructor (GOOD):
    Brain(const Brain& other) {
        ideas = new std::string[100];  // Allocate NEW memory
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];  // Copy the VALUES
        }
    }
    ~Brain() {
        delete[] ideas;  // Safe: each object owns its own memory
    }
};
```

**Why This Matters:**

When you copy an object that owns dynamically allocated memory, you must allocate new memory and copy the contents. Otherwise, multiple objects will try to delete the same memory, causing crashes and undefined behavior.

**Memory Leak Detection:**

In Ex01, we use memory leak detection to verify that all allocated memory is properly freed:

```bash
valgrind --leak-check=full ./animals
```

This ensures that even when objects are copied, no memory is leaked.

---

## Exercise Breakdown

### Exercise 00: Polymorphism

**Objective**: Understand virtual functions and method overriding.

**Key Classes:**

- `Animal`: Base class with virtual `makeSound()`
- `Dog`: Derived class that overrides `makeSound()` with "Woof!"
- `Cat`: Derived class that overrides `makeSound()` with "Meow"
- `WrongAnimal` & `WrongCat`: Demonstrate non-virtual functions (wrong approach)

**Key Learning:**

```cpp
Animal* animal = new Dog();
animal->makeSound();  // Outputs: "Woof!" (dynamic dispatch)
delete animal;
```

Without `virtual`, `Animal::makeSound()` would be called instead of `Dog::makeSound()`.

---

### Exercise 01: I don't want to set the world on fire

**Objective**: Master deep copying and memory management.

**Key Classes:**

- `Brain`: Contains a pointer to an array of 100 strings (`ideas`)
- `Dog` & `Cat`: Each has a `Brain*` member

**Key Learning - Deep Copy Constructor:**

```cpp
Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);  // Deep copy the brain!
}
```

**Memory Leak Check:**

Run with Valgrind to ensure no leaks:

```bash
valgrind --leak-check=full ./animals
```

Expected output: "0 bytes lost"

**Why This Exercise Exists:**

It forces you to understand the difference between copying pointers (bad) and copying the data they point to (good). This is critical for writing robust C++ code.

---

### Exercise 02: Abstract Class

**Objective**: Prevent incomplete implementations using abstract classes.

**Key Change:**

The `Animal` class becomes abstract:

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual
    // Cannot be instantiated!
};
```

**What You Can't Do:**

```cpp
Animal a;  // ❌ Compile error: abstract class
```

**What You Can Do:**

```cpp
Animal* dog = new Dog();  // ✅ OK: Dog implements makeSound()
dog->makeSound();
```

**Why This Matters:**

This prevents developers from creating incomplete Animal objects. The compiler ensures that only concrete classes (Dog, Cat) can be instantiated.

---

### Exercise 03: Interfaces & The RPG System

**Objective**: Design a complete system using interfaces and the Clone pattern.

**System Overview:**

An RPG system where characters equip magical materias (spells) and use them in combat.

**Key Classes:**

1. **AMateria** (Abstract Base Class):
   - Represents a spell with a `type` (ice, cure)
   - Pure virtual `clone()` method (Prototype Pattern)
   - Pure virtual `use()` method

2. **Concrete Materias** (Ice, Cure):
   ```cpp
   class Ice : public AMateria {
   public:
       Ice();
       Ice(const Ice& other);
       ~Ice();
       AMateria* clone() const;  // Create a deep copy
       void use(ICharacter& target);
   };
   ```

3. **ICharacter** (Interface):
   ```cpp
   class ICharacter {
   public:
       virtual const std::string& getName() const = 0;
       virtual void equip(AMateria* m) = 0;
       virtual void unequip(int idx) = 0;
       virtual void use(int idx, ICharacter& target) = 0;
   };
   ```

4. **Character** (Concrete Implementation):
   - Implements ICharacter
   - Manages 4 materia slots in an inventory
   - Deep copies materias when equipped

5. **IMateriaSource** & **MateriaSource**:
   - Stores materia templates
   - Can create copies of learned materias

**The Clone Pattern:**

Instead of passing materia prototypes around directly, we call `clone()` to create independent copies:

```cpp
AMateria* ice = new Ice();
AMateria* ice_copy = ice->clone();  // Deep copy using virtual clone()

character.equip(ice_copy);  // Character owns this copy
```

**Why This Design:**

- **Loose Coupling**: Characters don't know about Ice/Cure; they only know AMateria
- **Extensibility**: Add new materia types without changing Character
- **Memory Safety**: Each object owns its data; proper deep copying prevents leaks

---

## Installation & Usage

### Building the Project

Navigate to the desired exercise directory and build:

```bash
# Build Exercise 00
cd cpp-04/ex00
make

# Build Exercise 03 (RPG)
cd cpp-04/ex03
make
```

### Makefile Commands

```bash
make           # Build the executable
make re        # Clean and rebuild
make clean     # Remove object files
make fclean    # Remove object files and executable
```

### Running the Examples

**Exercise 00 - Polymorphism:**

```bash
cd ex00
make
./animals
```

Output demonstrates virtual function calls for Dog and Cat.

**Exercise 01 - Deep Copy:**

```bash
cd ex01
make
valgrind --leak-check=full ./animals
```

Should show "0 bytes lost" (no memory leaks).

**Exercise 03 - RPG System:**

```bash
cd ex03
make
./RPG
```

Output shows the RPG system in action with materias being equipped and used.

**Checking for Memory Leaks in Exercise 03:**

```bash
cd ex03
make
valgrind --leak-check=full ./RPG
```

Expected: "0 bytes lost" (all memory properly managed).

---

## Common Pitfalls & Solutions

### Pitfall 1: Forgetting Virtual Destructors

**Problem:**

```cpp
class Animal {
public:
    ~Animal() { }  // ❌ Not virtual!
};

Animal* dog = new Dog();
delete dog;  // Calls Animal::~Animal(), not Dog::~Dog()!
```

**Solution:**

```cpp
class Animal {
public:
    virtual ~Animal() { }  // ✅ Virtual destructor
};
```

### Pitfall 2: Shallow Copying Pointers

**Problem:**

```cpp
Brain b1;
Brain b2 = b1;  // Shallow copy: both point to same memory
// Crash when both try to delete the same memory!
```

**Solution:**

Always implement copy constructors and assignment operators for classes with pointers:

```cpp
Brain(const Brain& other) {
    ideas = new std::string[100];
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}
```

### Pitfall 3: Forgetting to Delete Unequipped Materias

**Problem:**

```cpp
AMateria* m = new Ice();
character.equip(m);
character.unequip(0);
// ❌ m is lost! Memory leak!
```

**Solution:**

```cpp
AMateria* m = new Ice();
character.equip(m);
character.unequip(0);
delete m;  // ✅ Take back ownership and clean up
```

---

## Key Takeaways

1. **Virtual Functions** enable dynamic dispatch: the correct method is called based on the actual object type, not the pointer type.

2. **Abstract Classes** enforce contracts: derived classes must implement pure virtual methods.

3. **Interfaces** define behavioral contracts without specifying implementation details.

4. **Deep Copying** is essential when objects own dynamically allocated memory; otherwise, multiple deletions cause crashes.

5. **Memory Management** is your responsibility: whoever allocates memory must deallocate it, and Valgrind helps verify correctness.

6. **Design Patterns** like Clone make systems extensible and maintainable.

---

## Compilation & C++ Standard

All exercises compile with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

This ensures strict C++98 compliance with maximum compiler warnings enabled.

---

## Author Notes

This module bridges the gap between procedural and object-oriented programming. Mastering these concepts—polymorphism, abstraction, and memory management—is essential for writing professional, maintainable C++ code. Pay special attention to the ownership and lifetime of dynamically allocated objects; this skill will serve you throughout your career.

**Happy coding!** 🚀
