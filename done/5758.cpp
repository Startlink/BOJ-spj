#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
bool check(){
    int N = inf.readInt();
    if(N == 0) return false; // end of test case
    vector<int> inp(N);
    for(int i=0;i<N;i++) inp[i] = inf.readInt();
    string jr = ans.readToken();
    if(jr == "No"){
        ans.readToken(); // solution
        quitif(ouf.readToken() != "No", _wa, "Wrong answer in No solution case");
        quitif(ouf.readToken() != "solution", _wa, "Wrong answer in No solution case");
    }
    else{
        int M = stoi(jr);
        for(int i=0;i<M;i++) ans.readInt();
        M = ouf.readInt(0,4*N*N-1);
        for(int i=0;i<M;i++){
            int x = ouf.readInt(1,N-1);
            swap(inp[x-1],inp[x]);
        }
        for(int i=0;i<N;i++){
            quitif(inp[i] != i+1, _wa, "swap sequence does not match the output");
        }
    }
    return true;
}
int main(int argc, char* argv[]){
	registerTestlibCmd(argc, argv);
    while(check()); // check() returns false at the end of test case("0")
    quitf(_ok, "Correct");
}
