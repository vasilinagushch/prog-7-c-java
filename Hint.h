#pragma once
#ifndef HINT_H
#define HINT_H

#include <string>

class Hint {
private:
    std::string text; // Используем std::string для текста подсказки

public:
    Hint(); // Конструктор по умолчанию
    Hint(const std::string& hintText); // Конструктор с параметром
    const std::string& getText() const; // Метод для получения текста
    void setText(const std::string& hintText); // Метод для установки текста
};

#endif // HINT_H