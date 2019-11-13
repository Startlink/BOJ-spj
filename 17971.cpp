#include <bits/stdc++.h>
using namespace std;

vector<int> arr[51];

int main(int argc, char** argv)
{
    FILE* in = fopen(argv[1], "r");
    FILE* sol = fopen(argv[2], "r");
    FILE* out = fopen(argv[3], "r");

    int ans;
    fscanf(sol, "%d", &ans);

    int m;
    assert(fscanf(out, "%d", &m) == 1);
    assert(m == ans);

    vector<pair<int, int>> v;

    int n;
    fscanf(in, "%d", &n);
    for(int i = 1; i < n; i++)
    {
        arr[i].push_back(0);
        while(1)
        {
            int x;
            fscanf(in, "%d", &x);
            if(x == 0)
                break;

            arr[i].push_back(x);
            v.push_back({ x, i });
        }
    }

    sort(v.begin(), v.end());

    vector<int> per(n + 1);
    for(int i = 1; i <= n; i++)
        per[i] = i;

    for(auto p : v)
    {
        int x = p.second;
        swap(per[x], per[x + 1]);
    }

    vector<pair<int, int>> v2;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        assert(fscanf(out, "%d%d", &x, &y) == 2);

        assert(1 <= x && x < n);
        assert(1 <= y && y < (int)arr[x].size());
        assert(arr[x][y] != -1);

        v2.push_back({ arr[x][y], x });
        arr[x][y] = -1;
    }

    sort(v2.begin(), v2.end());

    vector<int> per2(n + 1);
    for(int i = 1; i <= n; i++)
        per2[i] = i;

    for(auto p : v2)
    {
        int x = p.second;
        swap(per2[x], per2[x + 1]);
    }

    assert(per == per2);

    fscanf(out, " ");
    assert(feof(out));

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}

