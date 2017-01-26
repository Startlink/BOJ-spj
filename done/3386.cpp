#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;

int arr[1009];
int matched[1009][1009];
char sol_result[15];
char out_result[15];

int main(int agrc, char **argv){
    FILE *in = fopen(argv[1],"r");
    FILE *sol = fopen(argv[2],"r");
    FILE *out = fopen(argv[3],"r");

    int n,i,j;
    fscanf(in,"%d",&n);
    for(i=1;i<=n;i++)
        fscanf(in,"%d",&arr[i]);

    fgets(sol_result, sizeof(sol_result), sol);
    fgets(out_result, sizeof(out_result), out);

    int sol_len = strlen(sol_result);
    int out_len = strlen(out_result);
    assert(sol_len == out_len);
    for(i=0;i<sol_len;i++)
        assert(sol_result[i] == out_result[i]);

    if(sol_result[0] == 'N') {
        int check;
        assert(fscanf(out, "%d", check) == EOF);
        fclose(in);
        fclose(sol);
        fclose(out);
        return 0;
    }

    int tmp, before;
    for(i=1;i<=n;i++) {
        before = -1;
        while(arr[i]--) {
            assert(fscanf(out,"%d",&tmp) == 1);
            assert(1 <= tmp && tmp <= n);
            assert(before < tmp);
            assert(i!=tmp);
            ++matched[i][tmp];
            ++matched[tmp][i];
            before = tmp;
        }
    }

    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            assert(matched[i][j] == 0 || matched[i][j] == 2);
        }
    }

    int check;
    assert(fscanf(out, "%d", &check) == EOF);

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}
