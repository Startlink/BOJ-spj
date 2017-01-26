#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

vector<int> ts[505];
int n, m, r, t, k;
int adj[505][505];
int vis[505];

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(in, "%d %d %d %d %d", &n,&m,&r,&t,&k);
	for(int i=0; i<k; i++){
		int x, y;
		fscanf(in, "%d %d",&x,&y);
		adj[x][y] = 1;
	}
	int ans1, ans2;
	fscanf(sol, "%d %d",&ans1, &ans2);
	int ans3, ans4;
	assert(fscanf(out, "%d %d", &ans3, &ans4) == 2);
	assert(ans1 == ans3 && ans2 == ans4);
	lint totp = 0;
	for(int i=0; i<ans1; i++){
		int a, b, c;
		assert(fscanf(out, "%d %d %d",&a,&b,&c) == 3);
		assert(1 <= a && a <= n && 1 <= b && b <= m && 0 <= c && c <= t - r);
		totp += c + r;
		assert(adj[a][b]);
		assert(!vis[b]);
		vis[b] = 1;
		ts[a].push_back(c);
	}
	assert(totp == ans2);
	for(int i=1; i<=n; i++){
		sort(ts[i].begin(), ts[i].end());
		for(int j=1; j<ts[i].size(); j++){
			assert(ts[i][j] - ts[i][j-1] >= r);
		}
	}
	assert(fscanf(out, "%d", &ans3) != 1);
	fclose(in);
	fclose(sol);
	fclose(out);
}
