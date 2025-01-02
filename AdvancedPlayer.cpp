// AdvancedPlayer.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "AdvancedPlayer.h"
#include <iostream>

AdvancedPlayer::AdvancedPlayer(const std::string& name) : Player(name) {}

void AdvancedPlayer::printInfo() const {
    std::cout << "AdvancedPlayer: " << getName() << ", Score: " << getScore() << std::endl;
}