#pragma once
#ifndef OPTION_H
#define OPTION_H

#include <string>

class Option {
private:
    std::string text; // ���������� std::string ��� ������ �����

public:
    Option(); // ����������� �� ���������
    Option(const std::string& optionText); // ����������� � ����������
    const std::string& getText() const; // ����� ��� ��������� ������
    void setText(const std::string& optionText); // ����� ��� ��������� ������
};

#endif // OPTION_H