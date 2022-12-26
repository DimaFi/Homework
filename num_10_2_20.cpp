#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
struct point {
	int x, y;
};
double dlin(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {


	point t[100];

	ifstream in("input.txt");
	ofstream out("output.txt");


	int i = 0;

	while (!in.eof()) {
		in >> t[i].x >> t[i].y;
		i++;
	}

	int n, j, z = 0, k = 0, u = 0, p;
	n = i;

	double min, min1, min2;
	min = 100000;
	min1 = 100000;
	min2 = 100000;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (p = 0; p < n; p++){
				if (min > dlin(t[j], t[p]) && i != j && j != p && i != p) {
					min = dlin(t[j], t[p]);
					if (min1 > dlin(t[j], t[i]) && i != j && j != p && i != p) {
						min1 = dlin(t[j], t[i]);
						if (min2 > dlin(t[p], t[i]) && i != j && j != p && i != p) {
							min2 = dlin(t[p], t[i]);
							z = i;
							k = j;
							u = p;
						}
					}
				}
			}
		}
	}

	out << dlin(t[z],t[k]) + dlin(t[k],t[u]) + dlin(t[u],t[z]) << endl;
	out << t[z].x << t[z].y << endl;
	out << t[k].x << t[k].y << endl;
	out << t[u].x << t[u].y << endl;

	in.close();
	out.close();
}
