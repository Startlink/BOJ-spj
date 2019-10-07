#include <cstdio>
#include <cassert>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

string generate(set<string>& valid, ifstream& in) {
  string ret = "";
  string s;
  while(in >> s) {
    assert(valid.count(s));
    ret += s;
  }
  return ret;
}

void checkCase(ifstream& iStream, ifstream& sStream, ifstream& oStream) {
  int n;
  iStream >> n;
  set<string> validWords;
  while(n--) {
    string s;
    iStream >> s;
    validWords.insert(s);
  }
  string goal;
  iStream >> goal;
  string solution = generate(validWords, sStream);
  int numVowels = 0;
  for(int i = 0; i < solution.size(); i++) {
    numVowels += solution[i] == 'A';
    numVowels += solution[i] == 'E';
    numVowels += solution[i] == 'I';
    numVowels += solution[i] == 'O';
    numVowels += solution[i] == 'U';
  }
  string ours = generate(validWords, oStream);
  string cons = "";
  for(int i = 0; i < ours.size(); i++) {
    bool isVowel = false;
    isVowel |= ours[i] == 'A';
    isVowel |= ours[i] == 'E';
    isVowel |= ours[i] == 'I';
    isVowel |= ours[i] == 'O';
    isVowel |= ours[i] == 'U';
    if(isVowel) numVowels--;
    else cons += ours[i];
  }
  // check that the number of vowels matches
  assert(numVowels == 0);
  assert(cons == goal);
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
