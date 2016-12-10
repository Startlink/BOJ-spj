#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

struct Point {
	double x, y;
	Point operator+(const Point& r) const {
		return Point{ x + r.x, y + r.y };
	}
	Point operator*(const double r) const {
		return Point{ x * r, y * r };
	}
};
int n;
Point poly[2000];
char buf[1000];

inline double dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double distPointSeg(Point l0, Point l1, Point p) {
	for (int loop = 0; loop < 100; ++loop) {
		double d0 = dist(l0, p);
		double d1 = dist(l1, p);
		if (d0 < d1) {
			l1 = (l0 + l1) * 0.5;
		}
		else {
			l0 = (l0 + l1) * 0.5;
		}
	}
	return dist(l0, p);
}

inline double isLeft(Point p0, Point p1, Point p2) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool isInPolygon(Point p) {
	int wn = 0;
	for (int i = 0; i < n; ++i) {
		int ni = (i + 1 == n) ? 0 : i + 1;
		if (poly[i].y <= p.y) {
			if (poly[ni].y > p.y) {
				if (isLeft(poly[i], poly[ni], p) > 0) {
					++wn;
				}
			}
		}
		else {
			if (poly[ni].y <= p.y) {
				if (isLeft(poly[i], poly[ni], p) < 0) {
					--wn;
				}
			}
		}
	}
	return wn != 0;
}

int main(int agrc, char **argv) {
	FILE *in = fopen(argv[1], "r");
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; ++i) {
		fscanf(in, "%lf %lf", &poly[i].x, &poly[i].y);
	}
	fclose(in);

	FILE *sol = fopen(argv[2], "r");
	fscanf(sol, "%s", buf);
	bool ansExist = (buf[0] != 'i');
	fclose(sol);

	FILE *out = fopen(argv[3], "r");
	if (ansExist) {
		Point c1, c2;
		assert(fscanf(out, "%lf %lf ", &c1.x, &c1.y) == 2);
		assert(fscanf(out, "%lf %lf ", &c2.x, &c2.y) == 2);

		assert(dist(c1, c2) >= 2 * 3999);

		for (int i = 0; i < n; ++i) {
			int ni = (i + 1 == n) ? 0 : i + 1;
			double d = distPointSeg(poly[i], poly[ni], c1);
			assert(d >= 3999);
		}
		assert(isInPolygon(c1));
		assert(isInPolygon(c2));
	}
	else {
		assert(fgets(buf, 900, out) != nullptr);
		assert(strcmp(buf, "impossible") == 0 || strcmp(buf, "impossible\n") == 0);
	}
	assert(fgetc(out) == EOF);
	fclose(out);
	return 0;
}