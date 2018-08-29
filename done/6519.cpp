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
    assert(fscanf(fp, "%10000s", buffer) == 1);
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
    assert(fscanf(fp, "%10000[^\n]\n", buffer) == 1);
    return string(buffer);
}

void assert_eof(FILE *fp) {
    assert(fscanf(fp, "%10000s", buffer) != 1);
}

int main(int agrc, char **agrv){
    FILE *in = fopen(agrv[1], "r");
    FILE *sol = fopen(agrv[2], "r");
    FILE *out = fopen(agrv[3], "r");

    while (true) {
        int cx = read_int(in);
        int cy = read_int(in);
        if (cx == 0 && cy == 0)
            break;

        int startX = cx * 2 - 1;
        int startY = cy * 2 - 1;
        int endX = read_int(in) * 2 - 1;
        int endY = read_int(in) * 2 - 1;

        bool map[13][13] = { 0, };
        for (int i = 0; i < 3; i++) {
            int sx = read_int(in) * 2;
            int sy = read_int(in) * 2;
            int ex = read_int(in) * 2;
            int ey = read_int(in) * 2;

            if (sy == ey) {
                for (int x = sx; x <= ex; x++)
                    map[sy][x] = true;
            } else {
                for (int y = sy; y <= ey; y++)
                    map[y][sx] = true;
            }
        }

        string answer = read_line(sol);
        string userAnswer = read_line(out);
        assert(answer.size() == userAnswer.size());

        string path = userAnswer;
        int y = startY;
        int x = startX;
        for (int i = 0; i < path.size(); i++) {
            assert(path[i] == 'N' || path[i] == 'E' || path[i] == 'S' || path[i] == 'W');

            switch (path[i]) {
                case 'N':
                    y--;
                    assert(y < 13 && y >= 0 && !map[y][x]);
                    y--;
                    assert(y < 13 && y >= 0 && !map[y][x]);
                    break;
                case 'E':
                    x++;
                    assert(x < 13 && x >= 0 && !map[y][x]);
                    x++;
                    assert(x < 13 && x >= 0 && !map[y][x]);
                    break;
                case 'S':
                    y++;
                    assert(y < 13 && y >= 0 && !map[y][x]);
                    y++;
                    assert(y < 13 && y >= 0 && !map[y][x]);
                    break;
                case 'W':
                    x--;
                    assert(x < 13 && x >= 0 && !map[y][x]);
                    x--;
                    assert(x < 13 && x >= 0 && !map[y][x]);
                    break;
            }
        }

        assert(y == endY && x == endX);
    }

    assert(fscanf(out, "%10000[^\n]\n", buffer) == -1);

    fclose(in);
    fclose(sol);
    fclose(out);
    return 0;
}
