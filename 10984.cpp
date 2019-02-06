#include <cstdio>
#include <cassert>
using namespace std;

char z[5];

int main(int argc, char **argv){
  FILE *in = fopen(argv[1], "r");
  FILE *sol = fopen(argv[2], "r");
  FILE *out = fopen(argv[3], "r");

  int T; fscanf(in, "%d", &T);

  for(; T--; ){
    int N; fscanf(in, "%d", &N);

    int s = 0, t = 0;

    for(; N--; ){
      int a; fscanf(in, "%d", &a);
      fscanf(in, "%s", z);

      int v = (z[0] & 15) * 10;
      if(z[1] == '.') v += z[2] & 15;

      s += a; t += a * v;
    }

    int ss; double tt;

    assert(fscanf(out, "%d", &ss) == 1);

    assert(ss == s);

    assert(fscanf(out, "%lf", &tt) == 1);

    tt *= 10 * s;
    assert(tt >= t - s && tt <= t + s);
  }

  assert(fscanf(out, " %c", z) == EOF);

  fclose(in);
  fclose(sol);
  fclose(out);
  return 0;
}
