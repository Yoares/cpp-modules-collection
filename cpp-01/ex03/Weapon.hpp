#ifndef Weapon_hpp
#define Weapon_hpp
#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;
    public:
        Weapon();
        Weapon(const std::string& type);
        const std::string& getType() const;
        void    setType(const std::string& new_type);
};
#endif