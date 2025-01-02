// Player.h
#pragma once
#include <string>

class Player {
public:
    Player(const std::string& name = "");
    virtual ~Player() {}
    std::string getName() const;
    int getScore() const;
    void setName(const std::string& name);
    void incrementScore();
    void resetScore();
    virtual void printInfo() const;

private:
    std::string name;
    int score;
};