#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int n, m, s[10005], e[10005], chk[10005];

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(in, "%d %d", &n,&m);
	for(int i=0; i<m; i++) fscanf(in, "%d %d",&s[i],&e[i]);
	int w;
	assert(fscanf(out, "%d", &w) == 1);
	for(int i=0; i<m; i++){
		int t;
		assert(fscanf(out, "%d", &t) == 1);
		if(t == 0) chk[e[i]]++;
		else chk[s[i]]++;
	}
	assert(*max_element(chk + 1, chk + n + 1) == w);
	int t;
	assert(fscanf(sol, "%d", &t) == 1);
	assert(t == w);
	fclose(in);
	fclose(sol);
	fclose(out);
}
