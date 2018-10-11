#include <cstdio>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

static char buf[110];
static char tmp[110];

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    FILE *sol = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "r");

    fscanf(sol, "%100s", buf);    // Remove "Case" (sol)
    bool found_case_out = false;  // Found "Case" in advance (out)

    int tn;
    fscanf(in, "%d", &tn);
    for(int ti = 1; ti <= tn; ti++)
    {
        int k, c, s;
        fscanf(in, "%d%d%d", &k, &c, &s);

        long long mx = 1;
        for(int i = 0; i < c; i++)
            mx *= k;  // Guaranteed to not exceed 10^18

        bool possible = true;
        while(!feof(sol))
        {
            fscanf(sol, "%100s", buf);
            if(strcmp(buf, "Case") == 0)
                break;
            if(strcmp(buf, "IMPOSSIBLE") == 0)
                possible = false;
        }

        if(!found_case_out)
        {
            assert(fscanf(out, "%100s", buf) == 1);
            assert(strcmp(buf, "Case") == 0);
        }
        found_case_out = false;

        assert(fscanf(out, "%100s", buf) == 1);
        sprintf(tmp, "#%d:", ti);
        assert(strcmp(buf, tmp) == 0);

        // Impossible case
        if(!possible)
        {
            assert(fscanf(out, "%100s", buf) == 1);
            assert(strcmp(buf, "IMPOSSIBLE") == 0);
            continue;
        }

        // Possible case
        vector<long long> v;
        while(!feof(out))
        {
            assert(fscanf(out, "%100s", buf) == 1);
            if(strcmp(buf, "Case") == 0)
            {
                found_case_out = true;
                break;
            }

            long long x = 0;
            assert(sscanf(buf, "%lld", &x) == 1);
            sprintf(tmp, "%lld", x);
            assert(strcmp(buf, tmp) == 0);
            assert(1 <= x && x <= mx);
            assert((int)v.size() < s);
            v.push_back(x);
        }
        assert(!v.empty());

        sort(v.begin(), v.end());

        int sz = (int)v.size();
        for(int i = 0; i < sz - 1; i++)
            assert(v[i] != v[i + 1]);

        // Use 0-based index from now on
        vector<bool> chk(k, false);
        for(long long x : v)
        {
            x--;  // Converting to 0-based index

            for(int i = 0; i < c; i++)
            {
                chk[x % k] = true;
                x /= k;
            }
        }

        for(int i = 0; i < k; i++)
            assert(chk[i]);  // Possible 'G' at position i+1 is not considered

        if(ti == tn)
            assert(!found_case_out);  // Stray "Case" at the end of output
    }

    fscanf(out, " ");
    assert(feof(out));

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}
