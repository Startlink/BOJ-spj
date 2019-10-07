#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <tuple>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
char buffer[1000000];
string read_string(FILE *fp) {
	assert(fscanf(fp, "%10000s", buffer) == 1);
	return string(buffer);
}
int read_int(FILE *fp) {
	string str = read_string(fp);
	int temp;
	istringstream sin(str);
	assert(sin >> temp);
	return temp;
}
string read_line(FILE *fp) {
	assert(fscanf(fp, "%10000[^\n]\n", buffer) == 1);
	return string(buffer);
}
long long read_long(FILE *fp) {
	string str = read_string(fp);
	long long temp;
	istringstream sin(str);
	assert(sin >> temp);
	return temp;
}
float read_float(FILE *fp) {
	string str = read_string(fp);
	float temp;
	istringstream sin(str);
	assert(sin >> temp);
	return temp;
}
double read_double(FILE *fp) {
	string str = read_string(fp);
	double temp;
	istringstream sin(str);
	assert(sin >> temp);
	return temp;
}
void assert_eof(FILE *fp) {
	assert(fscanf(fp, "%10000s", buffer) != 1);
}
void assert_int_range(int num, int start, int end) {
	assert(start <= num && num <= end);
}
void assert_int(int num, int start) {
	assert_int_range(num, start, start);
}
int read_int_range(FILE *fp, int start, int end) {
	int num = read_int(fp);
	assert_int_range(num, start, end);
	return num;
}
int N, E[52][52], R[52], V[52]; ll M, D[52]; // N: Building수, Reach[b]=1 (b -> N으로의 path가 존재함)
ll f(int u) {
	if (u == N) return 1;
	if (V[u]) return -2;
	V[u] = 1;
	ll &ret = D[u], ret2;
	if (ret != -1) {
		V[u] = 0;
		return ret;
	}
	ret = 0;
	int v;
	for (v = 1; v <= N; v++) {
		if (E[u][v] == 0 || R[v] == 0) continue;
		ret2 = f(v);
		if (ret2 == -2) return ret = -2;
		ret += ret2;
	}
	V[u] = 0;
	return ret;
}
void g(int u) {
	R[u] = 1;
	int v;
	for (v = 1; v <= N; v++) {
		if (!R[v] && E[v][u]) g(v);
	}
}
int main(int agrc, char **agrv) {
	int i, j, t, T; string s_out, s_sol;
	FILE *in = fopen(agrv[1], "r");
	FILE *sol = fopen(agrv[2], "r");
	FILE *out = fopen(agrv[3], "r");
	t = read_int(in);
	for (T = 1; T <= t; T++) {
		N = read_int(in);
		M = read_long(in);
		s_sol = read_line(sol);
		s_out = read_line(out);
		assert(s_sol.compare(s_out) == 0);
		if (s_sol[s_sol.length() - 10] == 'I' && s_sol[s_sol.length() - 9] == 'M') continue;
		for (i = 1; i <= N; i++) {
			read_line(sol);
			s_out = read_line(out);
			for (j = 0; j < N; j++) {
				E[i][j + 1] = s_out[j] - '0';
			}
		}
		for (j = 1; j <= N; j++) {
			if (E[N][j] == 1) break;
		}
		/* The exception is that no slides are allowed to originate in building B, since once the CEO reaches that building, there is no need for her to do any more sliding. */
		assert(j > N);

		// R 만들기
		for (i = 1; i <= N; i++) R[i] = 0;
		g(N);

		for (i = 1; i <= N; i++) D[i] = -1;
		for (i = 1; i <= N; i++) V[i] = 0;
		assert(f(1) == M);
	}

	/* 그 이후 쓰레기 출력이 존재하면 안 됩니다. (assert) */
	assert(fscanf(out, "%d", &N) == -1);

	fclose(in);
	fclose(sol);
	fclose(out);

	return 0;
}