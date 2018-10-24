#include <cstdio>
#include <cstring>
#include <cassert>
#include <queue>

using namespace std;

struct pos
{
    int x, y;
};

static const int dx[4] = { 1, 0, -1, 0 };
static const int dy[4] = { 0, 1, 0, -1 };

static char buf[110];
static char tmp[110];

static char arr[110][110];
static pos sld[110];
static pos tur[110];

static bool chks[110];
static bool chkt[110];
static int sta[110][110];
static bool vit[110][110];

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    FILE *sol = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "r");

    int tn;
    fscanf(in, "%d", &tn);
    for(int ti = 1; ti <= tn; ti++)
    {
        int c, r, m;
        fscanf(in, "%d%d%d", &c, &r, &m);
        for(int i = 0; i < r; i++)
            fscanf(in, "%s", arr[i]);

        int s = 0;
        int t = 0;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(arr[i][j] == 'S')
                    sld[++s] = { i, j };
                else if(arr[i][j] == 'T')
                    tur[++t] = { i, j };
            }
        }

        for(int i = 1; i <= s; i++)
            chks[i] = false;
        for(int i = 1; i <= t; i++)
            chkt[i] = false;

        fscanf(sol, "%*s%*s");
        int ans1;
        fscanf(sol, "%d", &ans1);
        for(int i = 0; i < ans1; i++)
            fscanf(sol, "%*d%*d");

        assert(fscanf(out, "%100s", buf) == 1);
        assert(strcmp(buf, "Case") == 0);

        assert(fscanf(out, "%100s", buf) == 1);
        sprintf(tmp, "#%d:", ti);
        assert(strcmp(buf, tmp) == 0);

        int ans2;
        assert(fscanf(out, "%d", &ans2) == 1);
        assert(ans1 == ans2);

        for(int it = 0; it < ans2; it++)
        {
            int p, q;
            assert(fscanf(out, "%d%d", &p, &q) == 2);
            assert(1 <= p && p <= s && 1 <= q && q <= t);
            assert(!chks[p] && !chkt[q]);

            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    sta[i][j] = 0;
                    vit[i][j] = false;
                }
            }

            for(int i = 1; i <= t; i++)
            {
                if(chkt[i])
                    continue;
                int x = tur[i].x;
                int y = tur[i].y;
                for(int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    while(0 <= nx && nx < r && 0 <= ny && ny < c && arr[nx][ny] != '#')
                    {
                        if(i == q)
                            sta[nx][ny] = 2;
                        else if(sta[nx][ny] == 0)
                            sta[nx][ny] = 1;

                        nx += dx[d];
                        ny += dy[d];
                    }
                }
            }

            queue<pos> que;
            que.push(sld[p]);
            vit[sld[p].x][sld[p].y] = true;

            bool ok = false;
            for(int i = 0; i <= m; i++)
            {
                int sz = que.size();
                for(int j = 0; j < sz; j++)
                {
                    int x = que.front().x;
                    int y = que.front().y;
                    que.pop();

                    if(sta[x][y] == 2)
                    {
                        ok = true;
                        break;
                    }

                    if(sta[x][y] == 1)
                        continue;

                    for(int d = 0; d < 4; d++)
                    {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(0 <= nx && nx < r && 0 <= ny && ny < c && arr[nx][ny] != '#' && arr[nx][ny] != 'T' && !vit[nx][ny])
                        {
                            vit[nx][ny] = true;
                            que.push({ nx, ny });
                        }
                    }
                }
                if(ok)
                    break;
            }

            assert(ok);

            chks[p] = true;
            chkt[q] = true;
            arr[tur[q].x][tur[q].y] = '.';
        }
    }

    fscanf(out, " ");
    assert(feof(out));

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}
