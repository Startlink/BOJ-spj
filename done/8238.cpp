/*
   oi.h - pakiet funkcji do pisania weryfikatorow wejsc (inwer) i wyjsc (chk)
   Wersja: 1.3
   Autor: Piotr Niedzwiedz
   W razie problemow, bledow lub pomyslow na ulepszenie pisac na dzwiedziux@gmail.com

   Historia:
   1.1: Poprawka readInt (liczby ujemne).
   1.2: Zmiana nazwy, dodano namespace oi, dodano Random i MultipleRecursiveGenerator
   1.3: Poprawienie stylu kodu(Google code style).
        Zablokowano konstruktory kopiujące.
        Dopisano randomShuffle.
        Dopisano randInt i zmieniono nazwy metod Random na bardziej intiucyjne.
*/

#ifndef OI_LIB_OI_H_
#define OI_LIB_OI_H_
#include <assert.h>
en
#include <algorithm>
#include <assert.h>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>

using std::vector;
using std::max;
using std::swap;

// We want prevent usage of standard random function.
int rand(){
  fprintf(stderr, "DONT USE rand or random_shuffle!\nUse oi::Random class.\n");
  exit(1);
  return 0;
}

namespace oi {

enum Lang {
  EN = 0,
  PL = 1
};

class Reader;

class Scanner {
 protected:
  static const int realNumbersLimit = 20;

  Lang lang;
  Reader* reader;
  void(*end)(const char* msg, int line, int position);

  void readULL(unsigned long long int limit, unsigned long long int &val, bool &sign);
  void readLDB(long double limit, long double &val, bool &sign);

 public:
  Scanner(const char* file, Lang _lang = Lang(EN));
  Scanner(const char* file, void(*endf)(const char* msg, int line, int position), Lang _lang = Lang(EN));
  Scanner(FILE* input, Lang _lang = Lang(EN));
  Scanner(FILE* input, void(*endf)(const char* msg, int line, int position), Lang _lang = Lang(EN));
  ~Scanner();

  void                error(const char* msg);

  // Skips all whitespaces until any occurrence of EOF or other non-white character.
  int                 skipWhitespaces();
  // Skips all whitespaces until any occurrence of EOF, EOLN or other non-white character.
  int                 skipWhitespacesUntilEOLN();

  int                 readInt(int min_value = INT_MIN, int max_value = INT_MAX);
  unsigned int        readUInt(unsigned int min_value = 0, unsigned int max_value = UINT_MAX);
  long long           readLL(long long int min_value = LLONG_MIN, long long int max_value = LLONG_MAX);
  unsigned long long  readULL(unsigned long long int min_value = 0, unsigned long long int max_value = ULLONG_MAX);

  float               readFloat(float min_value, float max_value);
  double              readDouble(double min_value, double max_value);
  long double         readLDouble(long double min_value, long double max_value);

  char                readChar();

  // Newline character is read, but isn't added to s
  int                 readLine(char* s, int size);

  // Reads a string until occurrence of EOF, EOLN or whitespace.
  // Returns the number of characters read (possibly 0).
  int                 readString(char* s, int size);

  void                readEof();
  void                readEofOrEoln();
  void                readEoln();
  void                readSpace();
  void                readTab();

  bool                isEOF();
 private:
  Scanner(Scanner &s) {}
};

class MultipleRecursiveGenerator;

class Random {
 public:
  Random();
  explicit Random(unsigned int seed);
  ~Random();
  void setSeed(unsigned int seed);

  // Random number from range <0..2^31 - 1>
  int rand();

  // randS* - signed *
  // randU* - unsigned *
  int randSInt();
  unsigned int randUInt();
  long long randSLL();
  unsigned long long randULL();

  template<typename RandomAccessIterator>
  void randomShuffle(RandomAccessIterator first, RandomAccessIterator last);

