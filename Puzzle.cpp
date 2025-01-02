#define _CRT_SECURE_NO_WARNINGS
#include "Puzzle.h"
#include <iostream>

int Puzzle::puzzleCount = 0; // Инициализация статического поля

Puzzle::Puzzle() : correctAnswerIndex(0), attempts(0) {
    hints.resize(MAX_HINTS);
    options.resize(3);
    puzzleCount++; // Увеличиваем количество объектов при создании нового объекта
    std::cout << "\nСчётчик создания объектов Puzzle: " << puzzleCount << std::endl; // Отладочный вывод
}

Puzzle::Puzzle(const std::string& question, int correctAnswerIndex, const std::string& hintText1, const std::string& hintText2, const std::string& hintText3, const std::string& option1, const std::string& option2, const std::string& option3)
    : question(question), correctAnswerIndex(correctAnswerIndex), attempts(0) {
    hints.resize(MAX_HINTS);
    options.resize(3);
    hints[0].setText(hintText1);
    hints[1].setText(hintText2);
    hints[2].setText(hintText3);
    options[0].setText(option1);
    options[1].setText(option2);
    options[2].setText(option3);
    puzzleCount++; // Увеличиваем количество объектов при создании нового объекта
    std::cout << "\nСчётчик создания объектов Puzzle: " << puzzleCount << std::endl; // Отладочный вывод
}

const std::string& Puzzle::getQuestion() const {
    return question;
}

const std::string& Puzzle::getOption(int index) const {
    return options[index].getText();
}

const std::string& Puzzle::getHint(int index) const {
    return hints[index].getText();
}

int Puzzle::getCorrectAnswerIndex() const {
    return correctAnswerIndex;
}

int Puzzle::getAttempts() const {
    return attempts;
}

void Puzzle::incrementAttempts() {
    attempts++;
}

void Puzzle::resetAttempts() {
    attempts = 0;
}

int Puzzle::getPuzzleCount() {
    return puzzleCount; // Возвращаем количество объектов
}

// Использование оператора this
Puzzle& Puzzle::setQuestion(const std::string& newQuestion) {
    this->question = newQuestion;
    return *this;
}

// Дружественная функция
std::ostream& operator<<(std::ostream& os, const Puzzle& puzzle) {
    os << "Загадка (дружественная функция): " << puzzle.getQuestion() << "\n";
    return os;
}

// Перегрузка оператора +
Puzzle Puzzle::operator+(const Puzzle& other) const {
    Puzzle newPuzzle;
    newPuzzle.question = this->question + " " + other.question;
    return newPuzzle;
}

// Перегрузка оператора ++ (префиксный)
Puzzle& Puzzle::operator++() {
    ++attempts;
    return *this;
}

// Перегрузка оператора ++ (постфиксный)
Puzzle Puzzle::operator++(int) {
    Puzzle temp = *this;
    attempts++;
    return temp;
}