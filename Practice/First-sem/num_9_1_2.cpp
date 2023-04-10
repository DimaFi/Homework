#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string s, a;
	int c = 0;

	ifstream in("input.txt");
	ofstream out("output.txt");

	while (in.peek() != EOF) {
		getline(in, s, '\n');
		if (s[0] == s[s.length()-1]) {
			c++;
		}
	}
	out << c;
	in.close();
	out.close();
}
