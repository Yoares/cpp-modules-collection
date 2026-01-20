// 



#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

// Color codes for readable output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void printHeader(std::string title) {
    std::cout << BLUE << "\n=== " << title << " ===" << RESET << std::endl;
}

// 1. STANDARD SUBJECT TEST
void test_subject() {
    printHeader("Subject Test");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

// 2. TEST UNKNOWN MATERIA & NULL HANDLING
void test_unknown_materia() {
    printHeader("Unknown / NULL Materia Test");
    IMateriaSource* src = new MateriaSource();
    
    // Test: Create unknown materia
    AMateria* tmp = src->createMateria("fire"); 
    if (tmp == NULL)
        std::cout << GREEN << "[OK] 'fire' returns NULL" << RESET << std::endl;
    else
        std::cout << RED << "[FAIL] 'fire' created something!" << RESET << std::endl;

    // Test: Equip NULL
    ICharacter* me = new Character("me");
    me->equip(NULL); // Should not crash
    std::cout << GREEN << "[OK] Equipped NULL without crash" << RESET << std::endl;

    me->use(0, *me); // Should do nothing (slot empty)
    std::cout << GREEN << "[OK] Used empty slot without crash" << RESET << std::endl;

    delete me;
    delete src;
}

// 3. TEST INVENTORY FULL (OVERFLOW)
void test_inventory_full() {
    printHeader("Inventory Overflow Test");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    ICharacter* me = new Character("Hoarder");
    
    // Fill inventory (0-3)
    for (int i = 0; i < 4; i++) {
        me->equip(src->createMateria("ice"));
    }
    std::cout << YELLOW << "Inventory filled (0-3)." << RESET << std::endl;

    // Try to add 5th item
    AMateria* extra = src->createMateria("ice");
    me->equip(extra); // Should do nothing, but we must delete 'extra' manually if not equipped to avoid leak!
    
    // NOTE: In a real evaluations, relying on equip() to delete extra is risky. 
    // Usually equip() just returns if full. So 'extra' is strictly leaking here unless we delete it.
    // For this test, I will assume equip() rejected it, so I delete it.
    delete extra; 
    std::cout << GREEN << "[OK] 5th item handled (manually deleted to prevent leak)" << RESET << std::endl;

    // Test Use valid indices
    me->use(0, *me);
    me->use(3, *me);
    
    // Test Use invalid index
    me->use(4, *me); // Should not crash
    me->use(-1, *me); // Should not crash
    std::cout << GREEN << "[OK] Invalid index use handled" << RESET << std::endl;

    delete me;
    delete src;
}

// 4. TEST DEEP COPY (CHARACTER)
void test_deep_copy_character() {
    printHeader("Deep Copy Character Test");
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());

    Character* bob = new Character("Bob");
    bob->equip(src->createMateria("ice"));

    // Copy Bob to Alice
    Character* alice = new Character(*bob); // Copy Constructor

    std::cout << YELLOW << "Bob uses ice:" << RESET << std::endl;
    bob->use(0, *bob); 
    
    std::cout << YELLOW << "Alice uses ice (should be copy):" << RESET << std::endl;
    alice->use(0, *alice);

    // Modify Bob (unequip/delete his item)
    // Note: unequip DOES NOT DELETE. We must save pointer to delete it.
    // However, since we don't have getMateria(), we simulate modification by deleting Bob.
    
    delete bob; // Bob is gone. Alice should still have her items if Deep Copy worked.
    std::cout << YELLOW << "Bob deleted. Alice uses ice again:" << RESET << std::endl;
    alice->use(0, *alice); // If shallow copy, this crashes (use after free)

    delete alice;
    delete src;
    std::cout << GREEN << "[OK] Deep Copy passed (no crash after original deleted)" << RESET << std::endl;
}

// 5. TEST DEEP COPY (MATERIASOURCE)
void test_deep_copy_source() {
    printHeader("Deep Copy MateriaSource Test");
    MateriaSource* src1 = new MateriaSource();
    src1->learnMateria(new Ice());

    MateriaSource* src2 = new MateriaSource(*src1); // Copy src1

    delete src1; // Delete original source

    // src2 should still work
    AMateria* tmp = src2->createMateria("ice");
    if (tmp) {
        std::cout << GREEN << "[OK] src2 created materia after src1 deletion" << RESET << std::endl;
        delete tmp;
    } else {
        std::cout << RED << "[FAIL] src2 lost the template!" << RESET << std::endl;
    }

    delete src2;
}

// 6. TEST UNEQUIP (LEAK CHECK)
void test_unequip() {
    printHeader("Unequip Test");
    // NOTE: This test requires a slight hack because ICharacter doesn't give us the pointer back.
    // In strict 42 subject, unequip(idx) does NOT delete.
    // Realistically, to avoid leak in main, we need the pointer. 
    // Since we are black-boxing, we create, equip, unequip. 
    // WARNING: This SPECIFIC test will likely show 1 leak in Valgrind if your Character::unequip 
    // just NULLs the slot without returning the pointer. 
    // This is "Correct" behavior according to the subject ("Handle the loose materia...").
    
    std::cout << YELLOW << "Note: Unequipped items technically leak if not caught by a floor system." << std::endl;
    std::cout << "This test just ensures unequip() doesn't crash." << RESET << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    
    AMateria* tmp = src->createMateria("cure");
    me->equip(tmp);
    
    me->use(0, *me);
    me->unequip(0); // Slot 0 becomes NULL
    me->use(0, *me); // Should do nothing
    std::cout << GREEN << "[OK] Unequipped slot used safely" << RESET << std::endl;

    // Since we hold 'tmp' in main, we can delete it here to prevent the leak!
    delete tmp; 
    
    delete me;
    delete src;
}

int main() {
    test_subject();
    test_unknown_materia();
    test_inventory_full();
    test_deep_copy_character();
    test_deep_copy_source();
    test_unequip();

    std::cout << BLUE << "\nAll tests completed." << RESET << std::endl;
    return 0;
}