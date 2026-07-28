#include "Character.hpp"
#include <vector>

int main() {
    // game_engine::Character hero = game_engine::Character("HERO", 1, 100);
    // game_engine::Character enemy = game_engine::Character("ENEMY", 1, 100);
    // game_engine::battle(hero, enemy, 100);
    // auto name = hero.getName();
    // std::cout << name << std::endl;

    // enemy.heal("Large");
    // auto health = enemy.getHealth();
    // std::cout << health << std::endl;
    // enemy.heal(10);
    // health = enemy.getHealth();
    // std::cout << health << std::endl;

    std::vector<game_engine::Character*> party;
    party.push_back(new game_engine::Warrior("Warrior", 1, 100, 100));
    party.push_back(new game_engine::Mage("Mage", 1, 100, 300));
    game_engine::Monster monster = game_engine::Monster("Monster", 1, 500);
    for (auto i = party.begin(); i != party.end(); i++){
        try {
            (*i)->useSkill(monster);
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    for (auto i = party.begin(); i != party.end(); i++){
        delete *i;
    }
    return 0;
}