 private:
  Random(Random &r) {}
  MultipleRecursiveGenerator* mrg_;
  void init();
};

class MultipleRecursiveGenerator {
 public:
  MultipleRecursiveGenerator(unsigned int modulo,
                             const vector<unsigned int> &A);
  void setSeed(unsigned int seed);
  unsigned int next16Bits();

 private:
  int n_;
  unsigned int modulo_;
  vector<unsigned int> A_;
  vector<unsigned int> X_;
};

class Reader {
 private:
  static const int bufferSize = 1000;
  char Buffer[bufferSize];
  int head, tail;
  int line, position;
  void fillBuffer();
  FILE* input;
 public:
  explicit Reader(const char* file);
  explicit Reader(FILE* _input);
  ~Reader();
  bool isEOF();
  int getLine() {return line;}
  int getPosition() {return position;}
  char read(bool move = false);
 private:
  Reader(Reader &r) {};
};


const char* msgLeadingZeros[]= {
  "Leading zeros",
  "Zera wiodace"};
const char* msgMinusZero[]= {
  "Minus zero -0",
  "Minus zero -0"};
const char* msgNoNumber[]= {
  "No number",
  "Brak liczby"};
const char* msgNoChar[]= {
  "No char - EOF",
  "Brak znaku - EOF"};
const char* msgNotEof[]= {
  "Not EOF",
  "Brak konca pliku"};
const char* msgNotEoln[]= {
  "Not EOLN",
  "Brak konca linii"};
const char* msgNotEofOrEoln[]= {
  "Not EOF or EOLN",
  "Brak konca linii i brak konca pliku"};
const char* msgNotSpace[]= {
  "Not space",
  "Brak spacji"};
const char* msgNotTab[]= {
  "Not tab",
  "Brak znaku tabulacji"};
const char* msgOutOfRangeInt[]= {
  "Integer out of range",
  "Liczba calkowita spoza zakresu"};
const char* msgOutOfRangeReal[]= {
  "Real number out of range",
  "Liczba rzeczywista spoza zakresu"};
const char* msgRealNumberLimit[]= {
  "Too many digits after dot",
  "Za duzo cyfr po kropce dziesietnej"};
const char* msgBadRealNumberFormat[]= {
  "Bad real number format",
  "Niepoprawny format liczby rzeczywistej"};

// ------------------------------- Implementation -----------------------------

typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef long double ldb;


inline bool isDot(char x) {
  return x == '.';
}

inline bool isEOLN(char x) {
  return x == '\n';
}

inline bool isMinus(char x) {
  return x == '-';
}

inline bool isSpace(char x) {
  return x == ' ';
}

inline bool isTab(char x) {
  return x == '\t';
}

inline bool isWhitespace(char x) {
  return x == ' ' || x == '\t' || x == '\n';
}

void endDefault(const char* msg, int line, int position) {assert(0);
  printf("ERROR(line: %d, position: %d): %s\n", line, position, msg);
  exit(1);
}

// ------------------------------- Random -------------------------------------

void Random::init() {
// Here is a reference about it:
// http://random.mat.sbg.ac.at/results/karl/server/node7.html
  vector<unsigned int> A(5, 0);
  A[0] = 107374182, A[4] = 104480;
  unsigned int modulo = 2147483647;  // 2^31 -1
  mrg_ = new MultipleRecursiveGenerator(modulo, A);
}

Random::Random() {
  init();
}

Random::Random(unsigned int seed) {
  init();
  setSeed(seed);
}

Random::~Random() {
  delete mrg_;
}

void Random::setSeed(unsigned int seed) {
  mrg_->setSeed(seed);
}

#define RAND_TYPE(type, iter)\
    type res = 0;\
    for (int i = 0; i < iter; ++i) {\
      res += ((type)mrg_->next16Bits()) << (i * 16);\
    }\
    return res;


int Random::rand() {
  int x = randSInt();
  if (x<0) return ~x;
  return x;
}

int Random::randSInt() {
  RAND_TYPE(int, 2);
}

unsigned int Random::randUInt() {
  RAND_TYPE(unsigned int, 2);
}

long long Random::randSLL() {
  RAND_TYPE(long long, 4);
}

unsigned long long Random::randULL() {
  RAND_TYPE(unsigned long long, 4);
}

template<typename RandomAccessIterator>
void Random::randomShuffle(RandomAccessIterator first, RandomAccessIterator last) {
  int n = last - first;
  for (int i = 1; i < n; ++i) {
    int to = rand() % (i+1);
    swap(first[to], first[i]);
  }
}

// ----------------------- MultipleRecursiveGenerator -------------------------

MultipleRecursiveGenerator::MultipleRecursiveGenerator(
    unsigned int modulo,
    const vector<unsigned int> &A) : modulo_(modulo), A_(A) {
  n_ = A_.size();
  X_ = vector<unsigned int>(n_, 0);
  setSeed(0);
}

void MultipleRecursiveGenerator::setSeed(unsigned int seed) {
  for (int i = 0; i < n_; ++i) {
    seed = (seed + 1) % modulo_;
    X_[i] = seed;
  }
  for (int i = 0; i < n_; ++i) next16Bits();
}

unsigned int MultipleRecursiveGenerator::next16Bits() {
  unsigned int res = 0;
  for (int i = 0; i < n_; ++i) {
    res = (res + (long long)A_[i] * X_[i]) % modulo_;
    if (i < n_ - 1) X_[i] = X_[i+1];
  }
  X_[n_ - 1] = res;
  return res;
}

// --------------------------- Reader's methods -------------------------------

Reader::Reader(const char* file) {
  assert((input = fopen(file, "r")) != NULL);
  head = tail= 0;
  line = position = 1;
}

Reader::Reader(FILE* _input) {
  input = _input;
  head = tail = 0;
  line = position = 1;
}

Reader::~Reader() {
  assert(fclose(input) == 0);
}

void Reader::fillBuffer() {
  while ((tail + 1) % bufferSize != head) {
    int v = getc(input);
    if (v == EOF) break;
    Buffer[tail] = v;
    tail = (tail + 1) % bufferSize;
  }
}

bool Reader::isEOF() {
  fillBuffer();
  return head == tail;
}

char Reader::read(bool move) {
  fillBuffer();
  assert((head != tail) || (!move));
  if (head == tail) return 0;
  char v = Buffer[head];
  if (move) {
    if (isEOLN(v)) {
      line++;
      position = 1;
    } else {
      position++;
    }
    head = (head + 1) % bufferSize;
  }
  return v;
}

// ---------------------------- Scanner's methods -----------------------------

Scanner::Scanner(const char* file, Lang _lang): lang(_lang) {
  reader = new Reader(file);
  end = endDefault;
}

Scanner::Scanner(const char* file, void(*endf)(const char* msg, int line, int position), Lang _lang): lang(_lang) {
  reader = new Reader(file);
  end = endf;
}

Scanner::Scanner(FILE* input, Lang _lang): lang(_lang) {
  reader = new Reader(input);
  end = endDefault;
}

Scanner::Scanner(FILE* input, void(*endf)(const char* msg, int line, int position), Lang _lang): lang(_lang) {
  reader = new Reader(input);
  end = endf;
}

Scanner::~Scanner() {
  delete reader;
}

void Scanner::error(const char* msg) {assert(0);
  int l = reader->getLine();
  int p = reader->getPosition();
  delete reader;
  (*end)(msg, l, p);
}

int Scanner::skipWhitespaces() {
  int result = 0;
  while (isWhitespace(reader->read())) {
    reader->read(1);
    result++;
  }
  return result;
}


int Scanner::skipWhitespacesUntilEOLN() {
  int result = 0;
  while (isWhitespace(reader->read()) && !isEOLN(reader->read())) {
    reader->read(1);
    result++;
  }
  return result;
}


// INTEGERS

int Scanner::readInt(int min_value, int max_value) {
  return (int)readLL(min_value, max_value);
}

uint Scanner::readUInt(uint min_value, uint max_value) {
  return (uint)readULL(min_value, max_value);
}

inline bool lower_equal(ull a, bool sign_a, ull b, bool sign_b) {
  if (sign_a != sign_b) return sign_a;
  if (sign_a) return a >= b;
  return a <= b;
}
inline ull spec_abs(ll x) {
  if (x < 0) return (-(x + 1)) + 1;
  return x;
}

ll Scanner::readLL(ll min_value, ll max_value) {
  assert(min_value <= max_value);
  bool sign;
  ull val;
  readULL(max(spec_abs(min_value), spec_abs(max_value)), val, sign);
  ll v = val;
  if (!(lower_equal(spec_abs(min_value), min_value < 0, v, sign) &&
        lower_equal(v, sign, spec_abs(max_value), max_value < 0)))
    error(msgOutOfRangeInt[lang]);
  if (sign) v *= -1;
  return v;
}

ull Scanner::readULL(ull min_value, ull max_value) {
  assert(min_value <= max_value);
  bool sign;
  ull val;
  readULL(max_value, val, sign);
  if (sign) error(msgOutOfRangeInt[lang]);
  if (!(min_value <= val))
    error(msgOutOfRangeInt[lang]);
  return val;
}

// REAL NUMBERS

float Scanner::readFloat(float min_value, float max_value) {
  return (float)readLDouble(min_value, max_value);
}

double Scanner::readDouble(double min_value, double max_value) {
  return (double)readLDouble(min_value, max_value);
}

long double Scanner::readLDouble(long double min_value, long double max_value) {
  assert(min_value <= max_value);
  bool sign;
  ldb val;
  readLDB(max(fabsl(min_value), fabsl(max_value)), val, sign);
  if (sign) val *= -1;
  if (!(min_value <= val && val <= max_value))
    error(msgOutOfRangeReal[lang]);
  return val;
}

// STRINGS

int Scanner::readString(char* s, int size) {
  int x = 0;
  while ( x < size - 1 && !isEOF() && !isWhitespace(reader->read()))
    s[x++] = reader->read(1);
  s[x]=0;
  return x;
}

int Scanner::readLine(char* s, int size) {
  int x = 0;
  while ( x < size - 1 && !isEOLN(reader->read()) && !isEOF())
    s[x++] = reader->read(1);
  s[x] = 0;
  if (isEOLN(reader->read())) reader->read(1);
  return x;
}

char Scanner::readChar() {
  if (reader->isEOF()) error(msgNoChar[lang]);
  return reader->read(1);
}

// WHITESPACES

void Scanner::readEof() {
  if (!reader->isEOF()) error(msgNotEof[lang]);
}

void Scanner::readEoln() {
  if (!isEOLN(reader->read())) error(msgNotEoln[lang]);
  reader->read(1);
}

void Scanner::readEofOrEoln() {
  if (isEOLN(reader->read())) {
    reader->read(1);
  } else if (!reader->isEOF()) {
    error(msgNotEofOrEoln[lang]);
  }
}


void Scanner::readSpace() {
  if (!isSpace(reader->read())) error(msgNotSpace[lang]);
  reader->read(1);
}

void Scanner::readTab() {
  if (!isTab(reader->read())) error(msgNotTab[lang]);
  reader->read(1);
}

bool Scanner::isEOF() {
  return reader->isEOF();
}


// PROTECTED

void Scanner::readULL(ull limit, ull &val, bool &sign) {
  sign = 0;
  val = 0;
  sign = isMinus(reader->read());
  if (sign) reader->read(1);
  int zeros = 0;
  int valDigits = 0;
  while ('0' == reader->read()) {
    zeros++;
    valDigits++;
    reader->read(1);
    if (zeros > 1) error(msgLeadingZeros[lang]);
  }
  int limDigits = 0;
  ull tmp = limit;
  while (tmp) {
    limDigits++;
    tmp /= 10;
  }
  if (!limDigits) limDigits = 1;
  while (isdigit(reader->read())) {
    valDigits++;
    if (valDigits > limDigits) error(msgOutOfRangeInt[lang]);
    char x = reader->read(1);
    if (valDigits == limDigits) {
      if (limit / 10 < val) error(msgOutOfRangeInt[lang]);
      if (limit / 10 == val && limit % 10 < (ull)(x - '0')) error(msgOutOfRangeInt[lang]);
    }
    val = val * 10 + x - '0';
  }
  if (val > 0 && zeros) error(msgLeadingZeros[lang]);
  if (sign && zeros) error(msgMinusZero[lang]);
  if (!valDigits) error(msgNoNumber[lang]);
}

void Scanner::readLDB(ldb limit, ldb &val, bool &sign) {
  sign = 0;
  val = 0;
  sign = isMinus(reader->read());
  if (sign) reader->read(1);
  int zeros = 0;
  int valDigits = 0;
  while ('0' == reader->read()) {
    zeros++;
    valDigits++;
    reader->read(1);
    if (zeros > 1) error(msgLeadingZeros[lang]);
  }
  if (zeros && isdigit(reader->read())) error(msgLeadingZeros[lang]);
  while (isdigit(reader->read())) {
    valDigits++;
    char x = reader->read(1);
    val = val * 10.0 + x - '0';
  }
  if (!valDigits) error(msgNoNumber[lang]);
  if (isDot(reader->read())) {
    reader->read(1);
    ldb dec = 1;
    int dotDigits = 0;
    while (isdigit(reader->read())) {
      dotDigits++;
      if (dotDigits > realNumbersLimit) error(msgRealNumberLimit[lang]);
      char x = reader->read(1);
      dec /= 10.0;
      val += dec * (x - '0');
    }
    if (!dotDigits) error(msgBadRealNumberFormat[lang]);
  }
}

}  // namespace oi

