#pragma once
#include <string>
namespace game_system {
    class ItemData {
    private:
        std::string name;
        double rawPrice;
    public:
        ItemData(std::string name, double rawPrice) : name(name), rawPrice(rawPrice) {}
        std::string getName() {
            return name;
        }
        void setName(std::string name) {
            this->name = name;
        }
        double getRawPrice() {
            return rawPrice;
        }
        void setRawPrice(double rawPrice) {
            this->rawPrice = rawPrice;
        }
        int getRounderPrice() {
            return static_cast<int>(rawPrice);
        }

    };
    ItemData parseItemData(std::string rawData);
    class Player {
    private:
        std::string playerName;
        int gold;
    public:
        Player(std::string playerName, int gold) : playerName(playerName), gold(gold) {}
        std::string getPlayerName() {
            return playerName;
        }
        void setPlayerName(std::string playerName) {
            this->playerName = playerName;
        }
        int getGold() {
            return gold;
        }
        void setGold(int gold) {
            this->gold = gold;
        }
        void buyItem(ItemData item);


    };

};