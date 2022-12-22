#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, ss;
    string s, s1, s2;
    cin >> s >> s1 >> s2;



    for (i = 0; i < s.length(); i++) {
        if (s.find(s1, i) == i) {
            s.insert(i + 1, s2);
        }
    }

    cout << s;
}
