#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template <typename T, int S> inline int arraysize(const T(&v)[S]) { return S; }

struct Data {
	string name;
	int points;
	int goaldiff;

	Data() : name(""), points(0), goaldiff(0) {}
};

int main(int, char** argv) {
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[3], "r");
	char line[128];

	while (true) {
		fgets(line, arraysize(line), in);
		int n = atoi(line);
		if (n == 0) break;
		unordered_map<string, Data> teams;
		for (; n > 0; n--) {
			fgets(line, arraysize(line), in);
			string team1 = strtok(line, " ");
			int score1 = atoi(strtok(nullptr, " "));
			strtok(nullptr, " ");	// "X"
			int score2 = atoi(strtok(nullptr, " "));
			string team2 = strtok(nullptr, " \n");
			if (teams.find(team1) == teams.end()) {
				teams[team1].name = team1;
			}
			if (teams.find(team2) == teams.end()) {
				teams[team2].name = team2;
			}
			if (score1 > score2) {
				int d = score1 - score2;
				teams[team1].points += 3;
				teams[team1].goaldiff += d;
				teams[team2].goaldiff -= d;
			} else if (score1 < score2) {
				int d = score2 - score1;
				teams[team2].points += 3;
				teams[team1].goaldiff -= d;
				teams[team2].goaldiff += d;
			} else {
				teams[team1].points++;
				teams[team2].points++;
			}
		}

		map<int, map<int, unordered_set<string>, greater<int>>, greater<int>> board;
		for (auto p : teams) {
			Data &d = p.second;
			board[d.points][d.goaldiff].emplace(d.name);
		}
		for (auto pointsPair : board) {
			for (auto goaldiffPair : pointsPair.second) {
				auto& candidate = goaldiffPair.second;
				unordered_set<string> output;
				for (int i = candidate.size(); i > 0; i--) {
					// ASSERT: output has some line
					assert(fgets(line, arraysize(line), out) != nullptr);
					char *token = strtok(line, " ");
					// ASSERT: output has score
					assert(token != nullptr);
					int points = atoi(token);
					// ASSERT: points are same as current candidate
					assert(points == pointsPair.first);
					token = strtok(nullptr, " \n");
					// ASSERT: output has team name
					assert(token != nullptr);
					string teamname = token;
					// ASSERT: team name belongs to current candidates
					assert(candidate.find(teamname) != candidate.end());
					// ASSERT: output doesn't have duplicate team name
					assert(output.find(teamname) == output.end());
					output.emplace(teamname);
				}
			}
		}
		char *newline = fgets(line, arraysize(line), out);
		// ASSERT: output is one of this case
		// 1. end-of-file (note: if there are more input data but eof occures, next assert will fail)
		// 2. blank line with ending '\n'
		// 3. blank line without ending '\n'
		assert(feof(out) || newline != nullptr && (line[0] == '\0' || (line[0] == '\n' && line[1] == '\0')));
	}
	line[0] = '\0';
	fscanf(out, " %15s", &line);
	// ASSERT: output doesn't have unexpected elements
	assert(line[0] == '\0');

	fclose(in);
	fclose(out);
	return 0;
}
