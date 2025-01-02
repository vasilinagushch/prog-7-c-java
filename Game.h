#pragma once
#ifndef GAME_H
#define GAME_H

#include "Phrase.h"
#include "Player.h"
#include "Puzzle.h"
#include <string>
#include <vector>
#include <memory> // Для std::shared_ptr

class Game {
private:
    Player player;
    std::vector<std::shared_ptr<Puzzle>> puzzles; // Изменение массива на вектор умных указателей
    std::vector<Phrase> phrases; // Изменение массива на вектор
    int currentPuzzle;

public:
    Game();
    void initializePuzzles();
    void initializePhrases();
    void setPlayerName(const std::string& playerName); // Используем std::string
    const std::string& getPlayerName() const; // Используем std::string
    int getPlayerScore() const;
    const std::string& getRandomPhrase() const; // Используем std::string
    bool checkAnswer(int puzzleIndex, int answerIndex);
    void printPuzzle(int puzzleIndex) const;
    void printHint(int puzzleIndex) const;
    void startGame();
    void getAnswerAndCheck(int puzzleIndex);

    // Методы для демонстрации работы с массивами объектов
    void printAllPuzzles();
    void demoTwoDimensionalArray();
};

#endif // GAME_H