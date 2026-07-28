#pragma once
#include <string>
namespace game_engine {
    class Weapon {
    private:
        std::string weaponName;
        int damageBonus;
    public:
        Weapon(std::string weaponName = "Unknown", int damageBonus = 0) :
            weaponName(weaponName), damageBonus(damageBonus) {}
        const std::string& getWeaponName() const { // Mark as const
            return weaponName;
        }
        void setWeaponName(const std::string& weaponName) {
            this->weaponName = weaponName;
        }
        int getDamageBonus() const { // Mark as const
            return damageBonus;
        }
        void setDamageBonus(int damageBonus) { // int by value is fine
            this->damageBonus = damageBonus;
        }
    
        
    };
};