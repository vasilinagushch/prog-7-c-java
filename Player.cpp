// Player.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"
#include <iostream>

Player::Player(const std::string& name) : name(name), score(0) {}

std::string Player::getName() const { return name; }
int Player::getScore() const { return score; }
void Player::setName(const std::string& name) { this->name = name; }
void Player::incrementScore() { score++; }
void Player::resetScore() { score = 0; }
void Player::printInfo() const {
    std::cout << "Player: " << name << ", Score: " << score << std::endl;
}