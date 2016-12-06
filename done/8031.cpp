#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

int tc, tci[55];

namespace miller_rabin{
	lint mul(lint a, lint b, lint p){
		lint ret = 0;
		while(a){
			if(a&1) ret = (ret + b) % p;
			a >>= 1;
			b = (b << 1) % p;
		}
		return ret;
	}
	lint ipow(lint x, lint y, lint p){
		lint ret = 1, piv = x % p;
		while(y){
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(lint x, lint a){
		if(x % a == 0) return 0;
		lint d = x - 1;
		while(1){
			lint tmp = ipow(a, d, x);
			if(d&1) return (tmp != 1 && tmp != x-1);
			else if(tmp == x-1) return 0;
			d >>= 1;
		}
	}
	bool isprime(lint x){
		for(auto &i : {2, 3, 5, 7, 11}){
			if(x == i) return 1;
			if(x > 11 && miller_rabin(x, i)) return 0;
		}
		if(x <= 11) return 0;
		return 1;
	}
}

int main(int agrc, char **agrv){
	FILE *in = fopen(agrv[1],"r");
	FILE *sol = fopen(agrv[2],"r");
	FILE *out = fopen(agrv[3],"r");
	assert(fscanf(in, "%d", &tc) == 1);
	for(int i=0; i<tc; i++){
		int n;
		assert(fscanf(in, "%d", &tci[i]) == 1);
		assert(fscanf(out, "%d", &n) == 1);
		assert(1 <= n && n <= 200000); // check if input is reasonable
		lint ret = 0;
		set<int> s;
		for(int i=0; i<n; i++){
			int w;
			assert(fscanf(out, "%d", &w) == 1);
			ret += w;
			assert(w > 2 && w % 2 == 1 && miller_rabin::isprime(w) && s.find(w) == s.end());
			s.insert(w);
		}
		assert(ret == tci[i]);
	}
	fclose(in);
	fclose(sol);
	fclose(out);
}

