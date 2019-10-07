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
int N, K;
string bignum_add(string &s1, string &s2) {
	int i, j, n1, n2, a; string s3; vector<int> v;
	n1 = s1.size(); n2 = s2.size();
	v.reserve(max(n1, n2) + 1);
	for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
		a = s1[i] - '0' + s2[j] - '0';
		v.push_back(a);
	}
	while (i >= 0) {
		a = s1[i] - '0';
		v.push_back(a);
		i--;
	}
	while (j >= 0) {
		a = s2[j] - '0';
		v.push_back(a);
		j--;
	}
	for (i = 0, a = 0; i < v.size(); i++) {
		a += v[i];
		if (a >= 10) {
			v[i] = a - 10;
			a = 1;
		}
		else {
			v[i] = a;
			a = 0;
		}
	}
	if (a) v.push_back(a);
	s3.reserve(v.size());
	for (i = v.size() - 1; i >= 0; i--) s3 += (char)(v[i] + '0');
	return s3;
}
/* s1 - s2, s1 >= s2 */
string bignum_sub(string &s1, string &s2) {
	int i, j, n1, n2, a; string s3; vector<int> v;
	n1 = s1.size(); n2 = s2.size();
	v.reserve(max(n1, n2) + 1);
	for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
		a = s1[i] - '0' - (s2[j] - '0');
		v.push_back(a);
	}
	while (i >= 0) {
		a = s1[i] - '0';
		v.push_back(a);
		i--;
	}
	while (j >= 0) {
		a = s2[j] - '0';
		v.push_back(a);
		j--;
	}
	for (i = 0, a = 0; i < v.size(); i++) {
		a += v[i];
		if (a < 0) {
			v[i] = a + 10;
			a = -1;
		}
		else {
			v[i] = a;
			a = 0;
		}
	}
	/* if s1 > s2 then a is -1 (result is minus) */
	if (a) v.push_back(a);
	s3.reserve(v.size());

	/* trim leading zeros */
	for (i = v.size() - 1; i > 0; i--) {
		if (v[i]) break;
	}
	for (; i >= 0; i--) s3 += (char)(v[i] + '0');
	return s3;
}
/* 1 : s1 > s2, 0: s1==s2, -1 s1<s2 */
int bignum_compare(string &s1, string &s2) {
	if (s1.length() > s2.length()) return 1;
	if (s1.length() < s2.length()) return -1;
	int i;
	for (i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) {
			if (s1[i] > s2[i]) return 1;
			else return -1;
		}
	}
	return 0;
}
string bignum_trim_leading_zeros(string &s) {
	int i;
	for (i = 0; i < s.length() - 1; i++) {
		if (s[i] != '0') break;
	}
	return s.substr(i, s.length() - i); 
}
/* s1*n, 0<=n<=9 */
string bignum_mul(string &s1, int n) {
	string ret = "0";
	while (n-- > 0) {
		ret = bignum_add(ret, s1);
	}
	return bignum_trim_leading_zeros(ret);
}
/* y / x */
void bignum_div(string &y, string &x, string &quotient, string &remainder) {
	int i, j; string q, r, s2, s3; char ch;
	q = "0"; r = "0";
	for (i = 0; i < y.length(); i++) {
		s2 = string(1, y[i]);
		r = bignum_mul(r, 10);
		r = bignum_add(r, s2);
		s3 = x;
		for (j = 1; j <= 10; j++) {
			if (bignum_compare(s3, r) > 0) break;
			s3 = bignum_add(s3, x);
		}
		s3 = bignum_sub(s3, x); j--;
		ch = '0' + j;
		q += string(1, ch);
		r = bignum_sub(r, s3);
		r = bignum_trim_leading_zeros(r);
	}
	quotient = q; remainder = r;
}
string convert_binary_to_base(string &x, int base) {
	string ret = "0", s; char ch; int i;
	for (i = 0; i < x.length(); i++) {
		ch = x[i];
		s = string(1, ch);
		ret = bignum_mul(ret, base);
		ret = bignum_add(ret, s);
	}
	return bignum_trim_leading_zeros(ret);
}
int main(int agrc, char **agrv) {
	int i, t, T; string s_out, s_sol;
	FILE *in = fopen(agrv[1], "r");
	FILE *sol = fopen(agrv[2], "r");
	FILE *out = fopen(agrv[3], "r");
	t = read_int(in);
	for (T = 1; T <= t; T++) {
		/* read input */
		N = read_int(in); K = read_int(in);

		/* check whether "Case #n:" is same */
		s_sol = read_line(sol);
		s_out = read_line(out);
		assert(s_sol.compare(s_out) == 0);

		/* move on next TC for sol */
		for (i=0; i<K; i++) read_line(sol);

		/* check whether each jamcoins and nontrivial divisors is ok */
		while (K-- > 0) {
			string s1, s2, s3, q, r;
			s1 = read_string(out);
			assert(s1.length() == N);
			assert(s1[0] == '1' && s1[N - 1] == '1');
			for (i = 2; i <= 10; i++) {
				s2 = read_string(out);
				s3 = convert_binary_to_base(s1, i);
				bignum_div(s3, s2, q, r);
				r = bignum_trim_leading_zeros(r);
				assert(r.length() == 1 && r[0] == '0');
			}
		}
	}

	/* 그 이후 쓰레기 출력이 존재하면 안 됩니다. (assert) */
	assert(fscanf(out, "%d", &N) == -1);

	fclose(in);
	fclose(sol);
	fclose(out);

	return 0;
}