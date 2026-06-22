#ifndef Weapon_HPP
#define Weapon_HPP

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string type;

    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string& getType() const;
        void setType(std::string newtype);
};

#endif