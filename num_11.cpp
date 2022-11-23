#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	float a1 =0, a2, n, i;

	cin >> n;
	cout << a1 << endl;
	for (i = 1; i < n; i += 0.5) {
		a2 = a1 + 3;
		cout << a2 << endl;
		a1 = a2;
	}
	return 0;
} 
