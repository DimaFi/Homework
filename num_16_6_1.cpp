#include <iostream>

using namespace std;

void f(int a, int b) {
	int c, i, j;
	for (i = a; i <= b; i++) {
		c = 0;
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				c++;
			}
		}
		cout << i << ' ' << c << endl;
	}
}

void f(int a, int b, int n) {
	int c, i, j;
	for (i = a; i <= b; i++) {
		c = 0;
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				c++;

			}
		}
		if (c == n) {
			cout << i << ' ' << c << endl;
		}
	}
}

void fm(int a, int b) {
	int c, i, j;
	int* k = new int[b - a];
	int* l = new int[b - a];

	for (i = a; i <= b; i++) {
		c = 0;
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				c++;
			}
		}
		k[i] = i;
		l[i] = c;
 		cout << i << ' ' << c << endl;
	}
}

int main()
{
	int n, a, b;

	cout << "Enter [a b]" << endl;
	cin >> a >> b;
	f(a, b);

	cout << "Enter N del" << endl;
	cin >> n;
	fm(a, b);


}
