/*
 * Written by Gyojun Youn on Feb. 1. 2019.
 * BOJ 11838 "New Year Train"
 * Time Complexity O(N+M)
 * Space Complexity O(N+M)
 */
#include "testlib.h"
#include <algorithm>
#include <vector>
#define eb emplace_back
#define allv(V) ((V).begin()),((V).end())
using namespace std;

int main(int argc, char **argv) {
	registerTestlibCmd(argc, argv);

	const int N = inf.readInt();
	const int M = inf.readInt();
	const vector<int> A = inf.readInts(N, 1, N);
	const vector<int> B = ouf.readInts(N, 1, M);
	ouf.readEoln();
	const vector<int> C = ouf.readInts(N, 1, M);
	ouf.readEoln();
	ouf.readEof();

	vector<vector<int>> CH(M);
	for(int i = 0; i < N; i++)
		CH[B[i]-1].eb(A[i]);
	for(int i = 0; i < M; i++)
		reverse(allv(CH[i]));

	for(int i = 0; i < N; i++) {
		auto &V = CH[C[i]-1];
		if(V.empty() || i+1 != V.back())
			quitf(_wa, "Wrong Answer");
		V.pop_back();
	}

	quitf(_ok, "Correct");
	return 0;
}
