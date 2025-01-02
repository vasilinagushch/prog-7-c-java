#define _CRT_SECURE_NO_WARNINGS
#include "Option.h"

// ����������� �� ���������
Option::Option() : text("") {}

// ����������� � ����������
Option::Option(const std::string& optionText) : text(optionText) {}

// ����� ��� ��������� ������
const std::string& Option::getText() const {
    return text;
}

// ����� ��� ��������� ������
void Option::setText(const std::string& optionText) {
    text = optionText;
}
