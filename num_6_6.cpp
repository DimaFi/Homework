#include <iostream>


using namespace std;


int main()
{
    int n, i, j, i1, j1, c, m, a ,b;

    cin >> n >> m >> a >> b;

    int** p = new int*[n];
    c = 0;
    for (i = 0; i < n; i++) {
        p[i] = new int[m];
        for (j = 0; j < m; j++) {
            cin >> p[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        c = 1;
        for (j = 0; j < m; j++) {
            if (p[i][j] >= a && p[i][j] <= b) {
                c++;
            }

        }
        if (c == m){
            for (i1 = i; i < n-1; i++) {
                for (j = 0; j < m; j++) {
                    p[i][j] = p[i + 1][j];
                }
            }
            n--;
        }
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
}
