#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll area2(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	return llabs(
		x1 * y2 + x2 * y3 + x3 * y1 -
		x2 * y1 - x3 * y2 - x1 * y3
	);
}

char line[10240];
char param[6][10240];

int main(int agrc, char **agrv){
    FILE *in = fopen(agrv[1],"r");
    FILE *out = fopen(agrv[3],"r");

	int T;
	fscanf(in, "%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		int n, m, a;
		fscanf(in, "%d%d%d", &n, &m, &a);
		assert(fgets(line, 10240, out) != nullptr);

		int tcid;
		int param_cnt = sscanf(line, "Case #%d: %s%s%s%s%s%s", &tcid, param[0], param[1], param[2], param[3], param[4], param[5]);
		assert(param_cnt >= 2 && tcid == tt);

		if (a > n * m)
		{
			assert(param_cnt == 2);
			assert(strcmp(param[0], "IMPOSSIBLE") == 0);
		}
		else
		{
			assert(param_cnt == 7);
			ll dat[6];

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; param[i][j]; j++)
				{
					assert(isdigit(param[i][j]));
				}
				dat[i] = strtoll(param[i], nullptr, 10);
				assert(dat[i] >= 0);
				if (i % 2 == 0) assert(dat[i] <= n);
				else assert(dat[i] <= m);
			}

			ll ret = area2(dat[0], dat[1], dat[2], dat[3], dat[4], dat[5]);

			assert(ret == a);
		}
	}

	assert(fscanf(out, " %c", line) != 1);
}
