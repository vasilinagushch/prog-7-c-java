#define _CRT_SECURE_NO_WARNINGS
#include "Phrase.h"

// ����������� �� ���������
Phrase::Phrase() : text("") {}

// ����������� � ����������
Phrase::Phrase(const std::string& phraseText) : text(phraseText) {}

// ����� ��� ��������� ������
const std::string& Phrase::getText() const {
    return text;
}

// ����� ��� ��������� ������
void Phrase::setText(const std::string& phraseText) {
    text = phraseText;
}