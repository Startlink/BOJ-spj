#include <bits/stdc++.h>
using namespace std;

struct pos
{
    __int128 x, y;
    bool operator ==(const pos& a) const
    {
        return x == a.x && y == a.y;
    }
};

__int128 grad(pos a, pos b)
{
    assert(a.x != b.x && (a.y - b.y) % (a.x - b.x) == 0);
    return (a.y - b.y) / (a.x - b.x);
}

int main(int argc, char** argv)
{
    FILE* in = fopen(argv[1], "r");
    FILE* sol = fopen(argv[2], "r");
    FILE* out = fopen(argv[3], "r");

    int m1;
    vector<pos> v1;
    fscanf(sol, "%d", &m1);
    for(int i = 0; i < m1; i++)
    {
        long long x, y;
        fscanf(sol, "%lld%lld", &x, &y);
        v1.push_back({ x, y });
    }

    int m2;
    vector<pos> v2;
    assert(fscanf(out, "%d", &m2) == 1);
    assert(2 <= m2 && m2 <= 100000);
    for(int i = 0; i < m2; i++)
    {
        long long x, y;
        assert(fscanf(out, "%lld%lld", &x, &y) == 2);
        v2.push_back({ x, y });
    }

    fscanf(out, " ");
    assert(feof(out));

    for(int i = 0; i < m2 - 1; i++)
    {
        assert(v2[i].x < v2[i + 1].x);
        assert((v2[i].y - v2[i + 1].y) % (v2[i].x - v2[i + 1].x) == 0);
    }

    vector<pos> cv1;
    for(int i = 0; i < m1; i++)
        if(i == 0 || i == m1 - 1 || grad(v1[i - 1], v1[i]) != grad(v1[i], v1[i + 1]))
            cv1.push_back(v1[i]);

    vector<pos> cv2;
    for(int i = 0; i < m2; i++)
        if(i == 0 || i == m2 - 1 || grad(v2[i - 1], v2[i]) != grad(v2[i], v2[i + 1]))
            cv2.push_back(v2[i]);

    int sz1 = (int)cv1.size();
    int sz2 = (int)cv2.size();

    assert(sz1 == sz2);

    for(int i = 1; i < sz1 - 1; i++)
        assert(cv1[i] == cv2[i]);

    assert(grad(cv1[0], cv1[1]) == grad(cv2[0], cv2[1]) && grad(cv1[sz1 - 2], cv1[sz1 - 1]) == grad(cv2[sz2 - 2], cv2[sz2 - 1]));

    if(sz1 == 2)
    {
        __int128 g = grad(cv1[0], cv1[1]);
        assert(cv1[0] == cv2[0] || g == grad(cv1[0], cv2[0]));
        assert(cv1[0] == cv2[1] || g == grad(cv1[0], cv2[1]));
    }

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}
