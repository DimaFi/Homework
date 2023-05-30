#include <iostream> 
#include <set> 
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<char> setic;

    for (int i = 0; i < n; i++) {
        string x;
        getline(cin, x);

        for (int j = 0; j < x.size(); j++) {
            if (ispunct(x[j])) {
                setic.insert(x[j]);
            }
        }
        
        for (auto it = setic.begin(); it != setic.end(); it++) {
            if (setic.count(*it) == 1) {
                cout << *it << ' ';
            }
        }

        cout << endl;

        setic.clear();
    }

}
