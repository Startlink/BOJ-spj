#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    FILE *sol = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "r");

    int n;
    fscanf(in, "%d", &n);

    // arr[i]: Book # of i-th student
    vector<int> arr(n + 1);

    // chk[i][j]: whether i-th student read j-th book
    vector<vector<bool>> chk(n + 1, vector<bool>(n + 1));

    for(int i = 1; i <= n; i++)
    {
        arr[i] = i;
        chk[i][i] = true;
    }

    // At most 4950 replacements
    for(int i = 0; i < 4950; i++)
    {
        int x, y;
        if(fscanf(out, "%d", &x) != 1)
            break;
        assert(fscanf(out, "%d", &y) == 1);

        assert(1 <= x && x <= n && 1 <= y && y <= n);
        assert(x != y);

        swap(arr[x], arr[y]);

        chk[x][arr[x]] = true;
        chk[y][arr[y]] = true;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            assert(chk[i][j]);

    fscanf(out, " ");
    assert(feof(out));

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}
