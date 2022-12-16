#include <iostream>

using namespace std;

int main() {
	int n, i, a,b,j, c;
	cin >> n >> a >> b;

	int* k = new int[n];

	for (i = 0; i < n; i++) {
		cin >> k[i];
		for (j = a; j <= b; j++) {
			if (k[i] == j) {
				k[i] = 0;
				break;
			}
		}
	}
	c = 0;
	for (i = 0; i < n; i++) {
		if (k[i] != 0) {
			c++;
			cout << k[i] << ' ';
		}
		
	}
	cout << endl;
	cout << "Count 1mern - " << c << endl;


	cout << "n1 m" << endl;
	int n1,m;
	cin >> n1 >> m;


	int **p = new int*[n1];

	for (i = 0; i < n; i++) {
		p[i] = new int[m];
		for (j = a; j <= b; j++) {
			cin >> p[i][j];
		}
	}

	c = 0;


	for (i = 0; i < n1; i++) {
		for (j = 0; j < m; j++) {
			if (p[i][j] != 0) {
				c++;
				cout << p[i] << ' ';
			}
		}
		cout << endl;
		
	}
	cout << "Count 2mern - " << c << endl;

}
