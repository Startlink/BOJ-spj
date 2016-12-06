#include <cstdio>
#include <cassert>
using namespace std;

int n;
struct Point {
	int x, y;
};
Point pt[5000];
bool appeared[5000];
int outarr[5000];

inline int ccw(const Point& a, const Point& b, const Point& c) {
	long long res = (long long)a.x * (b.y - c.y) + (long long)b.x * (c.y - a.y) + (long long)c.x * (a.y - b.y);
	if (res == 0) {
		return 0;
	}
	return res > 0 ? 1 : -1;
}

int main(int agrc, char **argv) {
	FILE *in = fopen(argv[1], "r");
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; ++i) {
		fscanf(in, "%d %d", &pt[i].x, &pt[i].y);
	}
	fclose(in);

	FILE *out = fopen(argv[3], "r");
	int cnt, v;
	assert(fscanf(out, "%d", &cnt) == 1);
	assert(cnt == n);
	for (int i = 0; i < n; ++i) {
		assert(fscanf(out, "%d", &v) == 1);
		assert(1 <= v && v <= n);
		--v;
		assert(appeared[v] == false);
		appeared[v] = true;
		outarr[i] = v;
	}
	assert(fscanf(out, "%d", &v) == EOF);
	fclose(out);

	for (int i = 0; i + 2 < n; ++i) {
		assert(ccw(pt[outarr[i]], pt[outarr[i + 1]], pt[outarr[i + 2]]) > 0);
	}

	return 0;
}
