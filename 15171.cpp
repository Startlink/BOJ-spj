#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char ans[200050];
char str[200050];
vector <int> conn[200050];
bool chk[200050];
char u[200050];
int main(int argc, char **argv) {
	FILE *in = fopen(argv[1], "r");
	FILE *sol = fopen(argv[2], "r");
	FILE *out = fopen(argv[3], "r");

	int N, i, j;
	fscanf(in, "%d", &N);
	for (i = 1; i <= N; i++) {
		char c[2];
		fscanf(in, "%s", c);
		if (c[0] == 'N') chk[i] = true;
		int t1, t2;
		fscanf(in, "%d", &t1);
		while (t1--) {
			fscanf(in, "%d", &t2);
			conn[i].push_back(t2);
		}
	}
	fclose(in);

	fscanf(sol, "%s", ans);
	assert(fgets(str + 1, 200048, out) != NULL);
	assert(fscanf(out, "%s", u) == EOF);
	fclose(sol);
	fclose(out);


	if (strcmp(ans, "Impossible") == 0) {
		assert(strcmp(str + 1, "Impossible") == 0);
		return 0;
	}

	assert(strlen(str + 1) == N);
	for (i = 1; i <= N; i++) assert(str[i] == 'S' || str[i] == 'V');

	int cnt[2] = { 0,0 };
	for (i = 1; i <= N; i++) {
		if (str[i] == 'S') cnt[0]++;
		else cnt[1]++;
	}
	for (i = 1; i <= N; i++) {
		if (!chk[i]) {
			for (j = 0; j < conn[i].size(); j++) if (str[i] != str[conn[i][j]]) break;
			assert(j < conn[i].size());
		}
		else {
			int c = 0;
			for (j = 0; j < conn[i].size(); j++) if (str[i] != str[conn[i][j]]) c++;

			int t = 1;
			if (str[i] == 'S') t = 0;
			assert(cnt[1 - t] != c);
		}
	}
	return 0;
}	