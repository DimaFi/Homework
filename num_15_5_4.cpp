#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;



int main()
{
    int c, n;
    double i;
    double e, a, s;
    double f, st;

    cin >> e;

    for (i = -1; i <= 0 ; i += 0.1) {
        a = e + e;
        st = i;
        s = 0;
        f = 2;
        c = 2;
        n = 1;
        while (abs(a) >= e) {
            if (n % 2 == 0) {
                s += st / f;
                
            } else {
                //if (n % 2 == 0) {
                s -= st / f;
                
            }
            n++;
            c += 2;
            st *= i * i;
            f *= c * (c - 1);
            a = st / f;
        }
        cout << fixed << setprecision(6) << i << ' ' << s << ' ' << n << endl;
    }
}
