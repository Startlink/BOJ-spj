#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

static char buf[1010];

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    FILE *sol = fopen(argv[2], "r");
    FILE *out = fopen(argv[3], "r");

    int tn;
    fscanf(in, "%d", &tn);
    for(int ti = 1; ti <= tn; ti++)
    {
        int n, r, o, y, g, b, v;
        fscanf(in, "%d%d%d%d%d%d%d", &n, &r, &o, &y, &g, &b, &v);

        fscanf(sol, "Case #%*d:%1001s ", buf);
        bool possible = strcmp(buf, "IMPOSSIBLE") == 0 ? false : true;

        int t = 0;
        assert(fscanf(out, "Case #%d:%1001s ", &t, buf) == 2);
        assert(t == ti);

        if(!possible)
        {
            assert(strcmp(buf, "IMPOSSIBLE") == 0);
            continue;
        }

        assert((int)strlen(buf) == n);
        for(int i = 0; i < n; i++)
        {
            char c = buf[i];
            char d = buf[(i + 1) % n];
            switch(c)
            {
            case 'R':
                assert(d == 'Y' || d == 'B' || d == 'G');
                assert(r >= 1);
                r--;
                break;
            case 'O':
                assert(d == 'B');
                assert(o >= 1);
                o--;
                break;
            case 'Y':
                assert(d == 'B' || d == 'R' || d == 'V');
                assert(y >= 1);
                y--;
                break;
            case 'G':
                assert(d == 'R');
                assert(g >= 1);
                g--;
                break;
            case 'B':
                assert(d == 'R' || d == 'Y' || d == 'O');
                assert(b >= 1);
                b--;
                break;
            case 'V':
                assert(d == 'Y');
                assert(v >= 1);
                v--;
                break;
            default:
                assert(false);
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
