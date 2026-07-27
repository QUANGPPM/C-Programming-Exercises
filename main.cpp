#include "main.hpp"
#include "Character.hpp"

int main() {
    game_engine::Character hero = game_engine::Character("HERO", 1, 100);
    game_engine::Character enemy = game_engine::Character("ENEMY", 1, 100);
    game_engine::battle(hero, enemy, 100);
    auto name = hero.getName();
    std::cout << name << std::endl;

    enemy.heal("Large");
    auto health = enemy.getHealth();
    std::cout << health << std::endl;
    enemy.heal(10);
    health = enemy.getHealth();
    std::cout << health << std::endl;
    
    return 0;
}