#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

vector<pi> v;

bool _find(int s, int e, int x){
	auto l = lower_bound(v.begin(), v.end(), pi(x, s));
	auto r = upper_bound(v.begin(), v.end(), pi(x, e));
	return r - l >= 2;
}

bool ok(char *t){
	return t[0] == 'O' && t[1] == 'K' && t[2] == '\n' && t[3] == 0;
}

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	char t1[55], t2[55];
	while(1){
		int n, m;
		v.clear();
		fscanf(in, "%d %d\n", &n, &m);
		if(n == 0) break;
		for (int i = 0; i < n; i++) {
			int k;
			fscanf(in, "%d",&k);
			v.push_back(pi(k, i));
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < m; i++) {
			int x, y, v;
			fscanf(in, "%d %d",&x, &y); x--; y--;
			fgets(t1, 55, sol);
			assert(fgets(t2, 55, out) != NULL);
			if(ok(t1)) assert(ok(t2));
			else{
				assert(!ok(t2));
				assert(sscanf(t2, "%d\n", &v) == 1);
				assert(_find(x, y, v));
			}
		}
		fgets(t1, 55, sol);
		assert(fgets(t2, 55, out) != NULL);
		assert(t2[0] == '\n' && t2[1] == 0);
	}
	assert(fgets(t2, 55, out) == NULL);
}

