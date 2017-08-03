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

void Scanner::error(const char* msg) {
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
 *   Zadanie:              Labirynt                                      *
 *   Autor:                Adam Karczmarz, Tomasz Idziaszek              *
 *   Opis:                 Weryfikator odpowiedzi programu zawodnika     *
 *                                                                       *
 *************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

#define REP(AA,BB) for(int AA=0; AA<(BB); ++AA)
#define FOR(AA,BB,CC) for(int AA=(BB); AA<(CC); ++AA)
#define FC(AA,BB) for(__typeof((AA).begin()) BB=(AA).begin(); BB!=(AA).end(); ++BB)
#define SZ(AA) ((int)((AA).size()))
#define ALL(AA) (AA).begin(), (AA).end()
#define PB push_back
#define MP make_pair

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef long double LD;

struct point {
    int x, y, n;
    point(int _x=0, int _y=0, int _n=0) : x(_x), y(_y), n(_n) {}
    int operator<(const point &a) const {
        if(x==a.x)
            return y<a.y;
        return x<a.x;
    }
    int operator==(const point &a) const {
        return x==a.x && y==a.y;
    }
    point operator-(const point &a) const {
        return point(x-a.x, y-a.y);
    }
};

int cmp2(const point &a, const point &b) {
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

LL cross(const point &a, const point &b) {
    return (LL)a.x*b.y-(LL)a.y*b.x;
}

LL cross(const point &o, const point &a, const point &b) {
    return cross(a-o, b-o);
}

vector<point> P;

LL pole() {
    LL sum=0LL;
    FOR(i,2,SZ(P))
    sum+=cross(P[0],P[i-1],P[i]);
    return sum<0?-sum:sum;
}

int rozne() {
    vector<point> Q=P;
    sort(ALL(Q));
    FOR(i,1,SZ(Q)) {
        if(Q[i]==Q[i-1])
            return 0;
    }
    return 1;
}

int prostopadle() {
    int t, tmp;
    if(P[0].x==P[1].x && P[0].y!=P[1].y)
        t=0;
    else if(P[0].y==P[1].y && P[0].x!=P[1].x)
        t=1;
    else
        return 0;
    FOR(i,2,SZ(P)) {
        if(P[i-1].x==P[i].x && P[i-1].y!=P[i].y)
            tmp=0;
        else if(P[i-1].y==P[i].y && P[i-1].x!=P[i].x)
            tmp=1;
        else
            return 0;
        if(tmp==t)
            return 0;
        t=1-t;
    }
    if(P.back().x==P[0].x && P.back().y!=P[0].y)
        tmp=0;
    else if(P.back().y==P[0].y && P.back().x!=P[0].x)
        tmp=1;
    else
        return 0;
    return tmp!=t;
}

int nie_nakladaja() {
    vector<point> Q;
    for(int i=(P[0].x==P[1].x)?0:1; i<SZ(P); i+=2) {
        int j=(i+1)%SZ(P);
        Q.PB(point(P[i].x,P[i].y,i));
        Q.PB(point(P[j].x, P[j].y, i));
    }
    sort(ALL(Q));
    for(int i=0, j; i<SZ(Q); ) {
        for(j=i; j<SZ(Q) && Q[i].x==Q[j].x; ++j);
        for(int k=i; k<j; k+=2) {
            if(Q[k].n!=Q[k+1].n)
                return 0;
        }
        i=j;
    }
    Q.clear();
    for(int i=(P[0].y==P[1].y)?0:1; i<SZ(P); i+=2) {
        int j=(i+1)%SZ(P);
        Q.PB(point(P[i].x,P[i].y,i));
        Q.PB(point(P[j].x, P[j].y, i));
    }
    sort(ALL(Q),cmp2);
    for(int i=0, j; i<SZ(Q); ) {
        for(j=i; j<SZ(Q) && Q[i].y==Q[j].y; ++j);
        for(int k=i; k<j; k+=2) {
            if(Q[k].n!=Q[k+1].n)
                return 0;
        }
        i=j;
    }
    return 1;
}

struct ev {
    int x, y1, y2, c;
    ev(int _x=0, int _y1=0, int _y2=0, int _c=0) : x(_x), y1(_y1), y2(_y2), c(_c) {}
    int operator<(const ev &a) const {
        if(x==a.x)
            return c>a.c;
        return x<a.x;
    }
};

const int MAX_DRZ = 1<<19;
int cnt[MAX_DRZ], BASE;

int get(int a, int b) {
    int res=0;
    a+=BASE;
    b+=BASE;
    res+=cnt[a];
    if(b>a)
        res+=cnt[b];
    while((a>>1)!=(b>>1)) {
        if(b&1)
            res+=cnt[b-1];
        if(!(a&1))
            res+=cnt[a+1];
        a>>=1;
        b>>=1;
    }
    return res;
}

void add(int a, int v) {
    a+=BASE;
    while(a>0) {
        cnt[a]+=v;
        a>>=1;
    }
}

int brak_przeciec() {
    memset(cnt, 0, sizeof cnt);
    vector<ev> E;
    vector<int> wsp;
    wsp.PB(0);
    for(int i=0; i<SZ(P); ++i) {
        int j=(i+1)%SZ(P);
        if(P[i].x==P[j].x) {
            int y1=min(P[i].y,P[j].y)+1, y2=max(P[i].y,P[j].y)-1;
            if(y1<=y2) {
                wsp.PB(y1);
                E.PB(ev(P[i].x, y1, y2, 0));
            }
            if(y1<y2)
                wsp.PB(y2);
        }
        else {
            wsp.PB(P[i].y);
            E.PB(ev(min(P[i].x,P[j].x), P[i].y, 0, 1));
            E.PB(ev(max(P[i].x,P[j].x), P[i].y, 0, -1));
        }
    }
    sort(ALL(wsp));
    for(BASE=1; BASE<SZ(wsp); BASE<<=1);
    assert(2*BASE<=MAX_DRZ);
    REP(i,SZ(E)) {
        E[i].y1=lower_bound(ALL(wsp), E[i].y1)-wsp.begin();
        E[i].y2=lower_bound(ALL(wsp), E[i].y2)-wsp.begin();
    }
    sort(ALL(E));
    REP(i,SZ(E)) {
        if(E[i].c==0) {
            int tmp=get(E[i].y1,E[i].y2);
            assert(tmp>=0);
            if(tmp>0) {
                //fprintf(stderr, "%d\n", tmp);
                return 0;
            }
        }
        else
            add(E[i].y1, E[i].c);
    }
    return 1;
}

const int MAX_WSP = 1000000000;

void error(const char* msg, int line=0, int position=0) {
    assert(0);
    printf("WRONG\n%s\n",msg);
    exit(0);
}

void dobrze() {
    exit(0);
}

char buf[110];




const int MAX_LEN = 100000+10;

char s_in[MAX_LEN];
char s_user[MAX_LEN];
char _text[MAX_LEN*3];
int _p[MAX_LEN*3];

bool cyklicznie_rownowazne(int n, char* sa, char* sb) {
    REP(i,n) _text[i] = s_in[i];
    _text[n] = '$';
    REP(i,n) _text[n+1+i] = s_user[i];
    REP(i,n) _text[2*n+1+i] = s_user[i];

    _p[0] = -1;
    int t = -1;
    REP(j,3*n+1) {
        while (t >= 0 && _text[t] != _text[j])
            t = _p[t];
        t++;
        _p[j+1] = t;
        if (t >= n) return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
////   int n; assert(fscanf(fopen(argv[1], "r"), "%d", &n)==1);

    fscanf(fopen(argv[1], "r"), "%s", s_in);
    int n=strlen(s_in),cnt=0;
    REP(i,n) if (s_in[i]=='L') ++cnt;
    else --cnt;

    oi::Scanner s(argv[3], error, oi::PL);
////   if(n==2 || n%2==1) {
    if (cnt != 4) {
        s.skipWhitespaces();
        s.readString(buf, 7);
        if(strcmp(buf,"NIE")!=0)
            error("Oczekiwano NIE.");
        s.skipWhitespaces();
        s.readEof();
        dobrze();
        return 0;
    }
    REP(i,n) {
        point tmp;
        s.skipWhitespaces();
        tmp.x=s.readInt(-MAX_WSP, MAX_WSP);
        s.skipWhitespaces();
        tmp.y=s.readInt(-MAX_WSP, MAX_WSP);
        P.PB(tmp);
    }
    s.skipWhitespaces();
    s.readEof();
    if(!rozne())
        error("Punkty nie sa rozne.");
    if(!prostopadle())
        error("Kolejne boki nie sa prostopadle.");
////   if(pole()!=2*n) {
////      //fprintf(stderr, "%d\n", pole());
////      error("Pole nie jest rowne n.");
////   }
    if(!nie_nakladaja())
        error("Boki nakladaja sie na siebie.");
    if(!brak_przeciec())
        error("Znaleziono samoprzeciecia.");


    REP(i,n) {
        point a = P[i], b = P[(i+1)%n], c = P[(i+2)%n];
        if (a.y == b.y && a.x < b.x) s_user[i] = (b.y < c.y) ? 'L' : 'P';
        if (a.x == b.x && a.y > b.y) s_user[i] = (b.x < c.x) ? 'L' : 'P';
        if (a.y == b.y && a.x > b.x) s_user[i] = (b.y > c.y) ? 'L' : 'P';
        if (a.x == b.x && a.y < b.y) s_user[i] = (b.x > c.x) ? 'L' : 'P';
    }

    if (!cyklicznie_rownowazne(n, s_in, s_user))
        error("Niepoprawny ciag zakretow.");


    dobrze();
    return 0;
}
