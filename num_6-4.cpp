#include <iostream>


using namespace std;


int main()
{
    int n, i, j, c;

    cin >> n; // long strok stolb

    int** m = new int* [n];

    for (i = 0; i < n; i++) {
        m[i] = new int[n];
        for (j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int* p = new int[n];

    for (i = 0; i < n; i++) {
        c = 0;
        for (j = 1; j < n; j++) {
            if (m[i][j - 1] != m[i][j]) {
                c++;
                p[i] = c;
                break;
            }
            else {
                c++;
            }
            if (j == n - 1) {
                p[i] = -1;
            }
        }

    }

    for (i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
}
