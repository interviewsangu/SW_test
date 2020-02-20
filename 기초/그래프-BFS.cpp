푼 문제 : 2667, 4963, 2178, 7576, 1697, 14226, 13549, 1261, 2206, 3055

2667번 : 단지 번호 붙이기
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int check[25][25];
int cnt = 0;
vector<int> cnts;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
void bfs(int i, int j) {
	check[i][j] = 0;
	int count = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		int next_x;
		int next_y;
		for (int u = 0; u < 4; u++) {
			if (node.first + dx[u] >= 0 && node.first + dx[u] < n && node.second + dy[u] >= 0 && node.second + dy[u] < n) {
				next_x = node.first + dx[u];
				next_y = node.second + dy[u];
			}
			else {
				continue;
			}
			if (check[next_x][next_y] == 1) {
				count += 1;
				check[next_x][next_y] = 0;
				q.push(make_pair(next_x, next_y));
				
			}
		}	
	}
	cnts.push_back(count);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &check[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 1) {
				bfs(i, j);
				cnt += 1;
			}
		}
	}
	printf("%d\n", cnt);
	sort(cnts.begin(), cnts.end());
	for (int i = 0; i < cnts.size(); i++) {
		printf("%d\n", cnts[i]);
	}
	return 0;
}

4963번 : 섬의 개수
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int check[50][50];
int w, h;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
void bfs(int x, int y) {
	check[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (check[nx][ny] == 1) {
					check[nx][ny] = 0;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	while (true) {
		int cnt = 0;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			return 0;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				check[i][j] = 0;
				scanf("%d", &check[i][j]);
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (check[i][j] == 1) {
					bfs(i, j);
					cnt += 1;
				}
			}
		}
		printf("%d\n", cnt);
	}
}

2178번 : 미로탐색

#include <cstdio>
#include <queue>
using namespace std;
int n,m;
int a[100][100];
bool check[100][100];
int dist[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = true;
    dist[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (check[nx][ny] == false && a[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                    check[nx][ny] = true;
                }
            }
        }
    }
    printf("%d\n",dist[n-1][m-1]);
    return 0;
}

7576번 : 토마토
- 어떻게 동시에 시작하게 할 수 있을까?; 큐의 특성을 이용하자
- 먼저 시작해야 하는 친구들 먼저 큐에 집어 넣고 큐 탐색을 하면된다.
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int tomato[1000][1000];
int cnt[1000][1000];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void bfs(queue<pair<int,int>> &q) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (tomato[nx][ny] == 0) {
					tomato[nx][ny] = 1;
					cnt[nx][ny] = cnt[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &m, &n);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
                cnt[i][j] = 0;
			}
		}
	}
	bfs(q);
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < cnt[i][j]) {
				max = cnt[i][j];
			}
			if (tomato[i][j] == 0) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}

1697번 : 숨바꼭질

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
int cnt[100001];
bool check[100001];
int n, k;
void bfs() {
	int start = n;
	q.push(start);
	check[start] = true;
	cnt[start] = 0;
	while (!q.empty()) {
		start = q.front();
		if (start == k) {
			return;
		}
		q.pop();
		if (start -1 >=0 && check[start - 1] == false) {
			check[start - 1] = true;
			cnt[start - 1] = cnt[start] + 1;
			q.push(start - 1);
		}
		if (start + 1 <= 100000 && check[start + 1] == false) {
			check[start + 1] = true;
			cnt[start + 1] = cnt[start] + 1;
			q.push(start + 1);
		}
		if (start * 2 <= 100000 && check[start * 2] == false) {
			check[start * 2] = true;
			cnt[start * 2] = cnt[start] + 1;
			q.push(start * 2);
		}
	}
}
int main() {
	scanf("%d %d", &n, &k);
	bfs();
	printf("%d\n", cnt[k]);
	return 0;
}

14226번 : 이모티콘
- pair를 이용하여
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
bool check[1001][1001];
int cnt[1001][1001];
int s;
void bfs() {
	check[1][0] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(1,0));
	cnt[1][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == s) {
			printf("%d\n", cnt[x][y]);
			return;
		}
		if (x + y <= 1000 && check[x + y][y] == false) {
			check[x + y][y] = true;
			cnt[x + y][y] = cnt[x][y] + 1;
			q.push(make_pair(x + y, y));
		}
		if (x - 1 >0 && check[x - 1][y] == false) {
			check[x - 1][y] = true;
			cnt[x - 1][y] = cnt[x][y] + 1;
			q.push(make_pair(x - 1, y));
		}
		if (y != x && check[x][x] == false) {
			check[x][x] = true;
			cnt[x][x] = cnt[x][y] + 1;
			q.push(make_pair(x, x));
		}
	}
}
int main() {
	scanf("%d", &s);
	bfs();
	return 0;
}

13549번 : 숨바꼭질 3, deque 사용

#include <cstdio>
#include <deque>
using namespace std;
bool check[100001];
int cnt[100001];
int n, k;
int main() {
	scanf("%d %d", &n, &k);
	deque<int> q;
	q.push_front(n);
	check[n] = true;
	cnt[n] = 0;
	while (!q.empty()) {
		int node = q.front();
		if (node == k) break;
		q.pop_front();
        if (node * 2 <= 100000 && check[node * 2] == false) {
			check[node * 2] = true;
			q.push_front(node * 2);
			cnt[node * 2] = cnt[node];
		}
		if (node - 1 >= 0 && check[node - 1] == false) {
			check[node - 1] = true;
			q.push_back(node - 1);
			cnt[node - 1] = cnt[node] + 1;
		}
		if (node + 1 <= 100000 && check[node + 1] == false) {
			check[node + 1] = true;
			q.push_back(node + 1);
			cnt[node + 1] = cnt[node] + 1;
		}
		
	}
	printf("%d\n", cnt[k]);
	return 0;
}

