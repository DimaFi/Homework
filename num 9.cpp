#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
	if (x == 1 || x == 0.25) {
		return -0.00001;
	}
	else {
		return (1. / (x - 1) + 2. / (1 - 4 * x));
	}
}


int main()
{
	double a, b, i, h;
	cin >> a >> b >> h;
	cout << "y" << ' ' << "x" << endl;

	for (i = a; i < b + 1; i+=h) {
		if (f(i) == -0.00001) {
			cout << "None" << ' ' << i << endl;
		}
		else {
			cout << f(i) << ' ' << i << endl;
		}
	}
	return 0;
}
