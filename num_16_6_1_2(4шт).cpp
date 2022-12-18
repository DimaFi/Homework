#include <iostream>

using namespace std;

void f(int a, int b) {   // 2.1
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

void f(int a, int b, int n) {  // 2.2
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

void fm(int a, int b) {   //   2.3
	int c, i, j;
	c = 0;

	int max = -10000;

	for (i = a; i <= b; i++) {
		c = 0;
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				c++;
			}
		}
		if (c > max) {
			max = c;
		}
	}

	for (i = a; i <= b; i++) {
		c = 0;
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				c++;
			}
		}
		if (c == max) {
			cout << i << endl;
		}
	}

}

void f_4(int a, int b, int aa) {
	int c, i, j;
	c = 0;
	for (i = 1; i <= aa; i++) {
		if (aa % i == 0) {
			c++;
		}
	}
	int c1 = 0;

	for (i = aa+1; i <= b; i++) {
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				c1++;
			}
		}
		if (c1 == c) {
			cout << i << ' ' << c1 << " == " << c << " == count for A" << endl;
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
	f_4(a,b,aa);


}

/*  [ab] = [1 6]
*	1 - 1
*	2 - 2
*	3 - 2
*	4 - 3
*	5 - 2
*	6 - 4
* 
*	N del = 2
*	1 - 1 - None
*	2 - 2
*	3 - 2
*	4 - 3 - None
*	5 - 2
*	6 - 4 - None

	max del  = 4
	1 - 1 - None
*	2 - 2 - None
*	3 - 2 - None
*	4 - 3 - None
*	5 - 2 - None
*	6 - 4 
	
	A = 2 -> 2 del
	1 - 1 - None
*	2 - 2 == A
*	3 - 2 -> PRINT
*	
*/
