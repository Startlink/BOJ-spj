#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    FILE *sol = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "r");

    int t;
    fscanf(sol, "%d", &t);
    if (t == -1)
    {
        int t2;
        assert(fscanf(out, "%d", &t2) == 1);
    }
    else
    {
        int n;
        vector<int> arr[2];
        fscanf(in, "%d", &n);
        for (int b = 0; b < 2; b++)
        {
            arr[b].resize(n);
            for (int i = 0; i < n; i++)
                fscanf(in, "%d", &arr[b][i]);
        }

        vector<int> ord;
        ord.resize(n);
        for (int i = 0; i < n; i++)
            assert(fscanf(out, "%d", &ord[i]) == 1);

        vector<bool> chk;
        chk.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            assert(1 <= ord[i] && ord[i] <= n);
            assert(!chk[ord[i]]);
            chk[ord[i]] = true;
        }

        for (int b = 0; b < 2; b++)
        {
            int p, q;
            for (int i = 0; i < n; i++)
            {
                if (arr[b][i] == ord[0])
                {
                    p = (i - 1 + n) % n;
                    q = (i + 1) % n;
                    break;
                }
            }

            for (int i = 1; i < n; i++)
            {
                if (ord[i] == arr[b][p])
                    p = (p - 1 + n) % n;
                else if (ord[i] == arr[b][q])
                    q = (q + 1) % n;
                else
                    assert(0);
            }
        }
    }

    fscanf(out, " ");
    assert(feof(out));

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}