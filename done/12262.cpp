#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

char line[10245];
char str[10245];

void assert_testcase(FILE *fp, int tcid)
{
	assert(fgets(line, 10240, fp) != nullptr);

	int tt;
	char dummy;
	int param_cnt = sscanf(line, "Case #%d: %c", &tt, &dummy);
	assert(param_cnt == 1 && tt == tcid);
}

string get_line(FILE *fp)
{
	assert(fgets(line, 10240, fp) != nullptr);

	char dummy;
	assert(sscanf(line, "%s %c", str, &dummy) == 1);

	return str;
}

bool visit[55][55];

void validate_map(vector<string> mp, int r, int c, int m)
{
	assert(mp.size() == r);

	int mine_cnt = 0;
	int sx = -1, sy = -1;

	for (int i = 0; i < r; i++)
	{
		assert(mp[i].size() == c);

		for (int j = 0; j < c; j++)
		{
			assert(mp[i][j] == '.' || mp[i][j] == 'c' || mp[i][j] == '*');

			if (mp[i][j] == '*') ++mine_cnt;
			else if (mp[i][j] == 'c')
			{
				assert(sx == -1 && sy == -1);
				sx = i; sy = j;
			}
		}
	}

	assert(mine_cnt == m);
	assert(sx != -1 && sy != -1);

	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> que;
	visit[sx][sy] = true;
	que.emplace(sx, sy);

	while (que.empty() == false)
	{
		int x, y;
		tie(x, y) = que.front(); que.pop();

		bool mine = false;

		for (int dx = -1; dx <= 1 && !mine; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				int nx = x + dx; int ny = y + dy;
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

				if (mp[nx][ny] == '*')
				{
					mine = true;
					break;
				}
			}
		}

		if (mine) continue;

		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				int nx = x + dx; int ny = y + dy;
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

				if (visit[nx][ny]) continue;

				visit[nx][ny] = true;
				que.emplace(nx, ny);
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (mp[i][j] != '*') assert(visit[i][j]);
		}
	}
}

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *ans = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");

	int T;
	fscanf(in, "%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		assert_testcase(ans, tt);
		assert_testcase(out, tt);

		int r, c, m;
		fscanf(in, "%d%d%d", &r, &c, &m);

		vector<string> mp;

		string first_ans = get_line(ans);
		string first_out = get_line(out);

		if (strcasecmp(first_ans.c_str(), "Impossible") == 0)
		{
			assert(strcasecmp(first_out.c_str(), "Impossible") == 0);
			continue;
		}

		mp.push_back(move(first_out));

		for (int i = 1; i < r; i++)
		{
			mp.push_back(get_line(out));
			get_line(ans);
		}

		validate_map(move(mp), r, c, m);
	}

	assert(fscanf(out, " %c", line) != 1);
}