#endif  // OI_LIB_OI_H_


/*************************************************************************
 *                                                                       *
 *                    XX Olimpiada Informatyczna                         *
 *                                                                       *
 *   Zadanie:              Multidrink                                    *
 *   Autor:                Przemyslaw Horban                             *
 *   Opis:                 Weryfikator odpowiedzi programu zawodnika     *
 *                                                                       *
 *************************************************************************/

#include<iostream>
#include<set>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<stack>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<cstring>
#include<cctype>

using namespace std;
#define fe(e,C) for(__typeof((C).begin()) e = (C).begin(); e != (C).end(); e++)
#define fi(i,n) for(int (i) = 0, __end = (n); (i) < __end; i++)
#define iterate_until(i,s,n) for(int (i) = (s), __end = (n); (i) < __end; i++)
#define iterate_to(i,a,b) ft(i,a,b)
#define ft(i,a,b) for(int (i) = (a), __end = (b); (i) <= __end; (i)++)
#define fd(i,a,b) for(int (i) = (a), __end = (b); (i) >= __end; (i)--)
#define fs(i,C) fi(i,SZ(C))
#define ALL(V) (V).begin(), (V).end()
#define SET(T, c) memset(T, c, sizeof(T))
#define VI vector<int>
#define PB push_back
#define PII pair<int, int>
#define SEC second
#define FST first
#define MP make_pair
#define SZ(C) ((int)(C).size())
#define SQR(a) ((a)*(a))
#define VII vector<PII>
#define SS stringstream
#define UNIQUE(V) (V).erase(unique(ALL(V)), (V).end())


