#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
	if (x < 0) {
		return 0.2 * x * x - x - 0.1;
	}
	else if (x > 0 && x != 0.1){
		return double(x*x)/x-0.1;
	}
	else if (x == 0.1){
		return 0;
	}
	else {
		return 0.0000010901;
	}
}


int main()
{
	double a, b, i, h;
	cin >> a >> b >> h;
	cout << "y" << ' ' << "x" << endl;

	for (i = a; i < b + 1; i+= h) {
		if (f(i) == 0.0000010901) {
			cout << "None" << ' ' << i << endl;
		}
		else {
			cout << f(i) << ' ' << i << endl;
		}
	}
	return 0;
}
