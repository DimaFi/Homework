#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
	int n, i, max, maxi, m, j;

	cin >> n;
	int* a = new int [n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}


	for (i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			for (int j = i+1; j < n; j++) {
				a[j-1] = a[j];
			}
			n--;
		}
	}

	for (i = 0; i < n; i++) {
		cout << a[i];
	}



}
