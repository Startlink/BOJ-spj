#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <tuple>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char buffer[1000000];
string read_string(FILE *fp) {
    assert(fscanf(fp,"%10000s",buffer)==1);
    return string(buffer);
}
int read_int(FILE *fp) {
    string str = read_string(fp);
    int temp;
    istringstream sin(str);
    assert(sin >> temp);
    return temp;
}
string read_line(FILE *fp) {
    assert(fscanf(fp,"%10000[^\n]\n",buffer)==1);
    return string(buffer);
}
long long read_long(FILE *fp) {
    string str = read_string(fp);
    long long temp;
    istringstream sin(str);
    assert(sin >> temp);
    return temp;
}
float read_float(FILE *fp) {
    string str = read_string(fp);
    float temp;
    istringstream sin(str);
    assert(sin >> temp);
    return temp;
}
double read_double(FILE *fp) {
    string str = read_string(fp);
    double temp;
    istringstream sin(str);
    assert(sin >> temp);
    return temp;
}
void assert_eof(FILE *fp) {
    assert(fscanf(fp,"%10000s",buffer)!=1);
}
void assert_int_range(int num, int start, int end) {
    assert(start <= num && num <= end);
}
void assert_int(int num, int start) {
    assert_int_range(num, start, start);
}
int read_int_range(FILE *fp, int start, int end) {
    int num = read_int(fp);
    assert_int_range(num, start, end);
    return num;
}
int main(int agrc, char **agrv){
    FILE *in = fopen(agrv[1],"r");
    FILE *sol = fopen(agrv[2],"r");
    FILE *out = fopen(agrv[3],"r");
    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}
