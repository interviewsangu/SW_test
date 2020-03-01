** 다이나믹 프로그래밍
- 큰 문제를 작은 문제로 나눠서 푸는 알고리즘 
- 두 가지 속성을 만족해야 다이나믹 프로그래밍으로 문제를 풀 수 있다.
  1. Overlapping Subproblem - 부분 문제가 겹친다.
  2. Optimal Substructure - 문제의 답은 단 한번만 구하면 된다.
- 푸는 방법
  1. 큰 문제를 작은 문제로 나눈다.
  2. 작은 문제를 푼 결과를 이용해 큰 문제를 푼다. = 식으로 표현한다.

푼 문제 : 1463, 11726, 11727, 9095, 15988, 11052, 16194, 15990, 10844, 11057, 2193,
          9465, 2156
          
1463번 : 1로 만들기

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int d[1000001];
int main() {
	int n;
	scanf("%d", &n);
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) {
			int temp = d[i / 2] + 1;
			if (temp < d[i]) {
				d[i] = temp;
			}
		}
		if (i % 3 == 0) {
			int temp = d[i / 3] + 1;
			if (temp < d[i]) {
				d[i] = temp;
			}
		}
	}
	printf("%d\n", d[n]);
	return 0;
}

11726번 : 2 X n 타일링, 그림을 그려라.

#include <cstdio>
int d[1001];
int main() {
	int n;
	scanf("%d", &n);
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 2] + d[i - 1]) % 10007;
	}
	printf("%d\n", d[n]);
	return 0;
}

11727번 : 2 x n 타일링 2

#include <cstdio>
int d[1001];
int go(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (d[n] > 0) return d[n];
	d[n] = ((go(n - 1) % 10007) + (go(n - 2) * 2) % 10007) % 10007;
	return d[n];
}
int main() {
	int n;
	scanf("%d", &n);
	int ans = go(n);
	printf("%d\n", ans);
	return 0;
}

9095번 : 1, 2, 3 더하기

#include <cstdio>
int d[11];
int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		int n;
		scanf("%d", &n);
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		for (int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%d\n", d[n]);
	}
	return 0;
}

15988번 : 1, 2, 3 더하기 3

#include <cstdio>
long long d[1000001];
int main() {
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		d[i] %= 1000000009;
	}
	int t;
	scanf("%d", &t);
	while (t --) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
	return 0;
}

11052번 : 카드 구매하기

#include <cstdio>
int p[1001];
int d[1001];
int go(int n) {
	if (n == 0) {
		return 0;
	}
	if (d[n] > 0) {
		return d[n];
	}
	for (int i = 1; i <= n; i++) {
		int temp = go(n - i) + p[i];
		if (temp > d[n]) {
			d[n] = temp;
		}
	}
	return d[n];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	int ans = go(n);
	printf("%d\n", ans);
	return 0;
}

16194번 : 카드 구매하기 2

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int p[1001];
int d[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = 10000000;
		for (int j = 0; j < i; j++) {
			if (d[i] > d[j] + p[i - j]) {
				d[i] = d[j] + p[i - j];
			}
		}
	}
	printf("%d\n", d[n]);
	return 0;
}

15990번 : 1, 2, 3 더하기 5

#include <cstdio>
long long d[100001][4];
int main() {
	d[1][1] = 1;
	d[1][2] = 0;
	d[1][3] = 0;
	d[1][0] = 1;
	d[2][1] = 0;
	d[2][2] = 1;
	d[2][3] = 0;
	d[2][0] = 1;
	d[3][1] = 1;
	d[3][2] = 1;
	d[3][3] = 1;
	d[3][0] = 3;
	for (int i = 4; i <= 100000; i++) {
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % 1000000009;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % 1000000009;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % 1000000009;
		d[i][0] = d[i][1] + d[i][2] + d[i][3];
		d[i][0] %= 1000000009;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", d[n][0]);
	}
	return 0;
}

10844번 : 쉬운 계단 수

#include <cstdio>
long long d[101][10];
int main() {
	int n;
	scanf("%d", &n);
	d[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		d[i][0] = d[i - 1][1] % 1000000000;
		for (int j = 1; j < 9; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
			d[i][j] %= 1000000000;
		}
		d[i][9] = d[i - 1][8] % 1000000000;
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += (d[n][i] % 1000000000);
	}
	printf("%lld\n", (ans % 1000000000));
	return 0;
}

11057번 : 오르막 수

#include <cstdio>
long long d[1001][10];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += (d[i - 1][k] % 10007);
			}
			d[i][j] %= 10007;
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
	}
	printf("%lld\n", ans % 10007);
	return 0;
}

2193번 : 이친수

#include <cstdio>
long long d[91][2];
int main() {
	int n;
	scanf("%d", &n);
	d[1][1] = 1;
	d[1][0] = 0;
	d[2][1] = 0;
	d[2][0] = 1;
	for (int i = 3; i <= n; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	long long ans = 0;
	ans = d[n][0] + d[n][1];
	printf("%lld\n", ans);
	return 0;
}

9465번 : 스티커

#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
long long a[100001][2];
long long d[100001][3];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a[i][0]);
        }
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a[i][1]);
        }
        d[0][0] = d[0][1] = d[0][2] = 0;
        for (int i=1; i<=n; i++) {
            d[i][0] = max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
            d[i][1] = max(d[i-1][0],d[i-1][2])+a[i][0];
            d[i][2] = max(d[i-1][0],d[i-1][1])+a[i][1];
        }
        long long ans = 0;
        for (int i=1; i<=n; i++) {
            ans = max(max(ans,d[i][0]),max(d[i][1],d[i][2]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

2156번 : 포도주 시식

#include <cstdio>
#include <algorithm>
using namespace std;
int d[10001][3];
int a[10001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n == 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	d[2][0] = a[1];
	d[2][1] = a[2];
	d[2][2] = a[1] + a[2];
	for (int i = 3; i <= n; i++) {
		d[i][2] = d[i - 1][1] + a[i];
		d[i][1] = d[i - 1][0] + a[i];
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
	}
	int ans = 0;
	ans = max(d[n][0], max(d[n][1], d[n][2]));
	printf("%d\n", ans);
	return 0;
}

- 이전의 모든 상황을 언제 포함 하는가?
- 이친수와 포도주의 경우 일차원으로 풀이가 가능하다.
