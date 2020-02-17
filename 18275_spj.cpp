#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
using namespace std;

bool arr[1000001];
int main(int agrc, char **agrv) {
	FILE *in = fopen(agrv[1], "r");
	FILE *sol = fopen(agrv[2], "r");
	FILE *out = fopen(agrv[3], "r");

	int N, M, A, B;
	fscanf(in, "%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		assert(fscanf(out, "%d", &A) == 1);
		assert(fscanf(out, "%d", &B) == 1);
		assert(0 <= A && A <= N - 1);
		assert(M <= B && B <= M + N - 1);
		assert(!arr[A] && !arr[B]);
		assert((A & B) == A);
		arr[A] = arr[B] = true;
	}

	int tmp;
	assert(fscanf(out, "%d", &tmp) == -1);

	fclose(in);
	fclose(sol);
	fclose(out);
	return 0;
}