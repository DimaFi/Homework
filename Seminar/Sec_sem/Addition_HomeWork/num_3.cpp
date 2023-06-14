

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string surname, name;
    int originalOrder;
    vector<int> scores;
};


/*
Используется функция count_if, чтобы подсчитать кол-во зачетов. 
Затем происходит сравнение количества зачетов. 
Если они не равны, то студенты сортируются по убыв количества зачетов. 
Если кол-во зачетов одинаково, то сравнивается фамилия. 
Если фамилии равны, то сравнивается исходный порядок студентов.

Для учет исходного порядка используется переменная originalOrder.
*/


bool compare_students(const student& s1, const student& s2) {
    int s1_count = count_if(s1.scores.begin(), s1.scores.end(), [](int score) { return score >= 65; });
    int s2_count = count_if(s2.scores.begin(), s2.scores.end(), [](int score) { return score >= 65; });

    if (s1_count != s2_count) {
        return s1_count > s2_count;
    }
    else {
        if (s1.surname != s2.surname) {
            return s1.surname < s2.surname;
        }
        else {
            return s1.originalOrder < s2.originalOrder;
        }
    }
}

ifstream in("input.txt");
ofstream out("output.txt");

int main() {

    int Number;
    in >> Number;

    vector<student> students;

    string surname, name;
    vector<int> scores;
    int originalOrder = 0;
    while (in >> surname >> name) {
        scores.resize(3);
        for (int i = 0; i < 3; i++) {
            in >> scores[i];
        }
        students.push_back({ surname, name, originalOrder, scores });
        originalOrder++;
    }

    stable_sort(students.begin(), students.end(), compare_students);

    out << Number << endl;

    for (const auto& s : students) {
        out << s.surname << " " << s.name << " " << " ";
        for (const auto& score : s.scores) {
            out << score << " ";
        }
        out << endl;
    }
}

/*
141
Bob Rose 5 65 75
Matthew Rose 35 95 100
Emily Rose 90 100 30
Benjamin James 100 40 20
Charlotte Elizabeth 99 99 99
William David 50 70 76
Olivia Grace 20 20 26
Samuel John 80 30 76
Samuel John 50 80 76
Alexander Daniel 75 100 76
Samuel John 50 30 80
Mia Olivia 50 30 76
Samuel John 80 30 76
William Joseph 100 30 76
Samuel John 50 30 75
Samuel John 50 30 76
Samuel John 50 30 70
Samuel John 50 30 65
Ava Nicole 76 78 76
Danny Lua 100 30 76
*/
