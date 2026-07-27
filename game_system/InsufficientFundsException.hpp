#pragma once
#include <exception>
namespace game_system {
    class InsufficientFundsException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Error: Player don't have enough money to purchase this item!";
        }
    };
};