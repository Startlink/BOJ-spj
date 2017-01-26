#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int m, n, s[20005], e[20005];
char fst[10];
char ans[20005][10];

bool okay(vector<pi> v){
	set<int> s;
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); ){
		int e = i;
		while(e < v.size() && v[i].first == v[e].first) e++;
		for(int j=i; j<e; j++){
			auto p = s.upper_bound(v[j].first);
			if(p != s.end() && *p < v[j].second) return 0;
		}
		for(int j=i; j<e; j++) s.insert(v[j].second);
		i = e;
	}
	return 1;
}
int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(sol, "%s", fst);
	if(fst[0] == 'N' && fst[1] == 'I'){
		assert(fscanf(out, "%s\n", fst) >= 1);
		assert(fst[0] == 'N' && fst[1] == 'I' && fst[2] == 'E' && strlen(fst) == 3);
		assert(fscanf(out, "%s\n", fst) < 1);
		fclose(in);
		fclose(sol);
		fclose(out);
		return 0;
	}
	fscanf(in, "%d %d",&m,&n);
	for(int i=0; i<n; i++){
		fscanf(in, "%d %d",&s[i], &e[i]);
	}
	for(int i=0; i<n; i++){
		assert(fscanf(out, "%s\n", ans[i]) > 0);
		assert(strlen(ans[i]) == 1);
		assert(*ans[i] == 'N' || *ans[i] == 'S');
	}
	assert(fscanf(out, "%s\n", fst) <= 0);
	vector<pi> v1, v2;
	for(int i=0; i<n; i++){
		if(*ans[i] == 'N') v1.push_back(pi(s[i], e[i]));
		else v2.push_back(pi(s[i], e[i]));
	}
	assert(okay(v1) && okay(v2));
	fclose(in);
	fclose(sol);
	fclose(out);
}
