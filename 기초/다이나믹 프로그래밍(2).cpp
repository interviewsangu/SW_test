푼 문제 : 11053, ** 14002, 11055, 11722, 11054, 1912, 13398

11053번 : 가장 긴 증가하는 부분 수열

#include <cstdio>
int d[1001];
int a[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}
	// 돌면서 맥스값 찾아야지 뭐하냐 왜 끝에 맥스가 있을거라 생각한거임 printf("%d\n", d[n]);
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[i]) {
			max = d[i];
		}
	}
	printf("%d\n", max);
	return 0;
}

14002번 *** : 가장 긴 증가하는 부분 수열 4
- index 추적하기, 복원 = 기록
- reverse = 재귀로 가능
#include <cstdio>
int a[100001];
int d[100001];
int v[100001];
void go(int index) {
	if (index == -1) {
		return;
	}
	go(v[index]);
	printf("%d ", a[index]);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}
	int index = 0;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[i]) {
			max = d[i];
			index = i;
		}
	}
	printf("%d\n", max);
	go(index);
	return 0;
}

11055번 : 가장 큰 증가하는 부분 수열
- 합이나 길이나 푸는 방법은 같다.
#include <cstdio>
int a[1001];
int d[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = a[i];
		for (int j = 1; j < i; j++) {
			if (d[i] < d[j] + a[i] && a[i] > a[j]) {
				d[i] = d[j] + a[i];
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[i]) {
			max = d[i];
		}
	}
	printf("%d\n", max);
	return 0;
}

11722번 : 가장 긴 감소하는 부분 수열
- 뒤집어서 풀거나 그냥 부등호 반대
#include <cstdio>
int a[1001];
int d[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (d[i] < d[j] + 1 && a[i] < a[j]) {
				d[i] = d[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[i]) {
			max = d[i];
		}
	}
	printf("%d\n", max);
	return 0;
}

11054번 : 가장 긴 바이토닉 부분 수열
- 앞 뒤로 구하면 된다.

#include <cstdio>
int a[1001];
int d[1001];
int d2[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (d[i] < d[j] + 1 && a[i] > a[j]) {
				d[i] = d[j] + 1;
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		d2[i] = 1;
		for (int j = n; j > i; j--) {
			if (d2[i] < d2[j] + 1 && a[i] > a[j]) {
				d2[i] = d2[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < d[i] + d2[i]) {
			max = d[i] + d2[i];
		}
	}
	printf("%d\n", max - 1);
	return 0;
}

1912번 : 연속합

#include <cstdio>
int a[100001];
int d[100001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i] = a[i];
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	int ans = -2000;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}

13398번 : 연속합 2
- 상황을 나누는 경우
- 반드시 1개를 선택 : 초기화가 매우 중요하다.
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100001];
int d[100001][3];
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
	d[1][0] = a[1];
	d[1][1] = a[1];
	d[1][2] = 0;
	for (int i = 2; i <= n; i++) {
		d[i][0] = a[i];
		d[i][1] = max(d[i - 1][0] + a[i], d[i - 1][1] + a[i]);
		d[i][2] = max(d[i - 1][2] + a[i], max(d[i - 1][0], d[i - 1][1]));
	}
	int max = -20000000;
	d[1][2] = a[1];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 2; j++) {
			if (max < d[i][j]) {
				max = d[i][j];
			}
		}
	}
	printf("%d\n", max);
	return 0;
}

- 바이토닉 방식
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    vector<int> dr(n);
    for (int i=0; i<n; i++) {
        d[i] = a[i];
        if (i == 0) continue;
        if (d[i] < d[i-1] + a[i]) {
            d[i] = d[i-1] + a[i];
        }
    }
    for (int i=n-1; i>=0; i--) {
        dr[i] = a[i];
        if (i == n-1) continue;
        if (dr[i] < dr[i+1] + a[i]) {
            dr[i] = dr[i+1] + a[i];
        }
    }
    int ans = d[0];
    for (int i=1; i<n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    for (int i=1; i<n-1; i++) {
        if (ans < d[i-1] + dr[i+1]) {
            ans = d[i-1] + dr[i+1];
        }
    }
    cout << ans << '\n';
    return 0;
}
