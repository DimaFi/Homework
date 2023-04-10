
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void ff(int x, int p, int k, int it) {
	if (it <= x + 1) {
		for (int i = 0; i < p; i++)
			cout << ' ';
		for (int i = 0; i < k; i++)
			cout << '*';
		cout << '\n';
		return ff(x, p - 1, k + 2, it + 1);
	}
}

void trs(int n, int x, int p) {
	if (x <= n) {
		ff(x, p, 1, 1);
		return trs(n, x + 1, p);
	}
}

int main() {
	int n; cin >> n;
	trs(n, 1, n);
}
