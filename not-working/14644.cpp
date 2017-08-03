#include <bits/stdc++.h>
using namespace std;

char buf[5005];

bool read_token(vector<string> &ans, FILE *fp){
  if(fscanf(fp, "%s", buf) == -1) return 0;
  string s = buf;
  ans.push_back(s);
  return 1;
}

int main(){
  FILE *fp1 = fopen(argv[2], "r");
  FILE *fp2 = fopen(argv[2], "r");
  vector<string> v1, v2;
  while(read_token(v1, fp1));
  while(read_token(v2, fp2));
  assert(v1 == v2); // woah!
}