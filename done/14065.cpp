#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
	FILE *sol = fopen(argv[2], "r");
	FILE *out = fopen(argv[3], "r");
	double ans, yourans;
	fscanf(sol, "%lf", &ans);
	assert(fscanf(out, "%lf", &yourans) == 1);
	assert(fabs(ans - yourans) <= 1e-6 || fabs(ans - yourans) / fabs(ans) <= 1e-6);
	assert(fscanf(out, "%*s") == -1);
	return 0;
}

