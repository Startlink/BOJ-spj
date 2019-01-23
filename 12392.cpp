#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<tuple>
#include<set>
#include<utility>
#include<map>
#include <unordered_map>
#include <bitset>
using namespace std;
typedef long long ll;
int N, M; ll A[500];
int V[1000000][6];
map<ll, int> mp;
int main() {
	int t, T, i, j, a; ll sum;
	cin >> t;
	for (T = 1; T <= t; T++) {
		cin >> N;
		for (i = 0; i < N; i++) cin >> A[i];
		M = 0; mp.clear();
		printf("Case #%d:\n", T);
		while (1) {
			M++;
			for (i = 0; i < 6; i++) {
				a = rand() % N;
				for (j = 0; j < i; j++) if (V[M][j] == a) break;
				if (j == i) V[M][i] = a;
				else i--;
			}
			for (i = 0, sum = 0; i < 6; i++) {
				sum += A[V[M][i]];
			}
			a = mp[sum];
			if (a > 0) {
				sort(V[a], V[a] + 6);
				sort(V[M], V[M] + 6);
				for (i = 0; i < 6; i++) if (V[a][i] != V[M][i]) break;
				if (i != 6) {
					for (i = 0; i < 6; i++) printf("%lld ", A[V[a][i]]);
					printf("\n");
					for (i = 0; i < 6; i++) printf("%lld ", A[V[M][i]]);
					printf("\n");
					break;
				}
				M--;
			}
			else {
				mp[sum] = M;
			}
		}
	}
}