#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
struct point {
	int x, y, z;
};
int dlin(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}
int main() {


	point t[100];

	ifstream in("input.txt");
	ofstream out("output.txt");


	int i = 0;

	while (!in.eof()) {
		in >> t[i].x >> t[i].y >> t[i].z;
		i++;
	}

	int n,j, z, k;
	n = i;

	double max;
	max = dlin(t[0], t[1]);

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n; j++) {
			if (max < dlin(t[i], t[j])) {
				max = dlin(t[i], t[j]);
				z = i;
				k = j;
			}
		}
	}

	out << t[z].x << " " << t[z].y << " " << t[z].z << endl;
	out	<< t[k].x << " " << t[k].y << " " << t[k].z << endl;

	in.close();
	out.close();

}
