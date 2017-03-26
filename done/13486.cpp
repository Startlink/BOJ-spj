#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

char s1[500], s2[500];
int nxt[500];

int n;
string str[105];
int a[105];

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(sol, "%s", s1);
	assert(fscanf(out, "%s", s2) > 0);
	string st1 = s1, st2 = s2;
	assert(st1 == st2);
	if(st1 == "DA"){
		assert(fscanf(out, "%s", s1) > 0);
		assert(fscanf(out, "%s", s2) <= 0);
		assert(strlen(s1) == 26);
		set<int> s;
		for(int i=0; i<26; i++){
			assert(islower(s1[i]) != 0);
			s.insert(s1[i]);
			nxt[i + 'a'] = s1[i];
		}
		assert(s.size() == 26);
		fscanf(in, "%d", &n);
		for(int i=1; i<=n; i++){
			fscanf(in, "%s", s1);
			str[i] = s1;
			for(auto &j : str[i]){
				j = nxt[j];
			}
		}
		for(int i=1; i<=n; i++){
			fscanf(in, "%d", &a[i]);
		}
		for(int i=2; i<=n; i++){
			assert(str[a[i-1]] <= str[a[i]]);
		}
	}
	fclose(in);
	fclose(sol);
	fclose(out);
	return 0;
}

