#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main()
{
    int i;
    double e, a, s;
    double f, st;

    cin >> e;
    a = e+e;
    f = 1;
    st = -5;
    s = -1;
    cout << "1|" << s << '|' << s << endl;
    i = 2;
    while (abs(a) >= e) {
        f *= (2 * i - 2) * (2 * i - 1);
        st *= 25;
        a = st / (5 * f);
        s += a;
        cout << fixed << setprecision(15) << i << '|' << s << '|' << a << endl;
        i++;
    }
}
