#include <iostream>

using namespace std;

int main() {
	int n, i, a, b, j, c, x, n1, m;
	cout << "n - count, [a,b] |  (n,a,b)" << endl;
	cin >> n >> a >> b;

	int r[1000];

	for (i = 0; i < n; i++) {
		cin >> r[i];
		for (j = a; j <= b; j++) {
			if (r[i] == j) {
				r[i] = 0;
				break;
			}
		}
	}
	c = 0;



	for (i = 0; i < n; i++) {
		if (r[i] != 0) {
			c++;
			cout << r[i] << ' ';
		}

	}



	cout << endl;
	cout << "Count stat odnom- " << c << endl;

	cout << "------------------------------------------" << endl;


	cout << "n1 m" << endl;
	cin >> n1 >> m;

	int p1[50][50];

	for (i = 0; i < n1; i++) {
		for (j = 0; j < m; j++) {
			cin >> p1[i][j];
		}
	}

	c = 0;

	for (i = 0; i < n1; i++) {
		for (j = 0; j < m; j++) {
			if (p1[i][j] >= a && p1[i][j] <= b) {
				p1[i][j] = 0;
			}
		}
	}


	for (i = 0; i < n1; i++) {
		for (j = 0; j < m; j++) {
			if (p1[i][j] != 0) {
				c++;
				cout << p1[i][j] << ' ';
			}
		}
		cout << endl;

	}
	cout << "Count stat dvym - " << c << endl;

	n1 = 0;
	m = 0;

	cout << "------------------------------------------" << endl;


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

	cout << "------------------------------------------" << endl;


	cout << "n1 m" << endl;
	cin >> n1 >> m;


	int** p = new int* [n1];

	for (i = 0; i < n1; i++) {
		p[i] = new int[m];
		for (j = 0; j < m; j++) {
			cin >> p[i][j];
		}
	}

	c = 0;

	for (i = 0; i < n1; i++) {
		for (j = 0; j < m; j++) {
			if (p[i][j] >= a && p[i][j] <= b) {
				p[i][j] = 0;
			}
		}
		cout << endl;

	}


	for (i = 0; i < n1; i++) {
		for (j = 0; j < m; j++) {
			if (p[i][j] != 0) {
				c++;
				cout << p[i][j] << ' ';
			}
		}
		cout << endl;

	}
	cout << "Count 2mern - " << c << endl;

	cout << "------------------------------------------" << endl;

}
