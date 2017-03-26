#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n;
char str[11][100005];
int chk[11][100005], dx[100005];

vector<pi> query;

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(in, "%d", &n);
	for(int i=0; i<10; i++){
		fscanf(in, "%s", str[i]);
	}
	int t, u;
	assert(fscanf(out, "%d", &t) == 1);
	assert(0 <= t && t <= 50000);
	for(int i=0; i<t; i++){
		pi x;
		assert(fscanf(out, "%d %d",&x.first, &x.second) == 2);
		query.push_back(x);
		assert(x.first < n && x.first >= 0);
	}
	assert(fscanf(out, "%d", &u) != 1);
	fclose(in);
	fclose(out);
	for(int i=0; i+1<t; i++){
		assert(query[i].first + query[i].second <= query[i+1].first);
		dx[query[i].first]++;
		dx[query[i].first + query[i].second]--;
	}
	for(int i=1; i<n; i++) dx[i] += dx[i-1];
	int p = 9;
	for(int i=0; i<n; i++){
		assert(str[p][i] == '.');
		if(dx[i]){
			p = min(p-1, 0);
		}
		else p = max(p+1, 0);
	}
	return 0;
}

