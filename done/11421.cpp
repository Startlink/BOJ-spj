#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n;
int chatNeeds[10000];
const int BUFFER_LEN = 100005;
char buffer[BUFFER_LEN + 3];
bool conn[10000][10000];

vector<int> tokenizeNumbers(char* buf) {
	vector<int> out;
	char* p = strtok(buf, " \n");
	while (p != nullptr) {
		int v;
		try {
			v = stoi(string(p));
		}
		catch (const invalid_argument& ia) {
			assert(false);
		}
		catch (const out_of_range& ia) {
			assert(false);
		}
		out.push_back(v);
		p = strtok(nullptr, " \n");
	}
	return out;
}

int main(int agrc, char **argv) {
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[3], "r");

	int tc = 0;
	while (true) {
		////	check EOF
		if (fgets(buffer, BUFFER_LEN, in) == nullptr) {
			break;
		}
		if (buffer[0] == '\n') {
			break;
		}

		++tc;

		priority_queue<pair<int, int>> pq;
		queue<pair<int, int>> q;

		vector<int> inputs = tokenizeNumbers(buffer);
		n = (int)inputs.size();
		for (int i = 0; i < n; ++i) {
			chatNeeds[i] = inputs[i];
			pq.push({ chatNeeds[i], i });
		}

		bool ansExist = true;
		while (!pq.empty()) {
			int x = pq.top().second, d = pq.top().first;
			pq.pop();
			for (int i = 0; i < d; ++i) {
				if (pq.empty()) {
					ansExist = false;
					break;
				}
				int nx = pq.top().second, nd = pq.top().first;
				pq.pop();
				if (nd > 1) {
					q.push({ nd - 1, nx });
				}
			}
			if (!ansExist) {
				break;
			}
			while (!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
		}

		////	check empty line
		if (tc > 1) {
			assert(fgets(buffer, BUFFER_LEN, out) != nullptr);
			assert(buffer[0] == '\n');
		}

		////	check answer
		if (!ansExist) {
			assert(fgets(buffer, BUFFER_LEN, out) != nullptr);
			assert(strcmp(buffer, "fail\n") == 0 || strcmp(buffer, "fail") == 0);
		}
		else {
			for (int i = 0; i < n; ++i) {
				memset(conn[i], 0, sizeof(bool) * n);

				assert(fgets(buffer, BUFFER_LEN, out) != nullptr);
				vector<int> nums = tokenizeNumbers(buffer);
				assert(nums.size() == n);
				for (int j = 0; j < n; ++j) {
					assert(0 <= nums[j] && nums[j] <= 1);
					conn[i][j] = (nums[j] == 1);
				}
			}

			for (int i = 0; i < n; ++i) {
				assert(conn[i][i] == false);
				int cnt = 0;
				for (int j = 0; j < n; ++j) {
					assert(conn[i][j] == conn[j][i]);
					cnt += (conn[i][j]) ? 1 : 0;
				}
				assert(cnt == chatNeeds[i]);
			}
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