1261번 : 알고스팟 
- 벽을 부쉈는가, 부수지 않았는가의 상황을 나타내야한다.
- 상황이 여러개 이기 때문에 덱을 사용할 수 있다.
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int d[555][555];
int a[555][555];
int n,m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    scanf("%d %d",&m,&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
            d[i][j] = -1;
        }
    }
    deque<pair<int,int>> q;
    q.push_back(make_pair(0,0));
    d[0][0] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (d[nx][ny] == -1) {
                    if (a[nx][ny] == 0) {
                        d[nx][ny] = d[x][y];
                        q.push_front(make_pair(nx,ny));
                    } else {
                        d[nx][ny] = d[x][y]+1;
                        q.push_back(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    printf("%d\n",d[n-1][m-1]);
    return 0;
}

* 2206번 : 벽 부수고 이동하기
- 튜플을 사용하여 벽을 부순 경우와 안부순 경우로 나눌 수 있다.
- 값은 어디에 들어있을지 모른다.
#include <cstdio>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;
int a[1001][1001];
int cnt[1001][1001][2];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int n, m;
void bfs(){
	cnt[1][1][0] = 1;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 1, 0));
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (cnt[nx][ny][z] == 0 && a[nx][ny] == 0) {
					cnt[nx][ny][z] = cnt[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
				if (z == 0 && cnt[nx][ny][z + 1] == 0 && a[nx][ny] == 1) {
					cnt[nx][ny][z + 1] = cnt[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z + 1));
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	bfs();
	if (cnt[n][m][0] != 0 && cnt[n][m][1] != 0) {
		printf("%d\n", min(cnt[n][m][0], cnt[n][m][1]));
	}
	else if (cnt[n][m][0] != 0) {
		printf("%d\n", cnt[n][m][0]);
	}
	else if (cnt[n][m][1] != 0) {
		printf("%d\n", cnt[n][m][1]);
	}
	else {
		printf("-1\n");
	}
	return 0;
}

*** 3055번 : 탈출
- 소스
#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int water[50][50];
int d[50][50];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    memset(water,-1,sizeof(water));
    queue<pair<int,int>> q;
    int sx,sy,ex,ey;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == '*') {
                q.push(make_pair(i,j));
                water[i][j] = 0;
            } else if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (a[i][j] == 'D') {
                ex = i;
                ey = j;
            }
        }
    }
    while (!q.empty()) {
        int x, y;
        tie(x,y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (water[nx][ny] != -1) continue;
            if (a[nx][ny] == 'X') continue;
            if (a[nx][ny] == 'D') continue;
            water[nx][ny] = water[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    memset(d,-1,sizeof(d));
    q.push(make_pair(sx,sy));
    d[sx][sy] = 0;
    while (!q.empty()) {
        int x, y;
        tie(x,y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (d[nx][ny] != -1) continue;
            if (a[nx][ny] == 'X') continue;
            if (water[nx][ny] != -1 && d[x][y]+1 >= water[nx][ny]) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    if (d[ex][ey] == -1) {
        cout << "KAKTUS\n";
    } else {
        cout << d[ex][ey] << '\n';
    }
    return 0;
}
- water 배열을 먼저 만들어 놓고 시간을 비교하여 계산하였다.

- 내 소스
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
using namespace std;
int dx[] = { 0,0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int r, c;
int ex, ey, sx, sy, wx, wy;
int check[50][50];
int main() {
	queue<tuple<int, int, int>> q;
	memset(check, -1, sizeof(check));
	cin >> r >> c;
	vector<string> a(r);
	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'D') { ex = i; ey = j; }
			else if (a[i][j] == '*') { wx = i; wy = j; 
			q.push(make_tuple(wx, wy, 1));
			check[wx][wy] = 0;
			}
			else if (a[i][j] == 'S') { sx = i; sy = j; 
			}
		}
	}
	q.push(make_tuple(sx, sy, 0));
	check[sx][sy] = 0;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (z == 1) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (a[nx][ny] == '.' && check[nx][ny] == -1) {
					q.push(make_tuple(nx, ny, 1));
					check[nx][ny] = 0;
				}
			}
			else if (z == 0) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if ((a[nx][ny] == '.' || a[nx][ny] == 'D') && check[nx][ny] == -1) {
					q.push(make_tuple(nx, ny, 0));
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}
	if (check[ex][ey] != -1) {
		printf("%d\n", check[ex][ey]);
	}
	else {
		printf("KAKTUS\n");
	}
	return 0;
}
- 튜플을 이용하여 상황을 나타내었다.
- 물이 먼저 큐에 삽입되게 하고, 튜플의 마지막 요소를 검사해 어떤 것을 큐에 삽입할지
  결정하였다. 일단 물이 먼저 삽입되게 되면 언제나 물이 먼저 이동하게 된다.
- *** 물이 없는 경우가 있을 수 있기 때문에 물이 주어진 경우에만 초기화를 시작한다.

