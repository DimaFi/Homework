#include <iostream>


using namespace std;


int main()
{
    int n, i, j, c;

    cin >> n;

    int* p = new int[2*n];
    c = 0;
    for (i = 0; i < n; i++) {

        cin >> p[c];
        if (p[c] % 2 == 0) {
            p[c + 1] = p[c];
            p[c] = -22;
            c+=2;
        }
        else {
            c++;
        }
    }

    for (i = 0; i < c; i++) {
        cout << p[i] << ' ';
    }
}
