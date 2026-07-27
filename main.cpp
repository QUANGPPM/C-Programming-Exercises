#include "main.hpp"
#include <iostream>



int main() {
    game_system::ItemData hat = game_system::ItemData("Hat", 50);
    game_system::ItemData sword = game_system::ItemData("Sword", 100);
    
    game_system::Player ch1 = game_system::Player("Quang", 10);
    
    try {
        ch1.buyItem(hat);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        game_system::ItemData newItem = game_system::parseItemData("Pains_10.0");
        std::cout << newItem.getName() << std::endl;
        std::cout << newItem.getRawPrice() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}