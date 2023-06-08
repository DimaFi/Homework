/*
Решить одну задачу с использованием вектора, другую – списка. Для обеих теоретически обосновать выбор контейнера.

Создать класс "чего-то" и класс "список <чего-то>". Выбрать контейнер исходя из операций.



4. Список компьютерных игр. Операции:

а) Удалить все шутеры. Переставить первую игру в конец списка.

б) Изменить названия всех квестов, приписав в начале вопросительный знак. Поменять местами первую и предпоследнюю игры.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Game {
public:
    string name;
    string genre;

    Game(const string& name, const string& genre) : name(name), genre(genre) {}
};

int main() {

    vector<Game> games;

    // emplace_back используется для добавления нового элемента в конец вектора (в общем случае в конец контейнера)

    games.emplace_back("Game 1", "Shooter");
    games.emplace_back("Game 2", "RPG");
    games.emplace_back("Game 3", "Shooter");
    games.emplace_back("Game 4", "Adventure");
    games.emplace_back("Game 5", "Shooter");

    // Удаление шутеров
    games.erase(remove_if(games.begin(), games.end(), [](const Game& game) {
        return game.genre == "Shooter";
        }), games.end());

    // Перестановка первой игры в конец списка
    rotate(games.begin(), games.begin() + 1, games.end());

    for (const auto& game : games) {
        cout << "Name: " << game.name << ", Genre: " << game.genre << endl;
    }

}
