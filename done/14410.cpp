#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

char buf[500];
double p, q, r, s;


int main(int agrc, char **agrv){
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	assert(fscanf(out, "%lf %lf",&p,&q) == 2);
	fscanf(sol, "%lf %lf", &r, &s);
	assert(fabs(p - r) <= 0.01 && fabs(q - s) <= 0.01);
	assert(fscanf(out, "%lf", &p) == -1);
	fclose(sol);
	fclose(out);
	return 0;
}
