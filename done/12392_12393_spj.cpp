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
int N, XN, YN, S[500]; ll A[500], X[500], Y[500];
void read_string(string s, ll *x, int &xn) {
	int i; ll a;
	xn = 0; a = 0;
	for (i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			x[xn++] = a;
			a = 0;
		}
		else {
			a = a * 10 + s[i] - '0';
		}
	}
}
int main(int agrc, char **agrv) {
	int i, j, t, T; string s_out, s_sol; ll sum1, sum2;
	FILE *in = fopen(agrv[1], "r");
	FILE *sol = fopen(agrv[2], "r");
	FILE *out = fopen(agrv[3], "r");
	t = read_int(in);
	for (T = 1; T <= t; T++) {
		/* read input */
		N = read_int(in);
		for (i = 0; i < N; i++) A[i] = read_long(in);

		/* check whether "Case #n:" is same */
		s_sol = read_line(sol);
		s_out = read_line(out);
		assert(s_sol.compare(s_out) == 0);
		s_out = read_line(sol);
		s_out = read_line(sol);

		/* check whether sum of two subsets of output is same */
		s_sol = read_line(out);
		s_out = read_line(out);
		read_string(s_sol, X, XN); 
		read_string(s_out, Y, YN);
		sum1 = sum2 = 0;
		for (i = 0; i < XN; i++) sum1 += X[i];
		for (i = 0; i < YN; i++) sum2 += Y[i];
		assert(sum1 == sum2);

		/* check whether two subsets of output are distinct.(they do not have exactly the same elements) */
		sort(X, X + XN); sort(Y, Y + YN);
		for (i = 0; i < N; i++) S[i] = 0;
		for (i = 0; i < XN; i++) {
			for (j = 0; j < N; j++) {
				if (!S[j] && A[j] == X[i]) {
					S[j] = 1; break;
				}
			}
			assert(j < N); // the element of subset is not in the input
		}
		for (i = 0; i < N; i++) S[i] = 0;
		for (i = 0; i < YN; i++) {
			for (j = 0; j < N; j++) {
				if (!S[j] && A[j] == Y[i]) {
					S[j] = 1; break;
				}
			}
			assert(j < N); // the element of subset is not in the input
		}
		for (i = 0; i < XN; i++) {
			if (X[i] != Y[i]) break;
		}
		assert((XN != YN) || (i < XN)); // two subsets are distinct
	}

	/* 그 이후 쓰레기 출력이 존재하면 안 됩니다. (assert) */
	assert(fscanf(out, "%d", &N) == -1);

	fclose(in);
	fclose(sol);
	fclose(out);

	return 0;
}