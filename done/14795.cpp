#include <bits/stdc++.h>
using namespace std;

int main(int agrc, char **agrv){
	/* argv[1] 에는 입력 데이터의 파일 이름이 주어집니다. */
	FILE *in = fopen(agrv[1],"r");
	/* argv[2] 에는 "모범 답안"의 파일 이름이 주어집니다. */
	FILE *sol = fopen(agrv[2],"r");
	/* argv[3] 에는 제출한 프로그램의 출력 결과를 가지고 있는 파일 이름이 주어집니다. */
	/* 주의: 이 파일을 읽을 때는 어떠한 가정을 해서도 안됩니다.
	   예를 들어, 문제에 "연산을 하는 횟수의 최소값을 출력한다." 라고 되어 있음에도 불구하고
	   이 파일에는 정수나 실수, 심지어 문자열이 존재할 수도 있다고 생각하고 채점 프로그램을 작성해야 합니다. */
	FILE *out = fopen(agrv[3],"r");
	int tc; fscanf(in, "%d", &tc);
	char buf[105];
	auto get_from_sol = [&](){
		int punkty, token;
		fscanf(sol, "%*s %*s %d %d",&punkty,&token);
		for(int j=0; j<3*token; j++) fscanf(sol, "%*s");
		return punkty;
	};
	for(int i=1; i<=tc; i++){
		int n, m;
		fscanf(in, "%d %d", &n,&m);
		auto ok = [&](int x, int y){
			return 1 <= x && x <= n && 1 <= y && y <= n;
		};
		char grid[105][105];
		memset(grid, '.', sizeof(grid));
		for(int j=0; j<m; j++){
			int x, y;
			fscanf(in, "%s %d %d",buf,&x,&y);
			grid[x][y] = *buf;
		}
		int punkty_sol = get_from_sol();
		// start judging
		char tmp[100];
		sprintf(tmp, "#%d:", i);
		assert(fscanf(out, "%100s", buf) == 1);
		assert(strcmp(buf, "Case") == 0);
		assert(fscanf(out, "%100s", buf) == 1);
		assert(strcmp(buf, tmp) == 0);
		int punkty, token;
		assert(fscanf(out,"%d %d",&punkty,&token) == 2);
		assert(punkty_sol == punkty);
		for(int j=0; j<token; j++){
			int x, y;
			assert(fscanf(out, "%100s %d %d",buf,&x,&y) == 3);
			assert(strlen(buf) == 1);
			assert(ok(x, y));
			if(*buf == 'o'){
				if(grid[x][y] == '+' || grid[x][y] == 'x') punkty -= 1;
				else if(grid[x][y] == '.') punkty -= 2;
				else assert(false);
				grid[x][y] = *buf;
			}
			else if(*buf == '+' || *buf == 'x'){
				if(grid[x][y] == '.') punkty -= 1;
				else assert(false);
				grid[x][y] = *buf;
			}
			else assert(false);
		}
		assert(punkty == 0);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int k=1; k<j; k++){
					if(grid[i][j] != '.' && grid[i][k] != '.'){
						assert(grid[i][j] == '+' || grid[i][k] == '+');
					}
					if(grid[j][i] != '.' && grid[k][i] != '.'){
						assert(grid[j][i] == '+' || grid[k][i] == '+');
					}
				}
				if(grid[i][j] != '.'){
					for(int k=-100; k<=100; k++){
						if(ok(i + k, j + k) && grid[i + k][j + k] != '.'){
							assert(grid[i + k][j + k] == 'x' || grid[i][j] == 'x');
						}
						if(ok(i + k, j - k) && grid[i + k][j - k] != '.'){
							assert(grid[i + k][j - k] == 'x' || grid[i][j] == 'x');
						}
					}
				}
			}
		}
	}
	fscanf(out, " ");
	assert(feof(out));
	fclose(out);
}
