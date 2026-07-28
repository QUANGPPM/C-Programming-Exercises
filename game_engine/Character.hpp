#pragma once
#include <iostream>
#include <string>
#include "Weapon.hpp"
namespace game_engine {
    class Character {
    protected:
        std::string name;
        int level;
        int health;
        Weapon* weapon = nullptr;
    public:
        Character(std::string name = "Unknown", int level = 1, int health = 100) : 
                    name(name), level(level), health(health) {}
        virtual ~Character() {
            if(weapon != nullptr)
                delete weapon;
        }
        void equipWeapon(Weapon* weapon) {
            this->weapon = weapon;
        }
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
        virtual void useSkill(Character& target) = 0;

    };

    void battle(Character& attacker, Character& defender, int damage);
    
    class Warrior : public Character {
    private:
        int stamina;
    public:
        Warrior(std::string name, int level, int health, int stamina) :
            Character(name, level, health), stamina(stamina) {}
        void useSkill(Character& target) override {
            if (stamina - 10 < 0)
                throw std::runtime_error("Not enough stamina");
            stamina -= 10;
            int damage = level * 5 + (weapon == nullptr ? 0 : weapon->getDamageBonus());
            battle(*this, target, damage);
            std::cout << "[Warrior]: Skill used" << std::endl;
        }
    };
    
    class Mage : public Character {
    private:
        int mana;
    public:
        Mage(std::string name, int level, int health, int mana) :
            Character(name, level, health), mana(mana) {}
        void useSkill(Character& target) override {
            if (mana - 20 < 0)
                throw std::runtime_error("Not enough mana");
            mana -= 20;
            int damage = level * 10 + (weapon != nullptr ? weapon->getDamageBonus() : 0);
            battle(*this, target, damage);
            std::cout << "[Mage]: Skill used" << std::endl;
        }
    };

    class Monster : public Character {
    public:
        Monster(std::string name, int level, int health) :
            Character(name, level, health) {}
        void useSkill(Character& target) override {
            int damage = level * 4;
            battle(*this, target, damage);
            std::cout << "[Monster]: Skill used" << std::endl;
        }
    };
};