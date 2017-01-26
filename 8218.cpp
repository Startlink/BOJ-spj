#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int n, buf2;
vector<int> a[55];
char buf[11];
pi ans[3];

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(in, "%d", &n);
	for(int i=1; i<=n; i++){
		int s;
		fscanf(in, "%d", &s);
		a[i].resize(s);
		for(auto &j : a[i]){
			fscanf(in, "%d", &j);
		}
		sort(a[i].begin(), a[i].end());
	}
	fscanf(sol, "%s", buf);
	if(strlen(buf) == 3 && buf[0] == 'N' && buf[1] == 'I' && buf[2] == 'E'){
		assert(fscanf(out, "%s", buf) > 0);
		assert(strlen(buf) == 3 && buf[0] == 'N' && buf[1] == 'I' && buf[2] == 'E');
		assert(fscanf(out, "%s", buf) <= 0);
		fclose(in);
		fclose(sol);
		fclose(out);
		return 0;
	}
	for(int i=0; i<3; i++){
		assert(fscanf(out, "%d %d", &ans[i].first, &ans[i].second) == 2);
	}
	assert(fscanf(out, "%d", &buf2) != 1);
	sort(ans, ans + 3);
	vector<int> tmp;
	for(int i=0; i<2; i++){
		assert(ans[i].first != ans[i+1].first);
	}
	for(int i=0; i<3; i++){
		assert(ans[i].first <= n && ans[i].first >= 1);
		auto t = lower_bound(a[ans[i].first].begin(),
				a[ans[i].first].end(), 
				ans[i].second);
		assert(t != a[ans[i].first].end() && *t == ans[i].second);
		tmp.push_back(ans[i].second);
	}
	sort(tmp.begin(), tmp.end());
	assert(tmp[1] < tmp[0] + tmp[2] && tmp[2] < tmp[0] + tmp[1]);
	fclose(in);
	fclose(sol);
	fclose(out);
}
