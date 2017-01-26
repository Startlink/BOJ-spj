#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

int n, m, adj[505][505];
char buf[55];
int t;

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(in, "%d %d",&n,&m);
	memset(adj,-1,sizeof(adj));
	for(int i=0; i<m; i++){
		int x, y, c;
		fscanf(in, "%d %d %d",&x,&y,&c);
		adj[x][y] = c;
		adj[y][x] = c;
	}
	fscanf(sol, "%s", buf);
	if(*buf == 'B'){
		assert(fscanf(out, "%s", buf) > 0);
		assert(strcmp(buf, "BRAK") == 0);
		assert(fscanf(out, "%s", buf) <= 0);
		fclose(in);
		fclose(sol);
		fclose(out);
	}
	else{
		rewind(sol);
	}
	fscanf(sol, "%d", &t);
	vector<int> off(t);
	for(auto &j : off){
		fscanf(sol, "%d", &j);
	}
	assert(fscanf(out, "%d", &t) == 1);
	assert(t >= 2 && t <= m);
	vector<int> usr(t);
	for(auto &j : usr){
		assert(fscanf(out, "%d", &j) == 1);
		assert(1 <= j && j <= n);
	}
	assert(fscanf(out, "%d", &t) != 1);
	assert(usr.front() == usr.back());
	set<pi> s;
	lint ans = 0;
	for(int i=1; i<usr.size(); i++){
		assert(adj[usr[i-1]][usr[i]] != -1);
		assert(s.find(pi(usr[i-1], usr[i])) == s.end());
		assert(s.find(pi(usr[i], usr[i-1])) == s.end());
		ans += adj[usr[i-1]][usr[i]];
		s.insert(pi(usr[i-1], usr[i]));
	}
	for(int i=1; i<off.size(); i++){
		ans -= adj[off[i-1]][off[i]];
	}
	assert(ans == 0);
	fclose(in);
	fclose(sol);
	fclose(out);
}
