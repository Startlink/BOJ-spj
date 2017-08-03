#include <cstdio>
#include <cassert>
#include <string.h>

using namespace std;

char str[2003];
char user[2003], ans[2003];

int main(int argc, char **argv){
    
    FILE *in = fopen(argv[1], "r");  // input 
    FILE *sol = fopen(argv[2], "r"); // answer
    FILE *out = fopen(argv[3], "r"); // user's solution
        
    while(fscanf(in, "%s", str) == 1){
        fscanf(sol, "%s", ans);
        int s = strlen(str);
        assert(fscanf(out, "%s", user) == 1);
        int u = strlen(user);
        int a = strlen(ans);
        assert(u == a);
        int p = 0;
        for(int i=0; i<s && p<u; i++){
            if(str[i] == user[p])p++;
        }
        assert(p == u);
    }
    
    assert(fscanf(out, "%s", user) != 1);
    
    return 0;

}