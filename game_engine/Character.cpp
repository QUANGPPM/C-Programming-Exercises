#include "Character.hpp"

namespace game_engine {
    void Character::displayInfo() {

    }
    void Character::heal(int amount) {
        health += amount;
    }
    void Character::heal(std::string potionType) {
        if(potionType == "Small")
            heal(20);
        else if(potionType == "Large")
            heal(50);
    }
    void battle(Character& attacker, Character& defender, int damage) {
        defender.setHealth(defender.getHealth() - damage);
        std::cout << attacker.getName() << " attacked " << defender.getName() << " for " << damage << " !" << std::endl;
    }
};