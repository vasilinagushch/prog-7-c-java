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

// Инициализация векторов для хранения загадок и фраз
void Game::initializePuzzles() {
    puzzles.push_back(make_shared<Puzzle>("Что может идти вверх и вниз, но при этом не двигается?", 0, "У этого предмета есть ступеньки.", "Ты можешь встретить его в здании.", "Это помогает людям перемещаться между этажами.", "Лестница", "Эскалатор", "Лифт"));
    puzzles.push_back(make_shared<Puzzle>("То ли зебра, то ли лесенка, прикоснись - и будет песенка.", 1, "Это музыкальный инструмент.", "У него есть черные и белые клавиши.", "У него нет струн.", "Эскалатор", "Пианино", "Гитара"));
    puzzles.push_back(make_shared<Puzzle>("Я говорю без рта и слышу без ушей. Что я такое?", 1, "Это природное явление, которое ты можешь услышать.", "Оно возникает, когда звук отражается от поверхности.", "Ты можешь слышать его в горах или пещерах.", "Голос", "Эхо", "Ветер"));
}

void Game::initializePhrases() {
    phrases.push_back(Phrase("У дома Круэллы красная крыша.\n"));
    phrases.push_back(Phrase("У дома Круэллы красная дверь.\n"));
    phrases.push_back(Phrase("Дом Круэллы построен из кирпича.\n"));
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
    cout << "\nЗагадка: " << puzzles[puzzleIndex]->getQuestion() << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ") " << puzzles[puzzleIndex]->getOption(i) << endl;
    }
}

void Game::printHint(int puzzleIndex) const {
    int attempts = puzzles[puzzleIndex]->getAttempts();
    if (attempts < MAX_HINTS) {
        cout << "Подсказка: " << puzzles[puzzleIndex]->getHint(attempts) << endl;
    }
}

void Game::startGame() {
    for (currentPuzzle = 0; currentPuzzle < puzzles.size(); currentPuzzle++) {
        printPuzzle(currentPuzzle);
        getAnswerAndCheck(currentPuzzle);
    }
    cout << "Игра завершена! " << getPlayerName() << " решил(а) " << getPlayerScore() << " загадок." << endl;
    if (getPlayerScore() == 0) {
        cout << "Вы не решили ни одной загадки. Попробуйте снова!\n" << endl;
        player.resetScore();
        startGame();
    }
}

void Game::getAnswerAndCheck(int puzzleIndex) {
    int answerIndex = 0;
    bool validInput = false;

    while (!validInput) {
        try {
            cout << "Введите номер ответа (1-3): ";
            cin >> answerIndex;
            if (cin.fail() || answerIndex < 1 || answerIndex > 3) {
                throw std::invalid_argument("Введите число от 1 до 3.");
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
        cout << "Правильно! Молодец!\n" << endl;
        cout << getRandomPhrase() << endl;
    }
    else {
        if (puzzles[puzzleIndex]->getAttempts() < MAX_ATTEMPTS) {
            printHint(puzzleIndex);
            getAnswerAndCheck(puzzleIndex);
        }
        else {
            cout << "Три попытки истекли. Переход к следующей загадке.\n" << endl;
        }
    }
}

// Метод для демонстрации работы с одномерным массивом объектов
void Game::printAllPuzzles() {
    for (const auto& puzzle : puzzles) {
        cout << puzzle->getQuestion() << endl;
    }
}

// Метод для демонстрации работы с двумерным массивом объектов
void Game::demoTwoDimensionalArray() {
    vector<vector<shared_ptr<Puzzle>>> puzzleMatrix = {
        {puzzles[0], puzzles[1]},
        {puzzles[2], make_shared<Puzzle>("Дополнительная загадка", 0, "Подсказка 1", "Подсказка 2", "Подсказка 3", "Вариант 1", "Вариант 2", "Вариант 3")}
    };

    for (const auto& row : puzzleMatrix) {
        for (const auto& puzzle : row) {
            cout << puzzle->getQuestion() << endl;
        }
    }
}