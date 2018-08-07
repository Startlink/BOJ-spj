#include<fstream>
#include<numeric>
#include<cassert>


using namespace std;

int max_dist, n;
int dist[101], mt_time[100];
int acc_dist[102];


inline void read_int(ifstream &ifs, int &res) {
    string tmp;
    size_t sz;
    assert(ifs >> tmp);
    res = stoi(tmp, &sz);
    assert(tmp.size() == sz);
}


int main(int argc, char **argv) {
    ifstream in(argv[1]);
    ifstream sol(argv[2]);
    ifstream out(argv[3]);

    in >> max_dist >> n;
    for (int i = 0; i <= n; i++)
        in >> dist[i];
    for (int i = 0; i < n; i++)
        in >> mt_time[i];
    
    partial_sum(dist, dist+n+1, acc_dist+1);

    int sol_res;
    sol >> sol_res;

    int out_res, out_mt_num, out_route[102] = {0};

    read_int(out, out_res);
    assert(out_res == sol_res);

    read_int(out, out_mt_num);

    for (int i = 1; i <= out_mt_num; i++) {
        read_int(out, out_route[i]);
        assert(1 <= out_route[i] && out_route[i] <= n);
    }
    out_route[out_mt_num+1] = n+1;
    for (int i = 1; i <= out_mt_num+1; i++)
        assert(acc_dist[out_route[i]] - acc_dist[out_route[i-1]] <= max_dist);
    int cnt = 0;
    for (int i = 1; i <= out_mt_num; i++)
        cnt += mt_time[out_route[i]-1];
    assert(cnt == out_res);

    string tmp;
    assert(!(out >> tmp));

    return 0;
}
