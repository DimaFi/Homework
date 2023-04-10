
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;
int main() {
    int n, max, mx;
    cin >> n;
    int *a = new int [n];
    int* b = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        max = -1e10;
        for (int i1 = 0; i1 < n; i1++) {
            if (a[i1] > max) {
                max = a[i1];
                mx = i1;
            }
        }
        a[mx] = -1e10;
        b[i] = max;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << '\n';
    }
}
