푼 문제 : 15649 ~ 11개

15649번 : 

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int c[10];
int a[10];
void go(int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d", a[i]);
			if (i != m - 1)
				printf(" ");
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (c[i]) continue;
		a[index] = i; c[i] = true;
		go(n, m, index + 1);
		c[i] = false;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	go(n, m, 0);
	return 0;
}
- c[i]를 쓰는게 리얼루다가 핵심이다.

15650번 : 

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[10];
void go(int n, int m, int index, int _i) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	for (int i = _i; i <= n; i++) {
		a[index] = i;
		go(n, m, index + 1, i + 1);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	go(n, m, 0, 1);
	return 0;
}
- start를 통해 중복이 일어나지 않게

15651번 : 

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[10];
void go(int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		a[index] = i;
		go(n, m, index + 1);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	go(n, m, 0);
	return 0;
}

15652번 :

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[10];
void go(int n, int m, int index, int start) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i <= n; i++) {
		a[index] = i;
		go(n, m, index + 1, i);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	go(n, m, 0, 1);
	return 0;
}
- start에 i를 전달하는게 핵심.

15654번 : 

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[10];
bool c[10];
int d[10];
void go(int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i]) continue;
		d[index] = a[i];
		c[i] = true;
		go(n, m, index + 1);
		c[i] = false;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	go(n, m, 0);
	return 0;
}
- sort 해주고 새로운 배열을 이용하여 값을 담아주는게 핵심

15655번 : 

#include <cstdio>
#include <algorithm>
using namespace std;
int a[10];
int d[10];
bool c[10];
void go(int n, int m, int index, int start) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < n; i++) {
		if (c[i]) continue;
		d[index] = a[i];
		c[i] = true;
		go(n, m, index + 1, i + 1);
		c[i] = false;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	go(n, m, 0, 0);
	return 0;
}

15656번 : 

#include <cstdio>
#include <algorithm>
using namespace std;
int a[10];
int d[10];
bool c[10];
void go(int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		d[index] = a[i];
		go(n, m, index + 1);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	go(n, m, 0);
	return 0;
}

15657번 : 

#include <cstdio>
#include <algorithm>
using namespace std;
int a[10];
int d[10];
bool c[10];
void go(int n, int m, int index, int start) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < n; i++) {
		d[index] = a[i];
		go(n, m, index + 1, i);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	go(n, m, 0, 0);
	return 0;
}

15663번 : 

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int a[10];
int d[10];
int cnt[10001];
vector<int> arr;
void go(int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (cnt[arr[i]] == 0) continue;
		cnt[arr[i]] -= 1;
		d[index] = arr[i];
		go(n, m, index + 1);
		cnt[arr[i]] += 1;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	a[n] = -1;
	for (int i = 0; i < n; i++) {
		cnt[a[i]] += 1;
		if (a[i] != a[i + 1])
			arr.push_back(a[i]);
	}
	go(n, m, 0);
	return 0;
}
- 벡터를 이용하여 중복을 제거하고, bool 대신 count를 사용한게 핵심.

15664번 : 

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int a[10];
int d[10];
int cnt[10001];
vector<int> arr;
void go(int n, int m, int index, int start) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < arr.size(); i++) {
		if (cnt[arr[i]] == 0) continue;
		cnt[arr[i]] -= 1;
		d[index] = arr[i];
		if (cnt[arr[i]] == 0)
			go(n, m, index + 1, i + 1);
		else
			go(n, m, index + 1, i);
		cnt[arr[i]] += 1;
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	a[n] = -1;
	for (int i = 0; i < n; i++) {
		cnt[a[i]] += 1;
		if (a[i] != a[i + 1])
			arr.push_back(a[i]);
	}
	go(n, m, 0, 0);
	return 0;
}
- 이전 문제에 if, else문을 더하였다.

15665번 : 

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int a[10];
int d[10];
int cnt[10001];
vector<int> arr;
void go(int n, int m, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		d[index] = arr[i];
		go(n, m, index + 1);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	a[n] = -1;
	for (int i = 0; i < n; i++) {
		cnt[a[i]] += 1;
		if (a[i] != a[i + 1])
			arr.push_back(a[i]);
	}
	go(n, m, 0);
	return 0;
}

15666번 : 

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int a[10];
int d[10];
int cnt[10001];
vector<int> arr;
void go(int n, int m, int index, int start) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", d[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < arr.size(); i++) {
		d[index] = arr[i];
		go(n, m, index + 1, i);
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	a[n] = -1;
	for (int i = 0; i < n; i++) {
		cnt[a[i]] += 1;
		if (a[i] != a[i + 1])
			arr.push_back(a[i]);
	}
	go(n, m, 0, 0);
	return 0;
}
