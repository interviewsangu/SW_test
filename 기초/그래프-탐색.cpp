푼 문제 : 1260, 11724, 1707

1260번 : dfs, bfs 구현

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < a[node].size(); i++) {
		if (!check[a[node][i]]) {
			dfs(a[node][i]);
		}
	}
}
void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	puts("");
	memset(check, false, sizeof(check));
	bfs(start);
	puts("");
	return 0;
}

11724번 : 연결 요소의 개수

#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
int cnt = 0;
void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			bfs(i);
			cnt += 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

1707번 : 큐를 이용한 이분 그래프 

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> a[20001];
int check[20001];
void bfs(int start) {
	queue<int> q;
	check[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == 0) {
				check[next] = 3 - check[node];
				q.push(next);
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			check[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				bfs(i);
			}
		}
		bool ans = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				if (check[i] == check[a[i][j]]) {
					ans = true;
				}
			}
		}
		if (ans) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}
