#include "testlib.h"

#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MX = 250005;
int chk[MX] = {};
int A[MX], B[MX];

int main(int argc, char * argv[])
{
	swap(argv[2], argv[3]);
	registerTestlibCmd(argc, argv);
	int N = inf.readInt();
	int K = ouf.readInt();
	int K2 = ans.readInt();
	if( K != K2 ) quitf(_wa, "# of order mismatch");
	for(int i = 1; i <= K; i++){
		int a = ouf.readInt();
		if(a < 0 || a > N ) quitf(_wa, "order out of range");
		if(chk[a]) quitf(_wa, "duplicated order");
		chk[a] = 1;
	}
	for(int i = 1; i <= N; i++) A[i] = inf.readInt();
	for(int i = 1; i <= N; i++) B[i] = inf.readInt();
	ll tot = 0;
	for(int i = 1; i <= N; i++){
		tot += A[i];
		if( chk[i] ) tot -= B[i];
		if( tot < 0 ) quitf(_wa, "not enough package");
	}
	quitf(_ok, "correct");
	return 0;
}
