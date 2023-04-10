#include <iostream>

using namespace std;


int main()
{
    int n,i,j;
    cin >> n;
    int* a = new int[2*n];
    
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    m = n;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            for (j = n; j > i; j--) {
                a[j] = a[j - 1];
            }
            n++;
            i++;
            a[i] = -5;
        }
    }

    for (i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
}
