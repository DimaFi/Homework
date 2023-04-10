
#include <iostream>
#include <cmath>

using namespace std;

void f(int &a) {
	cout << ((a % 10) * 10) + a / 10;
}


int main()
{
	int a;
	cin >> a;
	f(a);
	return 0;
}

// сверху новое, снизу старое



/*#include <iostream>
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

// через void функцию и через ссылку передать
