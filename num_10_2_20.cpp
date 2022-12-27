#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

struct tab {
	string f, i, o;
	int course, group, res;


};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, h;
	double x;

	in >> n;
	in >> h;
	tab* a = new tab[n];
	for (int i = 0; i < n; i++) {
		in >> a[i].f >> a[i].i >> a[i].o >> a[i].course >> a[i].group >> a[i].res;
	}
	int c;
	c = n;
	for (int i = 0; i < n; i++) {
		if (a[i].res >= h) {
			out << a[i].f << ' ' << a[i].i << ' ' << a[i].o << ' ' << a[i].course << ' ' << a[i].group << ' ' << a[i].res << endl;
		}
	}
}

/* 
5
3
S V A 1 141 3
K D M 2 241 2
L P V 1 141 5
A P M 1 141 5
S V P 1 141 4
*/
