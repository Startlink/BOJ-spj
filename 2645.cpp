#include<fstream>
#include<queue>
#include<utility>
#include<tuple>
#include<cassert>


using namespace std;
using Point = pair<int, int>;
using Tint = tuple<int, int, int>;

int board[51][51];
int n, k;
Point s, e;

bool is_new_wire[51][51];


// 꼭짓점의 집합(queue<point> line)을 받아서 전선을 그립니다.
// 단, is_new_wire_line이 true인 경우는 board에 전선을 그리지 않고 is_new_wire에 새로운 전선을 놓아야 한다는 표기만 합니다.
// 성공하면 true, 실패하면 false.
bool draw_line(queue<Point> &line, bool is_new_wire_line=false) {
    Point prv = line.front(), cur;
    line.pop();
    int prv_direction = 0, cur_direction;

    while (!line.empty()) {
        cur = line.front();
        // 이전 꼭짓점과 현재 꼭짓점이 같으면 안 됩니다.
        if (prv == cur)
            return false;
        // 수평 전선
        if (prv.first == cur.first) {
            int dir = (cur.second - prv.second)/abs(cur.second - prv.second);
            for (int j = prv.second; j != cur.second; j += dir) {
                if (!is_new_wire_line)
                    board[prv.first][j] = k;
                else
                    is_new_wire[prv.first][j] = true;
            }
            cur_direction = 1;
        }
        // 수직 전선
        else if (prv.second == cur.second) {
            int dir = (cur.first - prv.first)/abs(cur.first - prv.first);
            for (int i = prv.first; i != cur.first; i += dir) {
                if (!is_new_wire_line)
                    board[i][prv.second] = k;
                else
                    is_new_wire[i][prv.second] = true;
            }
            cur_direction = 2;
        }
        // 수평도 수직도 아니면 잘못된 전선입니다.
        else
            return false;
        // 만약 이전과 방향이 같으면 필요 없는 꼭짓점이 존재하는 것.
        if (prv_direction != 0 && prv_direction == cur_direction)
            return false;
        prv = cur;
        prv_direction = cur_direction;
        line.pop();
    }

    if (!is_new_wire_line)
        board[prv.first][prv.second] = k;
    else
        is_new_wire[prv.first][prv.second] = true;
    // 여기까지 왔으면 성공입니다.
    return true;
}


int main(int argc, char **argv) {
    ifstream in(argv[1]);       // 입력
    ifstream sol(argv[2]);      // 모범 답안
    ifstream out(argv[3]);      // 유저의 출력

    fill(&board[0][0], &board[0][0]+2601, 1);

    in >> n;
    in >> s.first >> s.second >> e.first >> e.second;
    in >> k;

    int num_line, num_point;
    in >> num_line;

    for (int i = 0; i < num_line; i++) {
        queue<Point> line;
        Point tmp;

        in >> num_point;
        while (num_point--) {
            in >> tmp.first >> tmp.second;
            line.push(tmp);
        }

        draw_line(line);
    }

    string sol_res;
    sol >> sol_res;

    string tmp;
    int out_res, out_num_point;
    queue<Point> out_new_wire_line;
    Point tmp_point;

    assert(out >> tmp);
    // 유저 출력의 회로 비용은 모범 답안의 회로 비용과 같아야 합니다.
    assert(sol_res == tmp);
    out_res = stoi(tmp);

    assert(out >> tmp);
    out_num_point = stoi(tmp);
    // 회로는 시작점 끝점이 있으니 꼭짓점의 개수는 당연히 2개 이상이어야 합니다.
    assert(out_num_point >= 2);
    
    while (out_num_point--) {
        assert(out >> tmp);
        tmp_point.first = stoi(tmp);
        // 꼭짓점의 행은 1 이상 n 이어야 합니다.
        assert(1 <= tmp_point.first && tmp_point.first <= n);

        assert(out >> tmp);
        tmp_point.second = stoi(tmp);
        // 열도 마찬가지.
        assert(1 <= tmp_point.second && tmp_point.second <= n);

        out_new_wire_line.push(tmp_point);
    }

    // 회로를 그리는 데 성공해야 합니다.
    assert(draw_line(out_new_wire_line, true));

    int new_wire_cost = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (is_new_wire[i][j])
                new_wire_cost += board[i][j];
    // 꼭짓점으로 그린 회로의 비용은 첫 줄의 회로 비용과 일치해야 합니다.
    assert(out_res == new_wire_cost);

    // 남은 출력이 더 있으면 안 됩니다.
    assert(!(out >> tmp));

    return 0;
}
