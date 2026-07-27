#include "Game.hpp"
#include "InsufficientFundsException.hpp"
#include <stdexcept>
#include <iostream>
namespace game_system {
    ItemData parseItemData(std::string rawData){
        ItemData item = ItemData("", 0);
        size_t found = rawData.find('-');
        
        if(found == std::string::npos)
            throw std::invalid_argument("Error: Invalid Format of ItemData!!");
        
        item.setName(rawData.substr(0, found));
        item.setRawPrice(std::stod(rawData.substr(found + 1)));
        return item;
    }
    void Player::buyItem(ItemData item){
        if(gold < item.getRounderPrice())
            throw InsufficientFundsException();
        gold -= item.getRounderPrice();
        std::cout << "Purchase an Item Successfully!!" << std::endl;
    }
};