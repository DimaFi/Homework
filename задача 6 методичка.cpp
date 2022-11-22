#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, i;
    cin >> a >> b;

    for (i = a; i < b + 1; i++) {
        if (i > 0) {
            cout << i;
        }
    }
    i = a;
    cout << " " << endl;
    while (i < b + 1) {
        if (i > 0) {
            cout << i;
        }
        i++;

    }
    i = a;
    cout << " " << endl;
    do {
        if (i > 0) {
            cout << i;
        }
        i++;
    } while (i < b + 1);

    return 0;
}
