#include <iostream>
#include <cmath>

using namespace std;



int main()
{
	double k, i,f = 1, s = 0, st = 1, p;
	cin >> k;
	for (i = 1; i <= k; i++) {
		p = i * i;
		st *= 2;
		f *= i;
		s += (st * f) / p;

	}
	cout << s;
}
