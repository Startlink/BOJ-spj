#include <stdio.h>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

int main(int argc, char **argv) {
	FILE* in = fopen(argv[1], "r");
	FILE* sol = fopen(argv[2], "r");
	FILE* out = fopen(argv[3], "r");
	int k, n;
	fscanf(in, "%d %d", &k, &n);
	vector<int> v;
	int x;
	long long sum = 0;
	while (fscanf(out, "%d", &x) == 1) {
		assert(1 <= x && x <= k);
		v.push_back(x);
		sum += x;
		assert(v.size() <= n);
	}
	assert(v.size() == n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	assert(v.size() == n);
	assert(sum == (long long)k);
	return 0;
}