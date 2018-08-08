#include<bits/stdc++.h>


using namespace std;
using Pint = pair<int, int>;

struct Comp_y {
    bool operator()(Pint a, Pint b) {
        return a.second < b.second || (a.second == b.second && a.first < b.first);
    }
};

bool comp_slope(Pint a, Pint b) {
    if (a.first >= 0 && b.first < 0)
        return true;
    if (b.first >= 0 && a.first < 0)
        return false;
    return (long long)a.second*b.first < (long long)a.first*b.second;
}


int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ifstream in(argv[1]);
    ifstream sol(argv[2]);
    ifstream out(argv[3]);

    int n, x, y;
    set<Pint, Comp_y> points;
    in >> n;
    for (int i = 0; i < n; i++) {
        in >> x >> y;
        points.insert(make_pair(x, y));
    }

    int t_sol;
    sol >> t_sol;

    int t;
    assert(out >> t);
    assert(t == t_sol);

    Pint heel;
    if (t != 0) {
        assert(out >> x >> y);
        heel = make_pair(x, y);
        assert(*points.begin() == heel);

        vector<Pint> foot_slope;
        for (int i = 1; i < t; i++) {
            assert(out >> x >> y);
            assert(points.find(make_pair(x, y)) != points.end());
            foot_slope.push_back(make_pair(x-heel.first, y-heel.second));
        }

        int sz = foot_slope.size();
        for (int i = 1; i < sz; i++)
            assert(comp_slope(foot_slope[i-1], foot_slope[i]));
    }

    string tmp;
    assert(!(out >> tmp));

    return 0;
}
