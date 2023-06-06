#include <iostream>
#include <vector>
#include <list>

using namespace std;

void replace(vector<int>& vec) {
    if (vec.size() < 2) {
        return;
    }

    int firstFrom10 = vec[0] % 10;

    vec[vec.size() - 2] = firstFrom10;
}


void removeMin(list<int>& lst) {
    if (lst.size() < 2) {
        return;
    }

    list<int>::iterator it = lst.end();
    int last = *(--it);
    int secLast = *(--it);

    if (last < secLast) {
        lst.erase(--it);
    }
    else {
        lst.pop_back();
    }
}


int main() {

    vector<int> vec = { 1, 2, 3, 4, 5 };

    replace(vec);

    for (int num : vec) {
        cout << num << " ";
    }


    list<int> lst = { 4, 2, 6, 8, 1 };

    removeMin(lst);

    for (int num : lst) {
        cout << num << " ";
    }

}
