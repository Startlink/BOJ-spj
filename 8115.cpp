#include <cstdio>
#include <cassert>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

string g[105];
int dx[4]{1,0,-1,0};
int dy[4]{0,-1,0,1};

int parseInt(string s) {
  int ret = 0;
  for(int i = 0; i < s.size(); i++) {
    ret *= 10;
    ret += s[i] - '0';
  }
  return ret;
}

void checkCase(ifstream& iStream, ifstream& sStream, ifstream& oStream) {
  int r, c;
  iStream >> r >> c;
  for(int i = 0; i < r; i++) {
    iStream >> g[i];
  }
  int sx, sy, ex, ey;
  iStream >> sx >> sy >> ex >> ey;
  sx--; sy--; ex--; ey--;
  string sshould, oshould;
  sStream >> sshould;
  oStream >> oshould;
  assert(sshould == oshould);
  if(sshould == "NIE") return;
  // read n lines from output
  int expect = parseInt(sshould);
  vector<pii> v;
  for(int i = 0; i < expect; i++) {
    int a, b;
    oStream >> a >> b;
    assert(a >= 1 && a <= r && b >= 1 && b <= c);
    v.push_back({--a, --b});
  }
  assert(v[0] == pii(sx, sy));
  assert(v.back() == pii(ex, ey));
  vector<int> dirs;
  for(int i = 1; i < v.size(); i++) {
    int dd = 0;
    while(dd < 4 && (v[i-1].first + dx[dd] != v[i].first || v[i-1].second + dy[dd] != v[i].second)) {
      dd++;
    }
    assert(dd < 4);
    dirs.push_back(dd);
  }
  for(int i = 1; i < dirs.size(); i++) {
    assert(dirs[i] == dirs[i-1] || dirs[i] == (dirs[i-1]+1)%4);
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
  checkCase(inputStream, solutionStream, outputStream);
  string s;
  assert(!(outputStream >> s));
  return 0;
}
