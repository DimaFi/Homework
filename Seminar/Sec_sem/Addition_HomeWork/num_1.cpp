/* Напишите рекурсивную функцию f(n), выводящую:
54321
 4321
  321
   21
    1
    12
    123
    1234
    12345
*/

#include <iostream>

using namespace std;

void print(int n) {

    int c = 0, k = 0, p = n;

    while (k != (n * 2)-1) {

        if (k >= n) {
            for (int j = 0; j < n-1; j++) {
                cout << ' ';
            }
            for (int i = 1; i <= p; i++) {
                cout << i;
            }
            p++;
            cout << endl;
        }
        else {
            for (int j = 0; j < c; j++) {
                cout << ' ';
            }
            for (int i = p; i >= 1; i--) {
                cout << i;
            }
            p--;
            c++;
            cout << endl;
        }
        if (p == 0) {
            p+=2;
        }
        k++;
    }
}

int main() {
    int n = 5;
    // cin >> n;
    print(n);
}
