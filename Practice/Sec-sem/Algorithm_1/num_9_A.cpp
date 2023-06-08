// а) удалить все точки из нижней половины системы координат

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> points = { {1, -2}, {3, 4}, {5, -6}, {7, 8}, {9, 10} };

    points.erase(remove_if(points.begin(), points.end(), [](const pair<int, int>& p) {
        return p.second < 0;
        }), points.end());


    for (const auto& p : points) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
