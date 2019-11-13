#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    FILE* in = fopen(argv[1], "r");
    FILE* sol = fopen(argv[2], "r");
    FILE* out = fopen(argv[3], "r");

    int n;
    fscanf(in, "%d", &n);

    vector<vector<bool>> edg(n + 1, vector<bool>(n + 1));
    for(int i = 0; i < n / 2; i++)
    {
        vector<int> v(n);
        for(int j = 0; j < n; j++)
        {
            assert(fscanf(out, "%d", &v[j]) == 1);
            assert(1 <= v[j] && v[j] <= n);
        }

        vector<bool> chk(n + 1);
        for(int j = 0; j < n; j++)
        {
            assert(!chk[v[j]]);
            chk[v[j]] = true;
        }

        for(int j = 0; j < n; j++)
        {
            int x = v[j];
            int y = v[(j + 1) % n];

            assert(!edg[x][y]);
            edg[x][y] = edg[y][x] = true;
        }
    }

    fscanf(out, " ");
    assert(feof(out));

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}