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
int N, X, Y;
int main() {
	int i, t, T, sum;
	freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	cin >> t;
	for (T = 1; T <= t; T++) {
		cin >> X >> Y; sum = 0; N = 0; string s = "";
		while (sum < abs(X) + abs(Y) || (sum + X + Y) % 2) {
			N++; sum += N;
		}
		while (N > 0) {
			if (abs(X) > abs(Y)) {
				if (X > 0) {
					s += "E"; X -= N;
				}
				else {
					s += "W"; X += N;
				}
			}
			else {
				if (Y > 0) {
					s += "N"; Y -= N;
				}
				else {
					s += "S"; Y += N;
				}
			}
			N--;
		}
		printf("Case #%d: ", T);
		for (i = s.length() - 1; i >= 0; i--) printf("%c", s[i]);
		printf("\n");
	}
}
