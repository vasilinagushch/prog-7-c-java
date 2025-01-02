#pragma once
#ifndef PHRASE_H
#define PHRASE_H

#include <string>

class Phrase {
private:
    std::string text; // ���������� std::string ��� ������ �����

public:
    Phrase(); // ����������� �� ���������
    Phrase(const std::string& phraseText); // ����������� � ����������
    const std::string& getText() const; // ����� ��� ��������� ������
    void setText(const std::string& phraseText); // ����� ��� ��������� ������
};

#endif // PHRASE_H