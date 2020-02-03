푼 문제 : 
https://www.acmicpc.net/problem/10430
https://www.acmicpc.net/problem/2609
https://www.acmicpc.net/problem/1934
https://www.acmicpc.net/problem/9613
https://www.acmicpc.net/problem/1978
https://www.acmicpc.net/problem/1929 **
https://www.acmicpc.net/problem/6588

10430번 : 나머지 구하기, 단순하게 출력만하면 되는 문제
연산 범위가 넘어갈 때 다른 방식으로 표현하면 되겠다 이말이야.
#include <cstdio>
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", (a + b) % c);
	printf("%d\n", (a % c + b % c) % c);
	printf("%d\n", (a * b) % c);
	printf("%d\n", (a % c * b % c) % c);
	return 0;
}

2609번 : 최대공약수와 최소공배수, 최소 공배수는 소인수분해로만 풀 수 있는가??
최소공배수는 최대공약수를 활용하여 풀 수 있다. 공통적으로 최대공약수가 포함되고
포함되지 않는 부분의 곱들이 최소공배수에 반드시 포함되어야 함.
- 재귀
#include <cstdio>
int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int g = gcd(a, b);
	printf("%d\n%d\n", g, (a * b) / g);
	return 0;
}
- 반복문 활용
#include <cstdio>
int gcd(int a, int b) {
	int r;
	while (true) {
		r = a % b;
		if (r == 0) {
			return b;
		}
		a = b;
		b = r;
	}
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int g = gcd(a, b);
	printf("%d\n%d\n", g, (a * b) / g);
	return 0;
}

1934번 : 최소공배수, 마찬가지로 gcd를 활용해서 구하면 되지 않을까?

#include <cstdio>
int gcd(int a, int b){
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int g = gcd(a, b);
		int lcm = (a * b) / g;
		printf("%d\n", lcm);
	}
}

9613번 : gcd 합, 가능한 모든 조합을 돌리면 되겠네, 수가 100개 미만이니 N^2도 가능
********* 출력 형식을 정확하게 지정해야한다!!!
#include <cstdio>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (a%b == 0) {
		return b;
	}
	return gcd(b, a % b);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> d(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &d[i]);
		}
		long long ans = 0;
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(d[i], d[j]);
			}
		}
		printf("%lld\n", ans);
	}
}

1978번 : O(N/2)는 O(N)이다.

#include <iostream>
using namespace std;

bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (prime(x)) {
			cnt += 1;
		}
	}
	cout << cnt << endl;
	return 0;
}

1929번 : * 에라토스테네스의 체를 통해 다시 풀어봐 
#include <cstdio>
bool prime(int x){
	if (x < 2)
		return false;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = n; i <= m; i++) {
		if (prime(i)) printf("%d\n", i);
	}
	return 0;
}

- 에라토스테네스의 체
#include <cstdio>
#include <vector>
using namespace std;
bool check[1000001];
vector<int> prime_number;
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			prime_number.push_back(i);
			for (int j = i + i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}
	for (int i = 0; i < prime_number.size(); i++) {
		if (prime_number[i] >= m && prime_number[i] <= n) {
			printf("%d\n", prime_number[i]);
		}
	}
	return 0;
}

6588번 : 골드바흐의 추측, 에라토스테네스의 체를 써야하는가..?

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int check[1000001];
vector<int> prime;
int main() {
	int n = 0;
	memset(check, false, sizeof(check));
	for (int i = 2; i <= 1000000; i++) {
		if (check[i] == false) {
			prime.push_back(i);
			for (int j = i + i; j <= 1000000; j += i) {
				check[j] = true;
			}
		}
	}
	while (scanf("%d", &n)) {
		if (n == 0) break;
		for (int i = 0; i < prime.size(); i++) {
			if (check[n - prime[i]] == false) {
				printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
				break;
			}
		}
	}
	return 0;
}

1. 나머지 연산
2. 최대공약수, 최소공배수
3. 소수

1. 나머지 연산
- (A+B) mod M = ((A mod M) + (B mod M)) mod M
- (AXB) mod M = ((A mod M) X (B mod M)) mod M
- 나누기의 경우 성립하지 않는다. Modular Inverse를 구해야 함
- 뺄셈의 경우 먼저 mod 연산을 한 결과가 음수가 나올 수 있기 때문에 다음과 같이한다.
  (A-B) mod M = ((A mod M) - (B mod M) + M) mod M

2. 최대공약수
- 최대공약수가 1인 두 수를 서로소(Coprime)라고 한다.
- 유클리드 호제법을 이용하여 구한다.
- 최소공배수의 경우 (A*B)/G 를 통하여 구한다.

3. 소수
- N이 소수가 되려면, 2보다 크거나 같고, N-1보다 작거나 같은 자연수로
  나누어 떨어지면 안된다.
- 소수와 관련된 알고리즘은 두 가지가 있다.
  (1) 어떤 수 N이 소수인지 아닌지 판별하는 방법 - 함수 제작 또는 에라토스테네스의 check
  (2) N보다 작거나 같은 모든 자연수 중에 소수를 찾아내는 방법
- N이 소수가 되려면, 2보다 크거나 같고, 루트N 보다 작거나 같은 자연수로 나누어
  떨어지면 안된다.
  이유 : N이 소수가 아리나면 N = a X b (a<=b), 두 수 a와 b의 차이가 가장 작은 경우는
  루트 N이다.
- 에라토스테네스의 체
  (1) 2부터 N까지 모든 수를 써놓는다.
  (2) 아직 지워지지 않은 수 중에서 가장 작은 수를 찾는다.
  (3) 그 수는 소수이다.
  (4) 이제 그 수의 배수를 모두 지운다.
