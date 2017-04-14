#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
const ll INF = 1034567891;
ll dis[105][105];
int main(int agrc, char **argv) {
	FILE *in = fopen("input.txt", "r");
	FILE *sol = fopen("solution.txt", "r");
	FILE *out = fopen("output.txt", "r");

	int N, M, D, i, j, t1, t2, t3;
	fscanf(in, "%d %d", &N, &M);
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) dis[i][j] = INF;
	for (i = 1; i <= M; i++) {
		fscanf(in, "%d %d %d", &t1, &t2, &t3);
		dis[t1][t2] = min(dis[t1][t2], (ll)-t3);
	}

	ll d = 0;
	fscanf(sol, "%d", &t1);
	if (t1 == -1) {
		assert(fscanf(out, "%d", &t2) == 1);
		assert(t1 == t2);
		assert(fscanf(out, "%d", &t2) != 1);
		return 0;
	}
	while (t1 != N) {
		fscanf(sol, "%d", &t2);
		d += dis[t1][t2];
		t1 = t2;
	}

	ll d2 = 0;
	assert(fscanf(out, "%d", &t1) == 1);
	assert(t1 == 1);
	while (t1 != N) {
		assert(fscanf(out, "%d", &t2) == 1);
		assert(t2 >= 1 && t2 <= N);
		assert(dis[t1][t2] != INF);
		d2 += dis[t1][t2];
		t1 = t2;
	}
	assert(fscanf(out, "%d", &t2) != 1);
	assert(d == d2);
	return 0;
}