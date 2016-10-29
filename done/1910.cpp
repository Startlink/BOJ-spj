#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int n;
vector<int> gph[205];

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(in, "%d", &n);
	for(int i=1; i<=n; i++){
		int s;
		fscanf(in, "%d", &s);
		gph[i].resize(s);
		for(int j=0; j<s; j++){
			fscanf(in, "%d", &gph[i][j]);
		}
	}
	int w, chk[205] = {};
	assert(fscanf(out, "%d", &w) == 1);
	assert(0 <= w && w <= n);
	for(int i=0; i<w; i++){
		int t;
		assert(fscanf(out, "%d", &t) == 1);
		assert(1 <= t && t <= n);
		assert(chk[t] == 0);
		chk[t] = 1;
	}
	int cnt = 0;
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			if(chk[i] == chk[j]) cnt++;
		}
		assert(cnt % 2 == 0);
	}
	fclose(in);
	fclose(sol);
	fclose(out);
}
