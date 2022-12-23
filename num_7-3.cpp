#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, ss,c;
    string s, s1;
    char s2;

    getline(cin, s);

    cin >> s2;
    c = 0;

    s1 = ' ';

    bool fl = 1;

    for (i = 0; i < s.length(); i++) {
        if (s[i]==' '|| i+1 == s.length()) {
            if (fl) {
                cout << s.substr(c, i - c) << ' ';
            }
            c = i;
            fl = false;

        }
        if (s[i] == s2) {
            fl = 1;
        }
    }

}
