#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

set<string> candidate;
char line[512];

int main(int agrc, char **argv) {
	FILE *in = fopen(argv[1], "r");
	FILE *sol = fopen(argv[2], "r");
	FILE *out = fopen(argv[3], "r");

	fgets(line, sizeof(line), in);
	long long N = stoll(line);

	for (long long i = 1; i * i <= N << 1; i++) {
		long long p = N << 1;

		if (p % (i + 1) == 0) {
			p = p / (i + 1);
			p -= i;

			if (p > 0 && p % 2 == 0) {
				p >>= 1;
				long long pp = p + i;

				string cand = to_string(p) + " " + to_string(pp);
				candidate.insert(cand);
			}
		}
	}

	while (candidate.size() != 0) {
		assert(fgets(line, sizeof(line), out) != nullptr);
		long long p = stoll(strtok(line, " "));
		long long pp = stoll(strtok(nullptr, "\n"));
		string ans = to_string(p) + " " + to_string(pp);

		assert(candidate.find(ans) != candidate.end());
		candidate.erase(ans);
	}

	fclose(in);
	fclose(sol);
	fclose(out);
	return 0;
}
