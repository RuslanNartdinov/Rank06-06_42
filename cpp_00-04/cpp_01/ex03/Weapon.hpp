#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string _type;
public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType() const;
    void setType(const std::string &newType);
};

#endif