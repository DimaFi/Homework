#include <iostream>

using namespace std;

int main() {
	int n, i, max, maxi;

	cin >> n;
	max = -10000;
	maxi = 0;
	int* a = new int[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (i = 0; i < n; i++) {
		if (a[i] >= max) {
			max = a[i];
			maxi = i;
		}
	}
	cout << maxi;
}
