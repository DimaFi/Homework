// в) Нахождение последней точки, удаленной от начала координат не менее чем на 10:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> points = { {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10} };

    auto lastPoint = find_if(points.rbegin(), points.rend(), [](const pair<int, int>& p) {
        return (p.first * p.first + p.second * p.second) >= 100;
        });

    if (lastPoint != points.rend()) {
        cout << "(" << lastPoint->first << ", " << lastPoint->second << ")" << endl;
    }

}
