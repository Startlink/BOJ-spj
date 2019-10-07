#include <cstdio>
#include <cassert>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void checkCase(ifstream& iStream, ifstream& sStream, ifstream& oStream) {
  // read case token and other thing and check for match
  string sc1, sc2;
  string oc1, oc2;
  assert(sStream >> sc1);
  assert(sStream >> sc2);
  oStream >> oc1 >> oc2;
  assert(sc1 == oc1);
  assert(sc2 == oc2);
  // read in input strings
  int n;
  iStream >> n;
  vector<string> tokens;
  tokens.resize(n);
  for(int i = 0; i < n; i++) {
    iStream >> tokens[i];
  }
  string ourAns, realAns;
  oStream >> ourAns;
  sStream >> realAns;
  if(realAns == "IMPOSSIBLE") {
    assert(ourAns == "IMPOSSIBLE");
    return;
  }
  assert(ourAns.size() == 26);
  set<char> ss;
  for(int i = 0; i < 26; i++) ss.insert(ourAns[i]);
  for(char ch = 'A'; ch <= 'Z'; ch++) assert(ss.count(ch));
  for(string out: tokens) {
    assert(ourAns.find(out) == string::npos);
  }
}

int main(int argc, char **argv) {
  /*
  FILE *in = fopen(argv[1],"r");
  FILE *sol = fopen(argv[2],"r");
  FILE *out = fopen(argv[3],"r");
  */
  ifstream inputStream(argv[1]);
  ifstream solutionStream(argv[2]);
  ifstream outputStream(argv[3]);
  int t;
  inputStream >> t;
  while(t--) {
    checkCase(inputStream, solutionStream, outputStream);
  }
  string s;
  assert(!(outputStream >> s));
  return 0;
}
