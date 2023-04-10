
#include <iostream>
#include <cmath>

using namespace std;



int main()
{
	float n, i;
	int a1, a2, a3;

	cin >> n;
	a1 = 0;
	for (i = 1; i <= n; i++) {
		if (i == 1) {
			cout << i << ' ' << a1 << endl;
			
		}

		if (i > 2) {
			a2 = a1 + 3;
			a3 = 2 * a2;
			cout << i << ' ' << a3 << endl;
			a1 = a2;
			a2 = a3;
		}

		if (i == 2) {
			a2 = a1 + 3;
			a3 = 2 * a2;
			cout << i << ' ' << a2 << endl;
			cout << i + 1 << ' ' << a3 << endl;
			a1 = a2;
			a2 = a3;
			i++;
		}
	}
}
