#pragma once
#include <iostream>
#include <string>
namespace game_engine {
    class Character {
    private:
        std::string name;
        int level;
        int health;
    public:
        Character(std::string name = "Unknown", int level = 1, int health = 100) : 
                    name(name), level(level), health(health) {}
        
        std::string getName() {
            return name;
        }
        void setName(std::string name){
            this->name = name;
        }
        int getLevel() {
            return level;
        }
        void setLevel(int level) {
            this->level = level;
        }
        int getHealth() {
            return health;
        }
        void setHealth(int health) {
            this->health = health;
        }
        void displayInfo();

        void heal(int amount);
        void heal(std::string potionType);

    };

    void battle(Character& attacker, Character& defender, int damage);
    
};