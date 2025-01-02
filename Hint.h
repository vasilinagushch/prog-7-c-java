#pragma once
#ifndef HINT_H
#define HINT_H

#include <string>

class Hint {
private:
    std::string text; // ���������� std::string ��� ������ ���������

public:
    Hint(); // ����������� �� ���������
    Hint(const std::string& hintText); // ����������� � ����������
    const std::string& getText() const; // ����� ��� ��������� ������
    void setText(const std::string& hintText); // ����� ��� ��������� ������
};

#endif // HINT_H