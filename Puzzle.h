#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <vector>
#include "Option.h"
#include "Hint.h"

#define MAX_HINTS 3

class Puzzle {
private:
    std::string question;
    std::vector<Option> options; // Используем вектор для хранения опций
    int correctAnswerIndex;
    std::vector<Hint> hints; // Используем вектор для хранения подсказок
    int attempts;

    static int puzzleCount; // Статическое поле для подсчета количества объектов

public:
    Puzzle();
    Puzzle(const std::string& question, int correctAnswerIndex, const std::string& hintText1, const std::string& hintText2, const std::string& hintText3, const std::string& option1, const std::string& option2, const std::string& option3);

    const std::string& getQuestion() const;
    const std::string& getOption(int index) const;
    const std::string& getHint(int index) const;
    int getCorrectAnswerIndex() const;
    int getAttempts() const;
    void incrementAttempts();
    void resetAttempts();

    static int getPuzzleCount(); // Статический метод для получения количества объектов

    // Использование оператора this
    Puzzle& setQuestion(const std::string& newQuestion);

    // Дружественная функция
    friend std::ostream& operator<<(std::ostream& os, const Puzzle& puzzle);

    // Перегрузка операторов
    Puzzle operator+(const Puzzle& other) const;
    Puzzle& operator++(); // Префиксный инкремент
    Puzzle operator++(int); // Постфиксный инкремент
};

#endif // PUZZLE_H