// Przemyslaw Horban (extremegf@gmail.com)
//
// This code is shared among solutions and verifiers

#define fe(e,C) for(__typeof((C).begin()) e = (C).begin(); e != (C).end(); e++)
#define foreach(VAR_DEF, C) \
  fe(__varname, C) \
    for(bool run_once = true; run_once; ) \
      for(VAR_DEF = *(__varname); run_once; run_once = false)

#ifndef DEBUG
#define DEBUG 0
#endif

class Graph {
protected:
    int minNode, _edgeCount;
    vector<vector<int> > E;

public:

    Graph(int smallestNode, int largestNode) {
        minNode = smallestNode;
        int size = largestNode - (smallestNode - 1);
        E.clear();
        E.resize(size);
        _edgeCount = 0;
    }

    void addEdge(int u, int v) {
        _edgeCount += 1;

        u -= minNode;
        v -= minNode;

        E[u].push_back(v);
        E[v].push_back(u);
    }

    size_t neighbourCount(int u) const {
        return E[u - minNode].size();
    }

    vector<int> neighbours(int u) const {
        vector<int> neighs(E[u - minNode]);
        iterate_until(i, 0, neighs.size())
        neighs[i] += minNode;
        return neighs;
    }

    bool hasUnusedNeighbour(int u, const vector<bool> used) const {
        assert(nodeCount() + minNode - 1 < used.size());
        u -= minNode;
        foreach(int v, E[u]) {
            v += minNode;
            if(!used[v])
                return true;
        }
        return false;
    }

