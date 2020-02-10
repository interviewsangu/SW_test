푼 문제 : 11723, 1182

* 비트마스크
- 0부터 N - 1까지 정수로 이루어진 집합을 나타낼 때 사용한다.
- 1부터 N까지 정수로 이루어진 집합을 사용하는 건 공간이 2배 더 필요한다.
- 확인하기 &
- 추가하기 |
- 제거하기 & ~
- 토글 ^ (1<<i)
- for(int i = 0; i<(1<<n); i++){} 전체를 검사하기 위한 포문

11723번 :
#include <cstdio>
#include <cstring>
using namespace std;
char b[111];
int main() {
    int n = 20;
    int m;
    scanf("%d",&m);
    int s = 0;
    int x;
    while (m--) {
        scanf("%s",b);
        if (!strcmp(b,"add")) {
            scanf("%d",&x); x--;
            s = (s | (1 << x));
        } else if (!strcmp(b,"remove")) {
            scanf("%d",&x); x--;
            s = (s & ~(1 << x));
        } else if (!strcmp(b,"check")) {
            scanf("%d",&x); x--;
            int res = (s & (1 << x));
            if (res) {
                puts("1");
            } else {
                puts("0");
            }
        } else if (!strcmp(b,"toggle")) {
            scanf("%d",&x); x--;
            s = (s ^ (1 << x));
        } else if (!strcmp(b,"all")) {
            s = (1<<n)-1;
        } else if (!strcmp(b,"empty")) {
            s = 0;
        }
    }
    return 0;
}
-입력을 받고 나서 1을 빼는 이유는 1~N을 0~N-1로 표현하기 위해서이다.

1182번 : 부분집합의 합
- 재귀로 풀었던 문제를 비트마스크로 풀어보자.

#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	for (int i = 1; i < (1 << n); i++) {
		int temp = 0;
		for (int k = 0; k < n; k++) {
			if (i & (1 << k)) {
				temp += a[k];
			}
		}
		if (temp == s) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
- 재귀보다 시간은 오래 걸리네
부분 집합을 구하는 시간 2^N, 각 부분 집합마다 for문을 돌리는 시간 N
O(N X 2^N)시간이 걸린다.
