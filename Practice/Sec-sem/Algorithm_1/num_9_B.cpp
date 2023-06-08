// б) Подсчет количества точек, лежащих на одной вертикальной или горизонтальной прямой с данной

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> points = { {1, 2}, {3, 2}, {5, 6}, {7, 2}, {9, 10} };

    pair<int, int> Point = { 3, 2 };

    int count = count_if(points.begin(), points.end(), [&](const pair<int, int>& p) {
        return p.first == Point.first || p.second == Point.second;
        });

    cout << "Count: " << count << endl;

}
