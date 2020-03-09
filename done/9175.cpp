#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
inline void myass(const bool chk) { quitif(!chk, _wa, "Wrong Answer"); }

bitset<1000> chkA, chkB, chkC;

int T, N;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);

	T = inf.readInt();
	for(int ti = 1, n; ti <= T; ti++) {
		N = inf.readInt();

		n = ouf.readInt(N, N);
    
    chkA.reset();
    chkB.reset();
    chkC.reset();
		for(int x = 0, y; x < N; x++) {
			y = ouf.readInt(0, N-1);
			myass(!chkA[y] && !chkB[x+y] && !chkC[x-y+305]);
			chkA[y] = chkB[x+y] = chkC[x-y+305] = true;
		}
	}

	quitf(_ok, "Correct");
}
