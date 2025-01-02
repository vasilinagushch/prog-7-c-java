// main.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>
#include <algorithm>
#include "Game.h"
#include "Player.h"
#include "AdvancedPlayer.h"
#include "Puzzle.h"

using namespace std;

#define MAX_HINT_LENGTH 200
#define MAX_OPTION_LENGTH 100
#define MAX_PHRASE_LENGTH 100
#define MAX_PUZZLES 3
#define MAX_ATTEMPTS 3
#define MAX_PHRASES 3
#define MAX_HINTS 3

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); // Инициализация генератора случайных чисел

    Game game;

    // Полиморфизм с использованием умных указателей и контейнеров STL
    vector<shared_ptr<Player>> players;

    // Работа с "статической" переменной
    cout << "\nВведите ваше имя (используя английские символы): ";
    char name[MAX_OPTION_LENGTH];
    cin >> name;
    shared_ptr<Player> staticPlayer = make_shared<Player>(name);
    players.push_back(staticPlayer);

    // Работа с динамической переменной
    shared_ptr<Player> dynamicPlayer = make_shared<Player>(*staticPlayer);
    game.setPlayerName(dynamicPlayer->getName());
    game.initializePuzzles();
    game.initializePhrases();
    game.startGame();

    // Работа с контейнером объектов класса
    int numPlayers;
    cout << "Введите количество игроков: ";
    cin >> numPlayers;

    for (int i = 0; i < numPlayers; i++) {
        cout << "Введите имя игрока " << i + 1 << ": ";
        cin >> name;
        if (i % 2 == 0) {
            players.push_back(make_shared<Player>(name)); // Добавление обычного игрока
        }
        else {
            players.push_back(make_shared<AdvancedPlayer>(name)); // Добавление продвинутого игрока
        }
    }

    // Демонстрация полиморфизма и сортировка по имени
    sort(players.begin(), players.end(),
        [](const shared_ptr<Player>& a, const shared_ptr<Player>& b) { return a->getName() < b->getName(); });

    // Демонстрация работы с контейнером объектов
    cout << "\nВсе игроки (отсортированные по имени):" << endl;
    for (const auto& player : players) {
        player->printInfo();
    }

    // Демонстрация поиска игрока по имени
    string searchName;
    cout << "Введите имя для поиска игрока: ";
    cin >> searchName;
    auto it = find_if(players.begin(), players.end(),
        [&searchName](const shared_ptr<Player>& player) { return player->getName() == searchName; });

    if (it != players.end()) {
        cout << "Игрок найден: " << (*it)->getName() << endl;
    }
    else {
        cout << "Игрок не найден" << endl;
    }

    // Демонстрация работы с одномерным массивом объектов
    cout << "\nВсе загадки:" << endl;
    game.printAllPuzzles();

    // Демонстрация работы с двумерным массивом объектов
    cout << "\nДвумерный массив загадок:" << endl;
    game.demoTwoDimensionalArray();

    return 0;
}