// Spaceship 스폐셜 저지
// https://github.com/Startlink/BOJ-spj 참조
#include <bits/stdc++.h>

using namespace std;

int N;
int input[100005];
int out_arr[100005];

// argv[1]: 입력 파일의 경로 (데이터 입력)
// argv[2]: 출력 파일의 경로 (데이터 출력)
// argv[3]: 유저가 출력한 파일의 경로 (유저의 출력)
// argv[4]: 채점 번호
int main(int agrc, char **agrv){
  FILE *in = fopen(agrv[1], "r");
  FILE *ans = fopen(agrv[2], "r");
  FILE *out = fopen(agrv[3], "r");

  // 문제의 입력 받아옴
  fscanf(in, "%d", &N);
  for(int i=0;i<N;i++)
    fscanf(in, "%d", &input[i]);
  fclose(in);

  // 유저가 출력한 데이터 받아옴
  for(int i=0;i<N;i++)
    assert(fscanf(out, "%d", &out_arr[i]) == 1);

  // 이후 추가적인 출력이 없었는 지 확인
  int left;
  assert(fscanf(out, "%d", &left) == -1);
  fclose(out);

  // 마지막 원소가 나머지 N-1개의 합과 같은 지 확인
  long long sum = 0;
  for(int i=0;i<N-1;i++)
    sum += out_arr[i];
  assert(sum == (long long)out_arr[N-1]);

  // 문제에서 주어진 입력 배열로만 구성하였는 지 확인
  sort(input, input+N);
  sort(out_arr, out_arr+N);
  
  for(int i=0;i<N;i++)
    assert(input[i] == out_arr[i]);

  return 0;
}
 