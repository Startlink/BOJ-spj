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
ll X, Y; string S;
int main(int agrc, char **agrv) {
	int i, t, T, a; string s_out, s_sol;
	FILE *in = fopen(agrv[1], "r");
	FILE *sol = fopen(agrv[2], "r");
	FILE *out = fopen(agrv[3], "r");
	t = read_int(in);
	for (T = 1; T <= t; T++) {
		X = read_long(in);
		Y = read_long(in);
		s_sol = read_line(sol);
		s_out = read_line(out);
		assert(s_sol.length() == s_out.length());
		if (T < 10) {
			assert(s_sol.compare(0, 9, s_out.c_str(), 9) == 0);
			S = s_out.substr(9, s_out.length() - 9);
		}
		else if (T < 100) {
			assert(s_sol.compare(0, 10, s_out.c_str(), 10) == 0);
			S = s_out.substr(10, s_out.length() - 10);
		}
		else {
			assert(s_sol.compare(0, 11, s_out.c_str(), 11) == 0);
			S = s_out.substr(11, s_out.length() - 11);
		}

		char ch; ll x, y;
		x = y = 0;
		for (i = 0; i < S.length(); i++) {
			ch = S[i];
			if (ch == 'S') y -= i + 1;
			else if (ch == 'N') y += i + 1;
			else if (ch == 'E') x += i + 1;
			else x -= i + 1;
		}
		assert(x == X && y == Y);
	}

	/* 그 이후 쓰레기 출력이 존재하면 안 됩니다. (assert) */
	assert(fscanf(out, "%d", &a) == -1);

	fclose(in);
	fclose(sol);
	fclose(out);

	return 0;
}