    size_t nodeCount() const {
        return E.size();
    }

    size_t edgeCount() const {
        return _edgeCount;
    }

    bool isConnected() const {
        vector<bool> onFringe(nodeCount(), false);
        vector<int> fringeNodes;

        fringeNodes.push_back(0);
        onFringe[0] = true;

        while(!fringeNodes.empty()) {
            int u = fringeNodes.back();
            fringeNodes.pop_back();

            fe(nextIt, E[u]) {
                int v = *nextIt;
                if(!onFringe[v]) {
                    fringeNodes.push_back(v);
                    onFringe[v] = true;
                }
            }
        }

        return count(ALL(onFringe), false) == 0;
    }
};


class TwoStepNeighIterator;

class Tree: public Graph {
    friend class TwoStepNeighIterator;
public:
    Tree(FILE *input, int numerationStart): Graph(numerationStart,
                read_int(input)) {
        while(edgeCount() < nodeCount() - 1)
            addEdge(read_int(input), read_int(input));

        buildFatherSonRelation();
    }

    // Haha! It takes O(1) time.
    bool areDistantByAtMost2(int u, int v, int *middleMan=NULL) const {
        u -= minNode;
        v -= minNode;

        if(middleMan) *middleMan = -1;

        // By definition they may be distant by 0
        if(u == v)
            return true;

        // Directly connected
        if(father[u] == v || father[v] == u)
            return true;

        // Distant by two edges
        //     v
        //    /
        //   m
        //  /
        // u
        if(father[father[u]] == v) {
            if(middleMan) *middleMan = father[u] + minNode;
            return true;
        }

        //     u
        //    /
        //   m
        //  /
        // v
        if(father[father[v]] == u) {
            if(middleMan) *middleMan = father[v] + minNode;
            return true;
        }

        //    m
        //  / |
        // u  v
        if(father[u] == father[v]) {
            if(middleMan) *middleMan = father[u] + minNode;
            return true;
        }


        return false;
    }

