#include <algorithm>
#include <cstdio>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

int main(int, char** argv) {
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[3], "r");
	int c;
	fscanf(in, " %d", &c);
	vector<int> answer;
	answer.reserve(c);
	for (int i = 0; i < c; i++) {
		int v;
		// ASSERT: output is number
		assert(fscanf(out, " %d", &v) == 1);
		// ASSERT: output is one digit
		assert(0 <= v && v <= 9);
		// ASSERT: output is distinct
		assert(find(answer.cbegin(), answer.cend(), v) == answer.cend());
		answer.emplace_back(v);
	}
	char garbage[16] = { '\0', };
	fscanf(out, " %15s", &garbage);
	// ASSERT: output doesn't have unexpected elements
	assert(garbage[0] == '\0');

	for (int i = 0; i < c; i++) {
		int a, b;
		int oa = 0, ob = 0;
		fscanf(in, " %d %d", &a, &b);
		for (int j = 0; j < c; j++) {
			int v;
			fscanf(in, " %d", &v);
			if (answer[j] == v) {
				oa+=v;
			} else if (find(answer.cbegin(), answer.cend(), v) != answer.cend()) {
				ob+=v;
			}
		}
		// ASSERT: output is consistent with each guess input
		assert(a == oa && b == ob);
	}

	fclose(in);
	fclose(out);
	return 0;
}
