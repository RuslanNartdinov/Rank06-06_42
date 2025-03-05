#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
private:
    std::string _name;
    Weapon&     _weapon;  // Ссылка (должна быть инициализирована в конструкторе)

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack() const;
};

#endif