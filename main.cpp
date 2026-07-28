#include "main.hpp"
#include <iostream>



int main() {
    std::cout << "====== Module 2 ======" << std::endl;
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

    std::cout << "====== Module 3 ======" << std::endl;
    game_system::Guild guild1 = game_system::Guild("Dragon", 5000, {"Athur", "Lancelot"});
    game_system::Guild guild2 = game_system::Guild("Wolves", 4500, {"Geralt", "Ciri"});
    std::cout << "Guild Count " << guild1.getGuildCount() << std::endl;
    std::cout << "Guild 1: " << guild1 << std::endl;
    std::cout << "Guild 2: " << guild2 << std::endl;
    auto guild3 =  guild1 + guild2;
    std::cout << "Guild 3: " << guild3 << std::endl;
    std::cout << "Member of Guild 3, index: " << 0 << " is " << guild3[0] << std::endl;
    std::cout << "Compare Guild 3 and Guide 2: " << (guild3 == guild2) << std::endl;
    return 0;
}