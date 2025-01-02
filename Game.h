#pragma once
#ifndef GAME_H
#define GAME_H

#include "Phrase.h"
#include "Player.h"
#include "Puzzle.h"
#include <string>
#include <vector>
#include <memory> // ��� std::shared_ptr

class Game {
private:
    Player player;
    std::vector<std::shared_ptr<Puzzle>> puzzles; // ��������� ������� �� ������ ����� ����������
    std::vector<Phrase> phrases; // ��������� ������� �� ������
    int currentPuzzle;

public:
    Game();
    void initializePuzzles();
    void initializePhrases();
    void setPlayerName(const std::string& playerName); // ���������� std::string
    const std::string& getPlayerName() const; // ���������� std::string
    int getPlayerScore() const;
    const std::string& getRandomPhrase() const; // ���������� std::string
    bool checkAnswer(int puzzleIndex, int answerIndex);
    void printPuzzle(int puzzleIndex) const;
    void printHint(int puzzleIndex) const;
    void startGame();
    void getAnswerAndCheck(int puzzleIndex);

    // ������ ��� ������������ ������ � ��������� ��������
    void printAllPuzzles();
    void demoTwoDimensionalArray();
};

#endif // GAME_H