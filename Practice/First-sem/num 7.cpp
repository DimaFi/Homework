#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i, j, a, b;
	j = 0;
	a = 0;
	b = 5;

	for (i = 0; i < 8; i+=2) {
		while (j <= i/2) {
			if (j == i/2) {
				cout << a + 1 << endl;
				j = 0;
				a++;
				break;
			}
			cout << a + 1 << ' ';
			j++;
		}
		while (j <= i/2) {
			if (j == i/2) {
				cout << b + 1 << endl;
				j = 0;
				b++;
				break;
			}
			cout << b + 1 << ' ';
			j++;
		}
	}

	return 0;
}
