
#include <iostream>

using namespace std;

void f(int a, int b) {   // 3.1
	int c, i, j,p;
	for (i = a; i <= b; i++) {
		c = 0;
		p = i;
		while (p != 0){

			c += p%10;
			p /= 10;
		}
		cout << i << ' ' << c << endl;
	}
}

void f(int a, int b, int n) {  // 3.2
	int c, i, j, p;
	for (i = a; i <= b; i++) {
		c = 0;
		p = i;
		while (p != 0) {

			c += p % 10;
			p /= 10;
		}
		if (c == n) {
			cout << i << ' ' << c << endl;
		}
	}
}

void fm(int a, int b) {   //   3.3
	int c, i, j, p;
	for (i = a; i <= b; i++) {
		c = 0;
		p = i;
		while (p != 0) {
			c += p % 10;
			p /= 10;
		}
		if (c % 2 != 0) {
				cout << i << ' ' << c << endl;
		}
	}
}

void f_4(int a, int b, int aa) {
	int c, i, j, p;
	c = 0;
	p =aa;
	while (p != 0) {
		c += p % 10;
		p /= 10;
	}

	int c1 = 0;

	for (i = aa + 1; i <= b; i++) {
		c1 = 0;
		p =i;
		while (p != 0) {
			c1 += p % 10;
			p /= 10;
		}
		if (c1 == c) {
			cout << i << ' ' << c1 << " == " << c << " == count for A" << endl;
			exit;
		}
	}
}


int main()
{
	int n, a, b, aa;

	cout << "Enter [a b]" << endl;
	cin >> a >> b;
	f(a, b);

	cout << "Enter N del" << endl;
	cin >> n;
	f(a, b, n);

	cout << "----------------------- " << endl;
	cout << "	--- max --- " << endl;
	fm(a, b);

	cout << "A - enter, AND A < b " << endl;
	cin >> aa;
	f_4(a, b, aa);


}
