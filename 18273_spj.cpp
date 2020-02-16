#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

multiset<int> heights;
int A[100001], B[100001];
int main(int agrc, char **agrv) {
	FILE *in = fopen(agrv[1], "r");
	FILE *sol = fopen(agrv[2], "r");
	FILE *out = fopen(agrv[3], "r");

	int N, x;
	fscanf(in, "%d", &N);

	for (int i = 0; i < N; i++) {
		fscanf(in, "%d", &x);
		heights.insert(x);
	}
	fclose(in);

	int solAns, numA, numB;
	fscanf(sol, "%d", &solAns);
	fclose(sol);
	assert(fscanf(out, "%d", &numA) == 1);

	if (solAns == -1) 
		assert(numA == -1);
	else {
		for (int i = 0; i < numA; i++) {
			assert(fscanf(out, "%d", &A[i]) == 1);
			assert(heights.find(A[i]) != heights.end());
			heights.erase(heights.find(A[i]));
		}

		assert(fscanf(out, "%d", &numB) == 1);
		for (int i = 0; i < numB; i++) {
			assert(fscanf(out, "%d", &B[i]) == 1);
			assert(heights.find(B[i]) != heights.end());
			heights.erase(heights.find(B[i]));
		}
		assert(numA + numB == N);
		assert(heights.size() == 0);

		int term;
		if (numA >= 2) {
			term = A[1] - A[0];
			for (int i = 1; i < numA; i++) {
				assert(A[i - 1] <= A[i]);
				assert(A[i] - A[i - 1] == term);
			}
		}
		if (numB >= 2) {
			term = B[1] - B[0];
			for (int i = 1; i < numB; i++) {
				assert(B[i - 1] <= B[i]);
				assert(B[i] - B[i - 1] == term);
			}
		}
	}

	int tmp;
	assert(fscanf(out, "%d", &tmp) == -1);

	return 0;
}