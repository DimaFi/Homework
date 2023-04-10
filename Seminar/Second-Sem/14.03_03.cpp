
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>


using namespace std;

template <typename x> void arrcin(x* a, int n) {
    for (int i = 0; i < n; i++) {
           cin >> a[i];
    }
}
template <typename x> void arrout(x* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
}
template <typename x> x fg(int n, x t) {
        x *a = new x [n];
        return *a;
}

int main(){
    int n, b, m;
    //int a;
    double a;
    cin >> n >> a;
    //int* h = new int[n];
    double* h = new double[n];
    *h = fg(n, a);
    arrcin(h, n);
    arrout(h, n);
}
