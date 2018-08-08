#include<bits/stdc++.h>


using namespace std;
using Pint = pair<int, int>;

int sol_res;
int out_res;

vector<Pint> sol_blocks;
vector<Pint> out_blocks;


inline void read_int(ifstream &ifs, int &res) {
    string tmp;
    size_t sz;
    assert(ifs >> tmp);
    res = stoi(tmp, &sz);
    assert(tmp.size() == sz);
}


int main(int argc, char **argv) {
    ifstream sol(argv[2]);
    ifstream out(argv[3]);

    int a, b;
    sol >> sol_res;
    for (int i = 0; i < sol_res; i++) {
        sol >> a >> b;
        sol_blocks.push_back(make_pair(a, b));
    }
    read_int(out, out_res);
    assert(sol_res == out_res);
    for (int i = 0; i < out_res; i++) {
        read_int(out, a);
        read_int(out, b);
        out_blocks.push_back(make_pair(a, b));
    }

    sort(sol_blocks.begin(), sol_blocks.end());
    sort(out_blocks.begin(), out_blocks.end());

    for (int i = 0; i < sol_res; i++)
        assert(sol_blocks[i] == out_blocks[i]);

    string tmp;
    assert(!(out >> tmp));

    return 0;
}
