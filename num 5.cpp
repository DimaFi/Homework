#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x, y;
	char op;
	cin >> x >> y >> op;
	switch (op) {
	case '+':
		cout << x + y;
		break;

	case '-':
		cout << x - y;
		break;

	case '*':
		cout << x * y;
		break;

	case '/':
		cout << x / y;
		break;

	default :
		cout << "бРЕД";
		break;
	} 
	return 0;
}
