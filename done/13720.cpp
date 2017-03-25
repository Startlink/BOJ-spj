#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n;
vector<lint> v;

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1], "r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(in, "%d", &n);
	int x;
	fscanf(sol, "%d", &x);
	lint y;
	while(~fscanf(out, "%lld", &y)){
		v.push_back(y);
	}
	assert(v.size() == 1 || v.size() == n * n);
	if(v[0] == -1) assert(x == -1);
	else{
		assert(x != -1);
		for(auto &i : v){
			assert(i > 0 && i < 1000000000);
		}
		for(int i=0; i<n; i++){
			lint s1 = 0, s2 = 0;
			for(int j=0; j<n; j++){
				s1 += v[i * n + j];
				s2 += v[j * n + i];
			}
			assert(abs(s1) % n == 0 && abs(s2) % n == 0);
			s1 /= n;
			s2 /= n;
			bool ok1 = 0, ok2 = 0;
			for(int j=0; j<n; j++){
				if(s1 == v[i * n + j]) ok1 = 1;
				if(s2 == v[j * n + i]) ok2 = 1;
			}
			assert(ok1 && ok2);
		}
	}
	fclose(in);
	fclose(sol);
	fclose(out);
}
