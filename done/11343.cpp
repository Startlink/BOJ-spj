#include <cstdio>
#include <cassert>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef pair<int,int> ip;

char b[102][102];
int n, m;
char buf[101], userRes[10001];

int main(int argc, char **argv) {
	FILE* in=fopen(argv[1],"r");
	FILE* sol=fopen(argv[2],"r");
	FILE* out=fopen(argv[3],"r");

	int tc;
	fscanf(in,"%d",&tc);
	while(tc--) {
		fscanf(in,"%d %d",&n,&m);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++)
				fscanf(in," %c",&b[i][j]);
		}
		fscanf(sol,"%s",buf);
		if(buf[0]=='n') {
			fscanf(sol,"%s %s",buf,buf);
			assert(fscanf(out,"%s",buf)==1 && !strcmp(buf,"no"));
			assert(fscanf(out,"%s",buf)==1 && !strcmp(buf,"set"));
			assert(fscanf(out,"%s",buf)==1 && !strcmp(buf,"found"));
			continue;
		} else {
			for(int i=0;i<5;i++)
				fscanf(sol,"%s",buf);
			ip res[3];
			for(int i=0;i<3;i++) {
				assert(fscanf(out,"%d %d",&res[i].first,&res[i].second)==2);
				assert(1<=res[i].first && res[i].first<=n);
				assert(1<=res[i].second && res[i].second<=m);
				if(i) assert(res[i-1].first<res[i].first || (res[i-1].first==res[i].first && res[i-1].second<res[i].second));
			}
			if(res[0].first==res[1].first) {
				assert(res[1].first==res[2].first);
				assert(res[0].second+1==res[1].second && res[1].second+1==res[2].second);
			} else {
				assert(res[0].first+1==res[1].first && res[1].first+1==res[2].first);
				assert(res[0].second==res[1].second && res[1].second==res[2].second);
			}
			assert(b[res[0].first][res[0].second]==b[res[1].first][res[1].second] && b[res[1].first][res[1].second]==b[res[2].first][res[2].second]);
		}
	}
	assert(fscanf(out,"%s",buf)!=1);
	return 0;
}
