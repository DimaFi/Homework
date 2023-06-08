// г) Расположение точек в порядке возрастания суммы координат:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> points = { {5, 6}, {1, 2}, {3, 4}, {9, 10}, {7, 8} };

    sort(points.begin(), points.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return (p1.first + p1.second) < (p2.first + p2.second);
        });


    for (const auto& p : points) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

}
