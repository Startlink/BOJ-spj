#include <cstdio>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char buffer[1000000];
string read_string(FILE *fp) {
    assert(fscanf(fp,"%10000s",buffer)==1);
    return string(buffer);
}
int read_int(FILE *fp) {
    int temp;
    assert(fscanf(fp,"%d",&temp)==1);
    return temp;
}
long long read_long(FILE *fp) {
    long long temp;
    assert(fscanf(fp,"%lld",&temp)==1);
    return temp;
}
long long read_double(FILE *fp) {
    double temp;
    assert(fscanf(fp,"%lf",&temp)==1);
    return temp;
}
void assert_eof(FILE *fp) {
    assert(fscanf(fp,"%10000s",buffer)!=1);
}
vector<int> a[1001];
bool ca[1001];
bool cb[1001];
int main(int agrc, char **agrv){
    FILE *in = fopen(agrv[1],"r");
    FILE *sol = fopen(agrv[2],"r");
    FILE *out = fopen(agrv[3],"r");
    int n = read_int(in);
    int m = read_int(in);
    for (int i=1; i<=n; i++) {
        int k = read_int(in);
        while (k--) {
            int t = read_int(in);
            a[i].push_back(t);
        }
    }
    fclose(in);
    int ans = read_int(sol);
    fclose(sol);
    int yourans = read_int(out);
    assert(ans == yourans);
    int t1 = read_int(out);
    assert(0 <= t1 && t1 <= n);
    for (int i=0; i<t1; i++) {
        int t = read_int(out);
        assert(1 <= t && t <= n);
        assert(ca[t] == false);
        ca[t] = true;
    }
    int t2 = read_int(out);
    assert(0 <= t2 && t2 <= m);
    for (int i=0; i<t2; i++) {
        int t = read_int(out);
        assert(1 <= t && t <= m);
        assert(cb[t] == false);
        cb[t] = true;
    }
    for (int i=1; i<=n; i++) {
        for (int j : a[i]) {
            assert(ca[i] || cb[j]);
        }
    }
    fclose(out);
    return 0;
}
