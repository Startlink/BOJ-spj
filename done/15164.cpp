#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<set>
#include<string>
using namespace std;

constexpr int MAX_MATCH = 10000;
constexpr int MAX_N = 1000;

set<string> left;
char buf[2002], a[22], b[22], c[22];

// atoi cannot be used since it ignores invalid chars followed by valid integer
// returns -1 if s is not valid integer.
int toint(char * s) {
	int ret = 0;
	for(int i=0;s[i];i++) {
		if(s[i] < '0' || s[i] > '9') return -1;
		ret *= 10;
		ret += s[i]-'0';
		if(ret > MAX_N) return -1;
	}
	return ret;
}

int main(int argc, char* argv[]) {
  // input test case
  FILE *in = fopen(argv[1],"r");
  // output of the user
  FILE *out = fopen(argv[3],"r");

  int n;
  fscanf(in,"%d",&n);
  for(int i=1;i<=n;i++) left.insert(itoa(i,buf,10));
  int m = MAX_MATCH;
  while(left.size() > 1) {
	// there cannot be more than MAX_MATCH matches.  
	m--;
	assert(m >= 0);
	
	assert(fgets(buf,sizeof(buf),out));
	assert(sscanf(buf,"%s%s%s",a,b,c) == 3);
	// A placeholder cannot be used as both a competitor and the winner in the
	// same match.
	// It is fine if both competitors in some match are the same.
	assert(strcmp(a,c));
	assert(strcmp(b,c));
	
	// placeholder must be a single lowercase letter.
	assert(strlen(c) == 1 && 'a'<= c[0] && c[0] <= 'z');
	
	// a and b must be in left if it is not number
	int x = toint(a);
	if(x<0) assert(left.count(a));
	x = toint(b);
	if(x<0) assert(left.count(b));
	
	// remove a and b in left and insert c
	left.erase(a);
	left.erase(b);
	left.insert(c);
  }
  assert(fscanf(out, "%s", buf) <= 0);
  assert(left.size() == 1 && *left.begin() == "a");
  
  fclose(in);
  fclose(out);
  
  return 0;
}