    bool fatherAndSon(int fatherNd, int childNd) const {
        childNd -= minNode;
        fatherNd -= minNode;
        return father[childNd] == fatherNd;
    }

    bool areNeighbours(int u, int v) const {
        u -= minNode;
        v -= minNode;
        // Directly connected
        return father[u] == v || father[v] == u;
    }

private:
    vector<int> father;

    void buildFatherSonRelation() {
        father.clear();
        father.resize(nodeCount());

        vector<bool> onFringe(nodeCount(), false);
        vector<int> fringeNodes;

        fringeNodes.push_back(0);
        onFringe[0] = true;
        father[0] = 0;

        while(!fringeNodes.empty()) {
            int u = fringeNodes.back();
            fringeNodes.pop_back();

            fe(nextIt, E[u]) {
                int v = *nextIt;
                // This is a Tree - if it's on fringe,
                // than it must be the father
                if(!onFringe[v]) {
                    // u adopts v
                    father[v] = u;
                    fringeNodes.push_back(v);
                    onFringe[v] = true;
                }
            }
        }
    }

    static int read_int(FILE *input) {
        int t;
        int result = fscanf(input, "%d", &t);
        assert(result == 1);
        return t;
    }
};

class TwoStepNeighIterator {
    const Tree *gPtr;
    int u;
    vector<int>::const_iterator nodesToGoIt, nodesToGoEnd;
    vector<int>::const_iterator neighbourIt, neighboursEnd;

public:
    TwoStepNeighIterator(const Tree *gPtr, int u): gPtr(gPtr), u(u) {
        const Tree &g = *gPtr;

        int root = u - g.minNode;;

        neighbourIt = g.E[root].begin();
        neighboursEnd = g.E[root].end();

        nodesToGoIt = g.E[root].begin();
        nodesToGoEnd = g.E[root].end();
    }

