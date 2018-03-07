// 10130 spj code written by khsoo01
#include<cstdio>
#include<cassert>

#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
const int N = 500005, M = 1000005;

int sol_b, out_a, out_b;

int n, m, dt[N], ind[N];

vector<int> adj[N], ord;
queue<int> q;

int main (int argc, char **argv)
{
	int tmp;

	FILE *in = fopen(argv[1], "r");
	FILE *sol = fopen(argv[2], "r");
	FILE *out = fopen(argv[3], "r");

	fscanf(in, "%d%d", &n, &m);
	for(int i=1; i<=m; i++) {
		int A, B;
		fscanf(in, "%d%d", &A, &B);
		adj[A].push_back(B);
		ind[B]++;
	}
	fscanf(sol, "%d%d", &tmp, &sol_b);
	tmp = fscanf(out, "%d%d", &out_a, &out_b);

	fclose(in);
	fclose(sol);
	fclose(out);

	assert(tmp == 2 && sol_b == out_b && 1 <= out_a && out_a <= n);

	for(int i=1; i<=n; i++) {
		if(ind[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		int C = q.front(); q.pop();
		ord.push_back(C);
		for(auto T : adj[C]) {
			if(--ind[T] == 0) q.push(T);
		}
	}
	reverse(ord.begin(), ord.end());

	tmp = 0;
	for(auto &C : ord) {
		if(C == out_a) continue;
		for(auto &T : adj[C]) {
			if(T == out_a) continue;
			dt[C] = max(dt[C], dt[T]+1);
		}
		tmp = max(tmp, dt[C]);
	}

	assert(tmp == sol_b);

	return 0;
}
