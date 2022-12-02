#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, i, s, f, x, y;

    f = x;
    s = 0;
    y = 1;
    cin >> n >> x;
    for (i = 1; i <= n; i++) {
        s += y * f;
        f *= x * x;
        y += 2;

    }
    cout << s;
}
