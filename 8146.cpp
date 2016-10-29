#include <algorithm>
#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int main(int, char** argv) {
	FILE *in = fopen(argv[1], "r");
	FILE *sol = fopen(argv[2], "r");
	FILE *out = fopen(argv[3], "r");
	int n;
	fscanf(in, " %d", &n);
	vector<int> board(n * 2);
	for (int i = 0; i < n * 2; i++) {
		fscanf(in, " %d", &board[i]);
	}
	int expected;
	fscanf(sol, " %d", &expected);
	int submit;
	// ASSERT: output is number
	assert(fscanf(out, " %d", &submit) == 1);
	// ASSERT: output is at least as good as expected. (allowing better answer than expected)
	assert(submit <= expected);

	for (int i = 0; i < submit; i++) {
		int move;
		// ASSERT: output is number
		assert(fscanf(out, " %d", &move) == 1);
		// ASSERT: output is inside current board
		assert(0 < move && move < board.size());
		int t = board[move];
		board[move] = board[move - 1];
		board[move - 1] = t;
		for (int i = board.size() - 1; i > 0; i--) {
			if (board[i] == board[i - 1]) {
				board.erase(board.begin() + (i - 1), board.begin() + (i + 1));
				if (i > board.size()) {
					i = board.size();
				}
			}
		}
	}
	// ASSERT: board is cleared after moves
	assert(board.empty());

	char garbage[16] = { '\0', };
	fscanf(out, " %15s", &garbage);
	// ASSERT: output doesn't have unexpected elements
	assert(garbage[0] == '\0');

	fclose(in);
	fclose(sol);
	fclose(out);
	return 0;
}
