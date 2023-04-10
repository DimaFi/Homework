#include <iostream>

using namespace std;

int main() {
	int n, i, max, maxi, m,j;

	cin >> n >> m;
	int** a = new int*[n];
	for (i = 0; i < n; i++) {
		a[i] = new int[m];
		for (j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int k = 0;
	if (m % 2 == 0) {
		for (i = 0; i < n; i++) {
			swap(a[i][m / 2 - 1], a[i][m / 2]);
		}
	}
	else {
		for (i = 0; i < n; i++) {
			swap(a[i][0], a[i][m / 2]);
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	
}
