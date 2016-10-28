#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int n;
int x[100005], y[100005], t[100005];

lint gr(){
	return 999900000 + 1 + 2 * (rand() % 50000);
}

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	fscanf(in, "%d", &n);
	for(int i=0; i<n; i++){
		fscanf(in, "%d %d %d", &x[i],&y[i],&t[i]);
	}
	int px, py, qx, qy;
	srand(time(0));
	assert(fscanf(sol, "%d %d", &px, &py) == 2);
	assert(fscanf(out, "%d %d", &qx, &qy) == 2);
	lint h1 = 0, h2 = 0, h3 = 0, h4 = 0;
	const lint mod1 = gr() * 1000000000 + gr();
	const lint mod2 = gr() * 1000000000 + gr();
	const lint mod3 = gr() * 1000000000 + gr();
	for(int i=0; i<n; i++){
		lint delta = 1ll * max(abs(x[i] - px), abs(y[i] - py)) * t[i] - 1ll * max(abs(x[i] - qx), abs(y[i] - qy)) * t[i];
		h1 = (h1 + delta) % mod1 + mod1;
		h2 = (h2 + delta) % mod2 + mod2;
		h3 = (h3 + delta) % mod3 + mod3;
		h4 += delta;
		h1 %= mod1;
		h2 %= mod2;
		h3 %= mod3;
	}
	assert(h1 == 0 && h2 == 0 && h3 == 0 && h4 == 0);
	fclose(in);
	fclose(sol);
	fclose(out);
}
