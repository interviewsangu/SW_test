1759푼 문제 : 9095, 1759, 6603, 1182, 14501, 14888, 15658,

9095번 : 1, 2, 3 더하기

#include <cstdio>
int sum(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	return sum(n - 3) + sum(n - 2) + sum(n - 1);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int ans;
		ans = sum(n);
		printf("%d\n", ans);
	}
	return 0;
}

- 반복문으로 구현하기
#include <cstdio>
int d[11];
int main() {
	d[0] = 1;
	for (int i = 1; i <= 10; i++) {
		if (i - 1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}
	return 0;
}

1759번 : 암호만들기
