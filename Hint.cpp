#define _CRT_SECURE_NO_WARNINGS
#include "Hint.h"

// ����������� �� ���������
Hint::Hint() : text("") {}

// ����������� � ����������
Hint::Hint(const std::string& hintText) : text(hintText) {}

// ����� ��� ��������� ������
const std::string& Hint::getText() const {
    return text;
}

// ����� ��� ��������� ������
void Hint::setText(const std::string& hintText) {
    text = hintText;
}