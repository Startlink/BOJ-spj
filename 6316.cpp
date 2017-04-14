#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <vector>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const char dirc[8] = {'n', 'e', 's', 'w', 'N', 'E', 'S', 'W'};
const int MAX_CASES_DIGITS = 100;
const char IMPOSSIBLE_STR[12] = "Impossible.";

int main(int argc, char **argv){
    FILE *in = fopen(argv[1], "r"); // 입력
    FILE *sol = fopen(argv[2], "r"); // 대회 공식 해답
    FILE *out = fopen(argv[3], "r"); // 사용자의 출력
	for(int t=1; ; t++){
		int R, C;
		char map[20][20];
		fscanf(in, "%d %d", &R, &C);
		if(R == 0 && C == 0) break; // 입력의 끝: R, C가 0

		// 빈 줄 하나로 테스트 케이스를 구분
		if(t > 1){
			assert(fgetc(out) == '\n');
			fgetc(sol);
		}

		// 이어서 지도를 마저 입력받는다.
		int sr, sc, sbr, sbc, dr, dc; // 시작점, 상자의 시작점, 목적지
		for(int i=0; i<R; i++){
			fgetc(in);
			for(int j=0; j<C; j++){
				map[i][j] = fgetc(in);
				if(map[i][j] == 'S'){
					sr = i;
					sc = j;
				}
				else if(map[i][j] == 'B'){
					sbr = i;
					sbc = j;
				}
				else if(map[i][j] == 'T'){
					dr = i;
					dc = j;
				}
			}
		}

		// 첫째 줄에 "Maze #t"가 있어야 함
		char c1, c2;
		while(1){
			c1 = fgetc(sol);
			c2 = fgetc(out);
			if(c2 == '\n') break;
			assert(c1 == c2);
		}

		// Impossible인지 먼저 테스트한다.
		c1 = fgetc(sol);
		if(c1 == 'I'){
			for(int i=0; i<strlen(IMPOSSIBLE_STR); i++){
				assert(fgetc(out) == IMPOSSIBLE_STR[i]);
				fgetc(sol);
			}
			assert(fgetc(out) == '\n');
		}
		// Impossible이 아닌 경우:
		else{
			// path test: 먼저 대문자 개수와 소문자 개수가 같은지 체크해야 한다.
			int cntSol[2] = {0}, cntOut[2] = {0};
			vector<char> path;
			do{
				cntSol[isupper(c1)]++;
			}while((c1 = fgetc(sol)) != '\n');
			while((c2 = fgetc(out)) != '\n'){
				assert(isalpha(c2));
				cntOut[isupper(c2)]++;
				path.push_back(c2);
			}
			for(int i=0; i<2; i++)
				assert(cntSol[i] == cntOut[i]);

			// path가 valid한지 체크한다.
			int pr = sr, pc = sc, br = sbr, bc = sbc;
			for(char c: path){
				int ci;
				for(ci=0; ci<8; ci++)
					if(dirc[ci] == c) break;
				assert(ci != 8); // 이상한 문자

				bool pushed = ci/4;
				int d = ci%4;
				int nr = pr+roff[d], nc = pc+coff[d];
				int nbr = br, nbc = bc;
				assert(nr >= 0 && nr < R && nc >= 0 && nc < C);
				assert(map[nr][nc] != '#');
				// 대문자: 상자를 옮겨야 함
				if(pushed){
					assert(nr == br && nc == bc);
					nbr += roff[d];
					nbc += coff[d];
					assert(nbr >= 0 && nbr < R && nbc >= 0 && nbc < C);
					assert(map[nbr][nbc] != '#');
				}
				pr = nr;
				pc = nc;
				br = nbr;
				bc = nbc;
			}
			// 최종적으로 상자가 T에 있어야 함
			assert(br == dr && bc == dc);
		}
	}
}