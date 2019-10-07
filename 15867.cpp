#include "testlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h> 
 
using namespace std;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long llu; 
typedef pair<int, int> pii;


const int MAX = 100010;
int n, U[MAX], su[MAX], m=0;
map<pii, int> mp;
pii mem[2*MAX];

pii GB[MAX], GC[MAX];

int find(int x){ return x==U[x] ? x : find(U[x]); }
void unite(int x, int y){
	x = find(x), y = find(y);
	if(x==y) return;
	if(su[x]>su[y]) swap(x,y);
	su[y] += su[x]; U[x] = y;
}


int main(int argc, char * argv[]) {
	registerTestlibCmd(argc, argv);
	// inf, ouf, ans

	int k = ans.readInt();
	if(k!=ouf.readInt()){
		quit(_wa, "Wrong");
	}

	n = inf.readInt();

	for(int i=0; i<n; i++) U[i]=i, su[i]=1;

	for(int i=1; i<n; i++){
		int u=inf.readInt(), v=inf.readInt();
		if(u>v) swap(u,v);
		mem[++m] = {find(u), find(v)};
		mp[pii(u,v)] = m;
	}
	for(int i=1; i<n; i++){
		int u=inf.readInt(), v=inf.readInt();
		if(u>v) swap(u,v);
		GB[i]={u,v};
	}
	sort(GB+1, GB+n);

	for(int i=1; i<=k; i++){
		int a,b, u,v;
		a=ouf.readInt(), b=ouf.readInt();
		u=ouf.readInt(), v=ouf.readInt();
		if(a>b) swap(a,b);
		if(u>v) swap(u,v);

		if(mp.find({a,b})==mp.end()) quit(_wa, "Wrong");
		int x,y; tie(x,y) = mem[mp[pii(a,b)]];
		mp.erase(pii(a,b));
		if(su[x]>su[y]) swap(x,y);
		for(int z=U[x]; z!=U[z]; z=U[z]) su[z]-=su[x];
		U[x] = x;

		if(find(u)==find(v)) quit(_wa, "Wrong");
		mem[++m] = {find(u), find(v)};
		mp[pii(u,v)] = m;

//		for(auto q:mp){
//			cout<<q.first.first<<", "<<q.first.second<<": "<<q.second<<'\n';
//		}
//		cout<<'\n';
	}
	
	int o = 0;
	for(auto q:mp){
		int u,v; tie(u,v) = q.first;
		if(u>v) swap(u,v);
		GC[++o] = {u,v};
	}
	sort(GC+1, GC+n);

//	for(int i=1; i<n; i++){
//		cout<<"B: "<<GB[i].first<<' '<<GB[i].second<<". C: "<<GC[i].first<<' '<<GC[i].second<<'\n';
//	}

	for(int i=1; i<n; i++) if(GC[i]!=GB[i]) quit(_wa, "Wrong");
	quitp(100, "Correct");
	return 0;
}
