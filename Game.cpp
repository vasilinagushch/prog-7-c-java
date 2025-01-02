#define _CRT_SECURE_NO_WARNINGS
#define MAX_ATTEMPTS 3
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

Game::Game() : currentPuzzle(0) {}

// ������������� �������� ��� �������� ������� � ����
void Game::initializePuzzles() {
    puzzles.push_back(make_shared<Puzzle>("��� ����� ���� ����� � ����, �� ��� ���� �� ���������?", 0, "� ����� �������� ���� ���������.", "�� ������ ��������� ��� � ������.", "��� �������� ����� ������������ ����� �������.", "��������", "���������", "����"));
    puzzles.push_back(make_shared<Puzzle>("�� �� �����, �� �� �������, ���������� - � ����� �������.", 1, "��� ����������� ����������.", "� ���� ���� ������ � ����� �������.", "� ���� ��� �����.", "���������", "�������", "������"));
    puzzles.push_back(make_shared<Puzzle>("� ������ ��� ��� � ����� ��� ����. ��� � �����?", 1, "��� ��������� �������, ������� �� ������ ��������.", "��� ���������, ����� ���� ���������� �� �����������.", "�� ������ ������� ��� � ����� ��� �������.", "�����", "���", "�����"));
}

void Game::initializePhrases() {
    phrases.push_back(Phrase("� ���� ������� ������� �����.\n"));
    phrases.push_back(Phrase("� ���� ������� ������� �����.\n"));
    phrases.push_back(Phrase("��� ������� �������� �� �������.\n"));
}

void Game::setPlayerName(const std::string& playerName) {
    player = Player(playerName);
}

const std::string& Game::getPlayerName() const {
    return player.getName();
}

int Game::getPlayerScore() const {
    return player.getScore();
}

const std::string& Game::getRandomPhrase() const {
    int randomIndex = rand() % phrases.size();
    return phrases[randomIndex].getText();
}

bool Game::checkAnswer(int puzzleIndex, int answerIndex) {
    if (answerIndex == puzzles[puzzleIndex]->getCorrectAnswerIndex()) {
        player.incrementScore();
        return true;
    }
    else {
        puzzles[puzzleIndex]->incrementAttempts();
        return false;
    }
}

void Game::printPuzzle(int puzzleIndex) const {
    cout << "\n�������: " << puzzles[puzzleIndex]->getQuestion() << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ") " << puzzles[puzzleIndex]->getOption(i) << endl;
    }
}

void Game::printHint(int puzzleIndex) const {
    int attempts = puzzles[puzzleIndex]->getAttempts();
    if (attempts < MAX_HINTS) {
        cout << "���������: " << puzzles[puzzleIndex]->getHint(attempts) << endl;
    }
}

void Game::startGame() {
    for (currentPuzzle = 0; currentPuzzle < puzzles.size(); currentPuzzle++) {
        printPuzzle(currentPuzzle);
        getAnswerAndCheck(currentPuzzle);
    }
    cout << "���� ���������! " << getPlayerName() << " �����(�) " << getPlayerScore() << " �������." << endl;
    if (getPlayerScore() == 0) {
        cout << "�� �� ������ �� ����� �������. ���������� �����!\n" << endl;
        player.resetScore();
        startGame();
    }
}

void Game::getAnswerAndCheck(int puzzleIndex) {
    int answerIndex = 0;
    bool validInput = false;

    while (!validInput) {
        try {
            cout << "������� ����� ������ (1-3): ";
            cin >> answerIndex;
            if (cin.fail() || answerIndex < 1 || answerIndex > 3) {
                throw std::invalid_argument("������� ����� �� 1 �� 3.");
            }
            validInput = true;
        }
        catch (const std::invalid_argument& e) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << e.what() << endl;
        }
    }

    if (checkAnswer(puzzleIndex, answerIndex - 1)) {
        cout << "���������! �������!\n" << endl;
        cout << getRandomPhrase() << endl;
    }
    else {
        if (puzzles[puzzleIndex]->getAttempts() < MAX_ATTEMPTS) {
            printHint(puzzleIndex);
            getAnswerAndCheck(puzzleIndex);
        }
        else {
            cout << "��� ������� �������. ������� � ��������� �������.\n" << endl;
        }
    }
}

// ����� ��� ������������ ������ � ���������� �������� ��������
void Game::printAllPuzzles() {
    for (const auto& puzzle : puzzles) {
        cout << puzzle->getQuestion() << endl;
    }
}

// ����� ��� ������������ ������ � ��������� �������� ��������
void Game::demoTwoDimensionalArray() {
    vector<vector<shared_ptr<Puzzle>>> puzzleMatrix = {
        {puzzles[0], puzzles[1]},
        {puzzles[2], make_shared<Puzzle>("�������������� �������", 0, "��������� 1", "��������� 2", "��������� 3", "������� 1", "������� 2", "������� 3")}
    };

    for (const auto& row : puzzleMatrix) {
        for (const auto& puzzle : row) {
            cout << puzzle->getQuestion() << endl;
        }
    }
}