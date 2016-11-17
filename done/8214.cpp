#include <cassert>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int, char** argv) {
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[3], "r");
	int n, m;
	fscanf(in, " %d %d", &n, &m);
	vector<unordered_set<int>> friend_map(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		fscanf(in, " %d %d", &a, &b);
		friend_map[a].insert(b);
		friend_map[b].insert(a);
	}

	unordered_set<int> answer;
	int n3 = n / 3;
	int last_p = 0;
	answer.reserve(n3);
	for (int i = 0; i < n3; i++) {
		int p;
		// ASSERT: output is number
		assert(fscanf(out, " %d", &p) == 1);
		// ASSERT: output is increasing order
		assert(p > last_p);
		for (int q : answer) {
			// ASSERT: current person know all people already in answer set
			assert(friend_map[p].count(q) != 0);
		}
		answer.insert(p);
		last_p = p;
	}
	char garbage[16] = { '\0', };
	fscanf(out, " %15s", &garbage);
	// ASSERT: output doesn't have unexpected elements
	assert(garbage[0] == '\0');

	fclose(in);
	fclose(out);
	return 0;
}
