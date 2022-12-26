#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string s;
	char s1;
	int c = 0, i;
	cin >> s1;

	ifstream in("input.txt");
	ofstream out("output.txt");

	string* a = new string[50];

	getline(in, s);
	i = 0;
	while (i < s.length()-1){
		if (s[i] == s1) {
			a[c] = s[i + 1];
			c++;
			i += 2;
		}
		else {
			i++;
		}
	}

	for (i = 0; i < c; i++) {
		out << a[i] << ' ';
	}
	in.close();
	out.close();
}
