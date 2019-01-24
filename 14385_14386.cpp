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
int N, K; 
char A[100];
char B[100] = "3 2 5 2 7 2 3 2 11";
void f(int idx) {
	if (K <= 0) return;
	if (idx == N - 2) {
		printf("%s %s\n", A, B);
		K--;
		return;
	}
	A[idx] = '0'; f(idx + 1);
	if (idx <= N - 4) {
		A[idx] = A[idx + 1] = '1';
		f(idx + 2);
	}
}
int main() {
	int t, T;
	freopen("a.txt", "r", stdin);
	freopen("14386_large.txt", "w", stdout);
	cin >> t;
	for (T = 1; T <= t; T++) {
		cin >> N >> K;
		printf("Case #%d:\n", T);
		A[0] = A[1] = '1'; A[N - 2] = A[N - 1] = '1'; A[N] = '\0';
		f(2);
	}
}