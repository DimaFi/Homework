#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string surname, name, fathername;
    int birthYear;
    vector<int> scores;
};


bool compare_students(const student& s1, const student& s2) {
    if (s1.surname != s2.surname) {
        return s1.surname < s2.surname;
    }
    else {
        return s1.birthYear > s2.birthYear;
    }
}

ifstream in("input.txt");
ofstream out("output.txt");

int main() {

    int Number;
    in >> Number;

    vector<student> students;

    string surname, name, fathername;
    int birthYear;
    vector<int> scores;
    while (in >> surname >> name >> fathername >> birthYear) {
        scores.resize(5);
        for (int i = 0; i < 5; i++) {
            in >> scores[i];
        }
        students.push_back({ surname, name, fathername, birthYear, scores });
    }

    sort(students.begin(), students.end(), compare_students);

    out << Number << endl;

    for (const auto& s : students) {
        out << s.surname << " " << s.name << " " << s.fathername << " " << s.birthYear << " ";
        for (const auto& score : s.scores) {
            out << score << " ";
        }
        out << endl;
    }

}

/*
141
Bob Rose Green 1000 5 5 5 5 5
Matthew Rose Turner 1996 4 2 3 5 1
Emily Rose Johnson 1995 2 1 5 4 3
Benjamin James Smith 1987 5 1 3 4 2
Charlotte Elizabeth Brown 2001 4 3 2 1 5
William David Taylor 1978 1 2 4 5 3
Olivia Grace Wilson 1998 3 4 5 2 1
Ethan Michael Davis 1992 1 5 2 3 4
Sophia Marie White 2004 2 1 3 4 5
Alexander Joseph Lee 1985 5 4 3 2 1
Lucas Thomas Martin 1990 1 2 5 4 3
Ava Nicole Anderson 2006 3 1 4 5 2
Jacob Ryan Mitchell 1983 5 4 1 2 3
Mia Elizabeth Cooper 1999 2 5 4 1 3
Noah Alexander King 1993 4 3 5 2 1
Lily Victoria Parker 2002 1 3 2 5 4
Samuel John Nelson 1991 2 2 2 2 2
Grace Olivia Adams 1997 2 4 1 5 3
Daniel Christopher Clark 1982 3 2 1 5 4
Chloe Madison Wright 2005 4 5 3 1 2
Samuel John Nelson 1990 0 0 0 0 0
Samuel John Nelson 1991 2 2 1 3 5
Samuel John Nelson 1991 4 2 2 2 2
Alexander Daniel Garcia 2002 3 4 3 2 4
Samuel John Nelson 1991 1 2 2 2 2
Mia Olivia Jackson 2004 5 5 5 4 5
Samuel John Nelson 1991 0 0 0 0 0
William Joseph Hernandez 2001 2 2 3 3 2
Samuel John Nelson 2990 5 2 5 3 5
Samuel John Nelson 2991 2 2 5 3 5
Samuel John Nelson 2991 1 2 5 3 5
Samuel John Nelson 2991 0 2 5 3 5
Ava Nicole Martinez 2003 5 3 4 4 4
Benjamin Michael Brown 2002 4 5 4 3 5
Bob Rose Green 1980 1 1 1 1 1
Sophia Elizabeth Davis 2005 4 4 3 5 4
Ethan James Kim 2001 3 2 2 3 4
Emily Grace Lee 2004 5 4 5 4 5
Lucas Alexander Rodriguez 2002 3 2 4 3 2
Danny Lua Kennen 2000 1 3 4 5 5
*/
