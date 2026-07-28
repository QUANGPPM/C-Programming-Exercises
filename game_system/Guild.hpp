#pragma once
#include "Game.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
namespace game_system {
    class Guild {
    private:
        static inline int guildCount = 0;
        std::string guildName;
        int totalPower;
        std::vector<std::string> members;
    public:
        static int getGuildCount() {return guildCount;}
        Guild() : guildName("Unknown"), totalPower(0), members({}) {guildCount++;}
        Guild(std::string guildName, int totalPower, const std::vector<std::string>& members) :
                guildName(guildName), totalPower(totalPower), members(members) {guildCount++;}
        ~Guild() {guildCount--;}
        std::string getGuildName() { return guildName; }
        void setGuildName(std::string guildName) {this->guildName = guildName;}
        int getTotalPower() {return totalPower;}
        void setTotalPower(int totalPower) {this->totalPower = totalPower;}
        void addMember(game_system::Player& player){
            members.push_back(player.getPlayerName());
            totalPower += player.getGold();
        }
        Guild operator+(const Guild& guild) const{
            Guild temp;
            temp.guildName = "Alliance of " + this->guildName + " and " + guild.guildName;
            temp.totalPower = this->totalPower + guild.totalPower;
            temp.members.reserve(this->members.size() + guild.members.size());
            temp.members.insert(temp.members.end(), this->members.begin(), this->members.end());
            temp.members.insert(temp.members.end(), guild.members.begin(), guild.members.end());
            return temp;
        }
        bool operator==(Guild& guild){
            return this->totalPower == guild.totalPower;
        }
        std::string& operator[](size_t index) {
            if (index >= members.size()){
                throw std::out_of_range("Index out of range");
            }
            return members[index];
        }
        friend std::ostream& operator<<(std::ostream& os, const Guild& guild){
            os << "Guild Name: " << guild.guildName << std::endl;
            os << "Total Power: " << guild.totalPower << std::endl;
            os << "Members: ";
            for(size_t i = 0; i < guild.members.size(); i++){
                os << guild.members[i] << " ";
            }
            os << std::endl;
            return os;
        }


    };
};