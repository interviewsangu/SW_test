푼 문제 : 1929, 6588, 2309, 1476, 14500, 9095

* 브루트 포스
- 브루트 포스는 모든 경우의 수를 다 해보는 것이다.
- 이 때, 경우의 수를 다 해보는데 걸리는 시간이 문제의 시간 제한을 넘지 않아야 한다.
- 브루트 포스 문제를 풀 때는 다음과 같은 3가지 단계를 생각할 수 있다.
  (1) 문제의 가능한 경우의 수를 계산해본다.
    - 직접 계산을  통해서 구한다. 대부분 손으로 계산이 가능하다.
  (2) 가능한 모든 방법을 다 만들어본다.
    - 하나도 빠짐 없이 만들어야 한다.
    - 겹치는 부분을 잘 고려해야 한다.
    - 대표적으로 그냥 다 해보는 방법, for, 순열, 재귀, 비트마스크 사용이 있다.
  (3) 각각의 방법을 이용해 답을 구해본다.
    - 이 단계는 보통은 어렵지 않다. 문제에 나와있는 대로 답을 계산해본다.
- 브루트 포스 문제의 시간 복잡도는 대부분 O(경우의 수 * 방법 1개에 걸리는 시간)이 걸린다.

2309번 : 일곱 난쟁이, * 9개 중 7개를 구하는 것은 9개 중 2개를 구하는 것과 같다.
         두 명을 고르는 경우의 수는 N^2라고 할 수 있다.
         나머지 난쟁이의 키의 합을 고르는 시간 복잡도 O(N)
         따라서, 이 문제는 O(N^3)으로 해결할 수 있다.

#include <iostream>
#include <algorithm>
using namespace std;
int a[9];
int n = 9;
int main(){
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a+n);
  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      if(sum - a[i] - a[j] == 100){
        for(int k = 0; k<n; k++){
          if(i == k || j == k) continue;
          cout << a[k] << endl;
        }
        return -;
      }
    }
  }
  return 0;
}
- 이 문제에서 가장 안쪽 for문은 사실상 조건이 맞아 떨어질 때 1번만 돌아가기 때문에,
  해당 알고리즘의 시간 복잡도는 N^2이다.
- 전체를 탐색하는 것에 대해 다시한번 생각해 봐라, j = i + 1

1476번 : 날짜 계산, 수식으로 찾아도 되고, 진짜 문제에서 시키는 대로 그대로 옮겨 적어도 되고.
- 수식으로 푼 경우
#include <cstdio>
int main() {
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);
	int i = 0;
	while (true) {
		int x = i * 28 + s;
		if ((x - e) % 15 == 0 && (x - m) % 19 == 0) {
			printf("%d\n", x);
			return 0;
		}
		i += 1;
	}
}
- 문제에서 시키는 대로 그대로 한 경우
소스 참고..

14500번 : 테트로미노, 모든 경우의 수를 실수 없이 잘 찾아야 한다.
- 무식하게 다 해보기
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[500][500];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//1
			if (j + 3 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
				if (ans < temp) ans = temp;
			}
			if (i + 3 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 1 < m) {
				int temp = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j - 2 >= 0) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 1][j - 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j - 1 >= 0) {
				int temp = a[i][j] + a[i][j - 1] + a[i + 1][j - 1] + a[i + 2][j - 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j - 2 >= 0) {
				int temp = a[i][j] + a[i][j - 1] + a[i][j - 2] + a[i + 1][j - 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j - 1 >= 0) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j - 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i -1 >=0 && j + 2 <m) {
				int temp = a[i][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && i - 1 >= 0 && j - 1 >= 0) {
				int temp = a[i][j] + a[i][j - 1] + a[i + 1][j - 1] + a[i - 1][j - 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && i - 1 >= 0 && j + 1 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i - 1][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			if (i + 1 < n && j - 2 >= 0) {
				int temp = a[i][j] + a[i][j - 1] + a[i + 1][j - 1] + a[i + 1][j - 2];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j + 1 < m) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i + 2 < n && j - 1 >= 0) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1];
				if (ans < temp) ans = temp;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

- 디버깅을 편하게 하기 위해 배열을 사용한 경우, 배열을 만드는 방법을 확인
  ok는 디버깅을 위해서 삽입했구나,,
#include <iostream>
using namespace std;
int a[500][500];
int block[19][3][2] = {
    {{0,1}, {0,2}, {0,3}},
    {{1,0}, {2,0}, {3,0}},
    {{1,0}, {1,1}, {1,2}},
    {{0,1}, {1,0}, {2,0}},
    {{0,1}, {0,2}, {1,2}},
    {{1,0}, {2,0}, {2,-1}},
    {{0,1}, {0,2}, {-1,2}},
    {{1,0}, {2,0}, {2,1}},
    {{0,1}, {0,2}, {1,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,1}, {1,0}, {1,1}},
    {{0,1}, {-1,1}, {-1,2}},
    {{1,0}, {1,1}, {2,1}},
    {{0,1}, {1,1}, {1,2}},
    {{1,0}, {1,-1}, {2,-1}},
    {{0,1}, {0,2}, {-1,1}},
    {{0,1}, {0,2}, {1,1}},
    {{1,0}, {2,0}, {1,1}},
    {{1,0}, {2,0}, {1,-1}},
}; // 19개의 경우의 수에, 각각 3개의 칸이 있고, 각 칸은 좌표 2개
int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 19; k++){
				bool ok = true;
				int sum = a[i][j];
				for(int l = 0; l < 3; l++){
					int x = j + block[k][l][1];
					int y = i + block[k][l][0];
					if(0 <= y && y < n && 0 <= x && x < m){
						sum += a[y][x];
					}
					else{
						ok = false;
						break;
					}
				}
				if(ok && ans < sum){
					ans = sum;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
} 

9095번 : N중 for문 문제이나 실제로는 거의 쓸일이 없기 때문에 다이나믹으로 해결

#include <cstdio>
int cnt_sum(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	return cnt_sum(n - 3) + cnt_sum(n - 2) + cnt_sum(n - 1);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", cnt_sum(n));
	}
	return 0;
}
