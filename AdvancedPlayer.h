#pragma once
// AdvancedPlayer.h
#include "Player.h"

class AdvancedPlayer : public Player {
public:
    AdvancedPlayer(const std::string& name = "");
    void printInfo() const override;
};