    int next() {
        if(neighbourIt != neighboursEnd) {
            int v = *neighbourIt + gPtr->minNode;
            neighbourIt++;
            if(v == u)
                return next();
            else
                return v;
        }
        else if(nodesToGoIt != nodesToGoEnd) {
            neighbourIt = gPtr->E[*nodesToGoIt].begin();
            neighboursEnd = gPtr->E[*nodesToGoIt].end();
            nodesToGoIt++;
            return next();
        }
        else
            return -1;

    }
};

// Iterative brutal path search
//
// CutoffMem is the datatype that cutOff function
// can use to memorize which cases have already been
// explored and make a cutoff decision based on that.
template<typename CutoffMem = char>
class PathSearch {
    const Tree &g;
    vector<int> p;
    vector<bool> used;
    vector<TwoStepNeighIterator> iters;
    vector<CutoffMem> cutoffMem;


public:
    PathSearch(const Tree &g): g(g) {}

    // Returns a vector with solution or empty vector if not found.
    vector<int> findTwoStepPath() {
        vector<int> solution;
        p.clear();
        p.push_back(1);
        used.clear();
        used.resize(g.nodeCount()+1, false);
        used[1] = true;

        if(DEBUG) {
            iterate_to(u, 1, g.nodeCount()) {
                TwoStepNeighIterator it(&g, u);
                printf("Sasiedzi %d: ", u);
                while(true) {
                    int v = it.next();
                    if(v == -1) break;
                    printf("%d ", v);
                }
                printf("\n");
            }
        }

        search_step();

        if(p.size() == g.nodeCount())
            solution.swap(p);

        return solution;
    }

    virtual ~PathSearch() {}
protected:
    virtual bool cutOff(const Tree &g,
                        int preLast, int last,
                        const vector<bool> &used,
                        CutoffMem *cutoffMemPtr) = 0;

private:
    void search_step() {
fake_recurse:
        if(p.size() == g.nodeCount() && p.back() == (int)g.nodeCount()) {
            // Solution found. Real return.
            return;
        }

        iters.push_back(TwoStepNeighIterator(&g, p.back()));
        p.push_back(-1);
        cutoffMem.push_back(CutoffMem());
        while(true) {
            p.back() = iters.back().next();
            if(p.back() == -1)
                break;
            if(DEBUG) {
                foreach(int u, p)
                printf("%d ", u);
                printf("\n");
            }
            if(!used[p.back()]) {
                used[p.back()] = true;
                // Jestem w p[-1], ostatni byl p[-2], uzyte sa used, a
                // a drzewo jest g.

                if(!cutOff(g, *(p.end()-2), *(p.end()-1), used, &*(cutoffMem.end()-1)))
                    goto fake_recurse; // search_step() - simulated recursive call
fake_return:
                // end of search_step() fake call
                used[p.back()] = false;
            }
        }
        p.pop_back();
        iters.pop_back();
        cutoffMem.pop_back();

        if(iters.empty()) // Real return - no solution found.
            return;
        else // return to callpoint in the while
            goto fake_return;
    }
};

