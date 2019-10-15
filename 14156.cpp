#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

char buf[16 + 2];

int main(int argc, char** argv)
{
    FILE* in = fopen(argv[1], "r");
    FILE* sol = fopen(argv[2], "r");
    FILE* out = fopen(argv[3], "r");

    int n;
    fscanf(in, "%d", &n);

    vector<bool> chk(1 << n);
    int p = -1;
    for(int i = 0; i < (1 << n); i++)
    {
        assert(fscanf(out, "%17s", buf) == 1);
        assert(strlen(buf) == n);

        int c = 0;
        for(int j = 0; j < n; j++)
        {
            assert(buf[j] == '0' || buf[j] == '1');
            if(buf[j] == '1')
                c |= 1 << j;
        }

        assert(!chk[c]);
        chk[c] = true;

        if(p != -1)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
                if((p ^ c) & (1 << j))
                    cnt++;

            assert(cnt == 1);
        }

        p = c;
    }

    fscanf(out, " ");
    assert(feof(out));

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}

