#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> setic;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (i == 0) {
            while (x > 0) {
                setic.insert(x % 10);
                x /= 10;
            }
        }
        else {
            set<int> temp;
            while (x > 0) {
                temp.insert(x % 10);
                x /= 10;
            }
            set<int> set3;
            set_intersection(setic.begin(), setic.end(), temp.begin(), temp.end(), inserter(set3, set3.begin()));
            setic = set3;
        }
    }


    for (auto i = setic.begin();i!=setic.end();i++) {
        cout << *i << " ";
    }

    return 0;
}
