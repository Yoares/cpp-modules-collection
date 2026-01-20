#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include <string>
#include <sstream>

void printTestHeader(const std::string &testName)
{
    std::cout << "\n"
              << std::string(50, '=') << std::endl;
    std::cout << "TEST: " << testName << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

int main()
{
    {
        printTestHeader("Basic Exercise Test (from subject)");

        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me");
        AMateria *tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter *bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    {
        printTestHeader("Simple Character Materia Use");

        Character hero("Hero");
        Character enemy("Enemy");

        hero.equip(new Ice());
        hero.equip(new Cure());

        hero.use(0, enemy);
        hero.use(1, enemy);
    }

    {
        printTestHeader("Full Inventory Test (4 materias)");

        Character warrior("Warrior");
        Character target("Target");

        warrior.equip(new Ice());
        warrior.equip(new Cure());
        warrior.equip(new Ice());
        warrior.equip(new Cure());

        std::cout << "Using all 4 materia slots:" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "Slot " << i << ": ";
            warrior.use(i, target);
        }

        std::cout << "\nTrying to equip 5th materia " << std::endl;
        warrior.equip(new Ice());
    }
    {
        printTestHeader("Invalid Operations Test");

        Character tester("Tester");
        Character dummy("Dummy");

        std::cout << "1. Using empty slot: ";
        tester.use(0, dummy);
        std::cout << std::endl;

        std::cout << "2. Using invalid negative index: ";
        tester.use(-1, dummy);
        std::cout << std::endl;

        std::cout << "3. Using index >= 4: ";
        tester.use(10, dummy);
        std::cout << std::endl;

        tester.equip(new Ice());

        std::cout << "4. Valid slot 0: ";
        tester.use(0, dummy);
        std::cout << std::endl;

        std::cout << "5. Empty slot 1: ";
        tester.use(1, dummy);
        std::cout << std::endl;
    }

    {
        printTestHeader("Unequip Test");

        Character knight("Knight");
        Character opponent("Opponent");

        knight.equip(new Ice());
        knight.equip(new Cure());

        std::cout << "Before unequip:" << std::endl;
        knight.use(0, opponent);
        knight.use(1, opponent);

        knight.unequip(0);
        std::cout << "\nAfter unequipping slot 0: and equip new materia " << std::endl;

        knight.equip(new Cure());
        knight.use(0, opponent);
        knight.use(1, opponent);

        knight.unequip(-1); 
        knight.unequip(10); 

    }


    {
        printTestHeader("MateriaSource Full Capacity (4 templates)");

        MateriaSource fullSource;

        fullSource.learnMateria(new Ice());
        fullSource.learnMateria(new Cure());
        fullSource.learnMateria(new Ice()); 
        fullSource.learnMateria(new Cure());

      
        std::cout << "Learning 5th materia ..." << std::endl;
        fullSource.learnMateria(new Ice());

   
        AMateria *test = fullSource.createMateria("ice");
        if (test)
        {
            std::cout << "Can still create after full: " << test->getType() << std::endl;
            delete test;
        }
    }

    {
        printTestHeader("Character Deep Copy Test");

  
        Character original("Original");
        original.equip(new Ice());
        original.equip(new Cure());

 
        Character copy(original);

        Character target("Target");

        std::cout << "Original character actions:" << std::endl;
        original.use(0, target);
        original.use(1, target);

        std::cout << "\nCopied character actions:" << std::endl;
        copy.use(0, target);
        copy.use(1, target);

    }

    {
        printTestHeader("Polymorphism Test");

        AMateria *materias[4];
        materias[0] = new Ice();
        materias[1] = new Cure();
        materias[2] = new Ice();
        materias[3] = new Cure();

        Character polymorphTest("PolyTest");
        Character target("Target");

        std::cout << "Testing polymorphic behavior:" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "Type: " << materias[i]->getType() << " - ";
            materias[i]->use(target);
        }
        for (int i = 0; i < 4; i++)
        {
            delete materias[i];
        }
    }


    {
        printTestHeader("NULL Materia Handling");

        Character nullTester("NullTester");
        MateriaSource nullSource;

        std::cout << "1. Equipping NULL materia: ";
        nullTester.equip(NULL);

        std::cout << "2. Learning NULL materia: ";
        nullSource.learnMateria(NULL);

    }

    std::cout << std::endl;


    return 0;
}