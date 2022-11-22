#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x, y;
    cin >> x >> y;
    if (y <= abs(x) && x*x + y*y <= 100) {
        if (y == abs(x) || (x*x + y*y == 100)) {
            cout << "На границе";
            return 0;
        }
        cout << "Да";
        return 0;
    }
    cout << "Нет";
    return 0;
}