string NO_SOLUTION_STR = "BRAK";

// Skips whitespace, seeking first continous string in file.
string readFirstString(const char *fileName) {
    oi::Scanner in(fileName, oi::PL);
    in.skipWhitespaces();
    char firstString[10];
    firstString[0] = 0;
    in.readString(firstString, 10);

    return firstString;
}

void chk_error_function(const char* msg, int line, int position) {assert(0);
    printf("WRONG\n");
    printf("ERROR(line: %d, position: %d): %s\n", line, position, msg);
    exit(1);
}

vector<int> readPermutation(oi::Scanner *inPtr, size_t size) {
    oi::Scanner &in = *inPtr;
    vector<int> p;
    p.resize(size);

    iterate_until(i, 0, size) {
        in.skipWhitespaces();
        p[i] = in.readInt(1, size);
    }
    in.skipWhitespaces();
    in.readEof();

    // Checkinf if all values from [1, size] are in p
    vector<int> v(p);
    sort(ALL(v));
    UNIQUE(v);
    if(v.size() != size)
        in.error("Not a permutation.");

    return p;
}

bool isTwoSkipHamiltonPath1ToN(Tree *treePtr,
                               const vector<int> &permutation) {
    Tree &g = *treePtr;
    if(permutation.front() != 1 || permutation.back() != (int)g.nodeCount())
        return false;

    assert(permutation.size() == g.nodeCount());
    iterate_until(i, 0, permutation.size() - 1)
    if(!g.areDistantByAtMost2(permutation[i],
                              permutation[i+1]))
        return false;

    return true;
}

int main(int argc, char *argv[]) {
    const char *inputFile = argv[1];
    const char *userOutputFile = argv[3];
    const char *expOutputFile = argv[2];

    FILE *inputFileObj = fopen(inputFile, "r");
    assert(inputFileObj != NULL);
    Tree tree(inputFileObj, 1);
    fclose(inputFileObj);

    oi::Scanner userOutScn(userOutputFile, chk_error_function, oi::PL);
    if(readFirstString(expOutputFile) == NO_SOLUTION_STR) {
        char word[6];
        userOutScn.skipWhitespaces();
        userOutScn.readString(word, 5);

        if(word != NO_SOLUTION_STR) {
            // Just to be safe, we'll check if this answer is actually a
            // correct path.
            oi::Scanner secUserOutScn(userOutputFile, chk_error_function, oi::PL);

            // To znaczy ze wzorcowka jest zmaszczona, bo daje BRAK
            // ale zawodnik znalazl poprawna sciezke.
            bool weAreScrewed =
                isTwoSkipHamiltonPath1ToN(&tree, readPermutation(&secUserOutScn,
                                          tree.nodeCount()));
            if(weAreScrewed) {
                assert(0);
                //userOutScn.error("Uwaga! Rozwiazanie wzorcowe jest niepoprawne."
                       //          "Koniecznie zglos to organizatorom.");
            } else {
                assert(0);
                userOutScn.error("Contestant returned a solution, though non-exits");
            }
        } else {
            // He's almost there. Just ensure there is no garbage after NO_SOLUTION_STR
            userOutScn.skipWhitespaces();
            userOutScn.readEof();
        }
    } else {
        if(!isTwoSkipHamiltonPath1ToN(&tree, readPermutation(&userOutScn,
                                      tree.nodeCount()))) {
           assert(0);
           // userOutScn.error("Found path is not correct.");
        }
    }

    return 0;
}

