#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
vector<int> v[2];
vector<int> yee;
bool check_subseq(){
    auto it = v[0].begin();
    for(int x : v[1]){
        if((*it) == x) ++it;
        if(it == v[0].end()) break;
    }
    return (it == v[0].end());
}
bool check_range(int l, int r){
    if(r == l) return true;
    int mid = (yee[r] + yee[l-1]) / 2;
    auto it = lower_bound(yee.begin() + (l-1), yee.begin() + r, mid);
    if((*it) != mid) return false;
    int idx = it - yee.begin();
    return check_range(l, idx) && check_range(idx+1, r);
}
bool check_valid(){
    int L = v[1].size();
    yee.resize(L+1);
    for(int i=0;i<L;i++){
        yee[i+1] = yee[i] + (1 << v[1][i]);
        if(yee[i+1] > (1<<30)) return false; // sum should be exactly 1<<30
    }
    if(yee[L] != (1<<30)) return false;
    return check_range(1, L);
}
bool check(){
    int N = inf.readInt();
    int K = inf.readInt();
    v[0] = inf.readInts(N, 0, 30);
    v[1] = ouf.readInts(N+K, 0, 30);
    quitif(!check_subseq(), _wa, "Output does not contain original sequence as a subsequence");
    quitif(!check_valid(), _wa, "Output is not a ZalSequence");
    return true;
}
int main(int argc, char* argv[]){
	registerTestlibCmd(argc, argv);
    check();
    quitf(_ok, "Correct");
}
