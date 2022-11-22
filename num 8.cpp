#include <iostream>
#include <cmath>

using namespace std;

int f(int a) {
	int c, d;
	c = a % 10;
	d = a / 10;
	return (c *10) + d;
}


int main()
{
	int a;
	cin >> a;
	cout << f(a);
	return 0;
}
