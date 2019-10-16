# BOJ 스페셜 저지

아래 문제의 스페셜 저지를 만들어 주세요. 문제 목록은 제일 아래에 있습니다.

스페셜 저지는 아래 템플릿를 이용해서 만들어 주세요.

```
#include <cstdio>
#include <cassert>
using namespace std;
int main(int argc, char **argv){
    FILE *in = fopen(argv[1],"r");
    FILE *sol = fopen(argv[2],"r");
    FILE *out = fopen(argv[3],"r");
    return 0;
}
```

작성한 스페셜 저지 파일을 **프로젝트 루트**에 넣은 다음, Pull Request를 이용해서 보내주세요.

* `argv[1]`: 입력 파일의 경로 (데이터 입력)
* `argv[2]`: 출력 파일의 경로 (데이터 출력)
* `argv[3]`: 유저가 출력한 파일의 경로 (유저의 출력)
* `argv[4]`: 채점 번호
* 채점 프로그램의 업데이트로 `argv[5]` 이상을 사용할 수도 있기 때문에, `argc`의 개수를 검사하면 안됩니다.

첨부되어 있는 [12852.cpp](https://github.com/Startlink/BOJ-spj/blob/master/12852.cpp)는 [12852번: 1로 만들기 2](https://www.acmicpc.net/problem/12852)의 채점 소스입니다.

[spj.cpp](https://github.com/Startlink/BOJ-spj/blob/master/spj.cpp)를 이용해서 구현한 스페셜 저지 코드는 [2051.cpp](https://github.com/Startlink/BOJ-spj/blob/master/2051.cpp) 입니다. 이 코드는 [2051번: 최소 버텍스 커버](https://www.acmicpc.net/problem/2051)을 채점하는 소스입니다.

`testlib.h`를 사용하고 싶은 경우에는 첨부되어 있는 [testlib.h](https://github.com/Startlink/BOJ-spj/blob/master/testlib.h)를 이용해 주세요.

Java를 이용해서 구현하려면 [Checker.java](https://github.com/Startlink/BOJ-spj/blob/master/Checker.java)를 이용해 주세요.

## 구현해야 하는 문제 목록 (일부)

* [Minuses](https://www.acmicpc.net/problem/8021)
* [Peaceful Comission](https://www.acmicpc.net/problem/8032)
* [Balance](https://www.acmicpc.net/problem/8023)
* [City Tour](https://www.acmicpc.net/problem/8038)
* [Mirror Trap](https://www.acmicpc.net/problem/7972)
* [Rock Garden](https://www.acmicpc.net/problem/8144)
* [Railway](https://www.acmicpc.net/problem/8147)
* [Building Blocks](https://www.acmicpc.net/problem/8151)
* [Gas Pipelines](https://www.acmicpc.net/problem/8148)
* [Plot purchase](https://www.acmicpc.net/problem/8164)
* [Triangles](https://www.acmicpc.net/problem/8166)
* [Station](https://www.acmicpc.net/problem/8168)
* [Toll](https://www.acmicpc.net/problem/8153)
* [Building blocks](https://www.acmicpc.net/problem/8154)
* [Mirror trap](https://www.acmicpc.net/problem/8157)
* [The Walk of Bytie-boy](https://www.acmicpc.net/problem/8175)
* [Ticket Inspector](https://www.acmicpc.net/problem/8176)
* [Primonimo](https://www.acmicpc.net/problem/13296)
* [Chocolate Eating](https://www.acmicpc.net/problem/6029)
* [Fast Food](https://www.acmicpc.net/problem/6309)
* [It Prefokery Pio](https://www.acmicpc.net/problem/13841)
* [Restriction Enzyme](https://www.acmicpc.net/problem/13843)
* [Divisor is the Conqueror](https://www.acmicpc.net/problem/13848)
* [Reading a Chord](https://www.acmicpc.net/problem/13849)
* [Tiling Polygons](https://www.acmicpc.net/problem/13852)
* [Hyperloop](https://www.acmicpc.net/problem/14086)
* [RAM](https://www.acmicpc.net/problem/14090)
* [Sličice](https://www.acmicpc.net/problem/14133)
* [Filtar](https://www.acmicpc.net/problem/14138)
* [Binarni](https://www.acmicpc.net/problem/14156)
* [Rekonstruiraj](https://www.acmicpc.net/problem/14212)
* [Password Security (Small1)](https://www.acmicpc.net/problem/12040)
* [Password Security (Small2)](https://www.acmicpc.net/problem/12041)
* [Rural Planning (Small)](https://www.acmicpc.net/problem/12303)
* [Rural Planning (Large)](https://www.acmicpc.net/problem/12304)
* [Pogo (Small)](https://www.acmicpc.net/problem/12319)
* [Pogo (Large)](https://www.acmicpc.net/problem/12320)
* [Aerobics (Small)](https://www.acmicpc.net/problem/12376)
* [Aerobics (Large)](https://www.acmicpc.net/problem/12377)
* [Mountain View (Small)](https://www.acmicpc.net/problem/12378)
* [Mountain View (Large)](https://www.acmicpc.net/problem/12379)
* [Equal Sums (Small)](https://www.acmicpc.net/problem/12392)
* [Equal Sums (Large)](https://www.acmicpc.net/problem/12393)
* [House of Kittens (Small)](https://www.acmicpc.net/problem/12501)
* [House of Kittens (Large)](https://www.acmicpc.net/problem/12502)
* [Strelice](https://www.acmicpc.net/problem/14414)
* [Prosječni](https://www.acmicpc.net/problem/13720)
* [Rekonstruiraj](https://www.acmicpc.net/problem/14212)
* [Alice in Foxland](https://www.acmicpc.net/problem/13831)
* [Go++ (Small)](https://www.acmicpc.net/problem/14353)
* [Go++ (Large)](https://www.acmicpc.net/problem/14354)
* [The Gardener of Seville (Small)](https://www.acmicpc.net/problem/14359)
* [The Gardener of Seville (Large)](https://www.acmicpc.net/problem/14360)
* [Slides! (Small)](https://www.acmicpc.net/problem/14365)
* [Slides! (Large)](https://www.acmicpc.net/problem/14366)
* [Fashion Police (Small)](https://www.acmicpc.net/problem/14367)
* [Fashion Police (Large)](https://www.acmicpc.net/problem/14368)
* [Coin Jam (Small)](https://www.acmicpc.net/problem/14385)
* [Coin Jam (Large)](https://www.acmicpc.net/problem/14386)
* [Jetpack](https://www.acmicpc.net/problem/13485)
* [Paralelogrami](https://www.acmicpc.net/problem/14415)
* [Odd Opportunities](https://www.acmicpc.net/problem/6637)
* [Son of Pipe Stream](https://www.acmicpc.net/problem/14642)
* [Hokej](https://www.acmicpc.net/problem/14966)
* [Treetop Walkway](https://www.acmicpc.net/problem/14987)
* [Who needs 8 Queens when you can have N?](https://www.acmicpc.net/problem/9175)
* [Election Frenzy](https://www.acmicpc.net/problem/15171)
* [Jousting Tournament](https://www.acmicpc.net/problem/15164)
* [Trapezi](https://www.acmicpc.net/problem/14520)
* [Pick up sticks](https://www.acmicpc.net/problem/4175)
* [Bukazoids](https://www.acmicpc.net/problem/7492)
* [Towers](https://www.acmicpc.net/problem/10567)
* [Drawing Borders](https://www.acmicpc.net/problem/16051)
* [Last Casino](https://www.acmicpc.net/problem/16111)
* [완전히 다양화 된 수열](https://www.acmicpc.net/2772)
* [Trees Gump](https://www.acmicpc.net/problem/16698)
* [Naan](https://www.acmicpc.net/problem/17670)
