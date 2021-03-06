푼 문제 : 10972번, 10973번, 10974번, 10819번, 10971번

* 순열
- 크기가 N인 순열은 총 N!개가 존재한다.
- 크기는 항상 N이 되어야 하고, 겹치는 숫자가 존재하지 않음
- 다음 순열을 찾는 방법
  (1) A[i-1]<A[i] 를 만족하는 가장 큰 i를 찾는다.
      즉, 순열의 마지막 수에서 끝나는 가장 긴 감소수열을 찾는다.
  (2) j >= i 이면서 A[j]>A[i-1] 를 만족하는 가장 큰 j를 찾는다.
  (3) A[i-1]과 A[j]를 swap 한다.
  (4) A[i]부터 순열을 뒤집는다.
- 순서가 중요한 경우 순열을 고려해봐라.
- 순서 변경시 값이 변경되는 경우
- N제한을 잘 체크해야 한다. 10!까지 가능

10972번 : 다음 순열

- stl 사용
#include <cstdio>
#include <vector>
#include <algorithm>
using  namespace std;
int main() {
	int n;
	scanf("%d\n", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (next_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
	}
	else {
		printf("-1");
	}
	printf("\n");
	return 0;
}

- 구현
#include <cstdio>
#include <vector>
using  namespace std;
bool next_permutation(int n, vector<int>& a) {
	int index = n - 1;
	while (index > 0 && a[index - 1] >= a[index]) {
		index -= 1;
	}
	if (index == 0) {
		return false;
	}
	int j = n - 1;
	while (a[j] <= a[index - 1]) {
		j -= 1;
	}
	swap(a[index - 1], a[j]);
	j = n - 1;
	int i = index;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
int main() {
	int n;
	scanf("%d\n", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (next_permutation(n, a)) {
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
	}
	else {
		printf("-1");
	}
	printf("\n");
	return 0;
}

10973번 : 이전 순열
#include <cstdio>
#include <vector>
using  namespace std;
bool prev_permutation(int n, vector<int>& a) {
	int index = n - 1;
	while (index > 0 && a[index - 1] <= a[index]) {
		index -= 1;
	}
	if (index == 0) {
		return false;
	}
	int j = n - 1;
	while (a[j] >= a[index - 1]) {
		j -= 1;
	}
	swap(a[index - 1], a[j]);
	j = n - 1;
	int i = index;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
int main() {
	int n;
	scanf("%d\n", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (prev_permutation(n, a)) {
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
	}
	else {
		printf("-1");
	}
	printf("\n");
	return 0;
}

10974번 : 모든 순열
#include <cstdio>
#include <vector>
using  namespace std;
bool next_permutation(int n, vector<int>& a) {
	int index = n - 1;
	while (index > 0 && a[index - 1] >= a[index]) {
		index -= 1;
	}
	if (index == 0) {
		return false;
	}
	int j = n - 1;
	while (a[j] <= a[index - 1]) {
		j -= 1;
	}
	swap(a[index - 1], a[j]);
	j = n - 1;
	int i = index;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	while (next_permutation(n, a)) {
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}

10819번 : 차이를 최대로, 순서를 바꾸면 값이 변경된다, 순열을 써보자

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using  namespace std;
bool next_permutation(int n, vector<int>& a) {
	int index = n - 1;
	while (index > 0 && a[index - 1] >= a[index]) {
		index -= 1;
	}
	if (index == 0) {
		return false;
	}
	int j = n - 1;
	while (a[j] <= a[index - 1]) {
		j -= 1;
	}
	swap(a[index - 1], a[j]);
	j = n - 1;
	int i = index;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += abs(a[i] - a[i + 1]);
	}
	while (next_permutation(n, a)) {
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			temp += abs(a[i] - a[i + 1]);
		}
		if (temp > ans) {
			ans = temp;
		}
	}
	printf("%d\n", ans);
	return 0;
}
- N!의 루프에 계산과정에 N이 소모되므로 총 N*N!의 시간이 걸린다.

10971번 : 외판원 순회2

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 4000000;
using  namespace std;
int d[10][10];
bool next_permutation(int n, vector<int>& a) {
	int index = n - 1;
	while (index > 0 && a[index - 1] >= a[index]) {
		index -= 1;
	}
	if (index == 0) {
		return false;
	}
	int j = n - 1; 
	while (a[j] <= a[index - 1]) {
		j -= 1;
	}
	swap(a[index - 1], a[j]);
	j = n - 1;
	int i = index;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &d[i][j]);
		}
	}
	int ans = MAX;
	do {
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			temp += d[a[i]][a[i + 1]];
			if (d[a[i]][a[i + 1]] == 0) {
				temp += MAX;
			}
		}
		temp += d[a[n - 1]][a[0]];
		if (d[a[n - 1]][a[0]] == 0) {
			temp += MAX;
		}
		if (ans > temp) {
			ans = temp;
		}
	} while (next_permutation(n, a));
	printf("%d\n", ans);
	return 0;
}

- 1 2 3 4, 2 3 4 1, 3 4 1 2, 4 1 2 3은 모두 같은 경우이다. 따라서 코드를
약간 변경하면 N!정도의 시간만에 문제를 해결할 수 있다.
- 즉 시작점을 1로 고정하고 뒷 부분만 돌려버리면 된다.
  (1) while문에 next_permutation(a.begin() + 1, a.end())를 하는 방법
  (2) 루프 시작점에서 if(a[0] != 0) break;를 달아주면 된다.

	
6603번 : 로또
- 컴비네이션을 어떻게 구현해야 할까..
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) {
			return 0;
		}
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		vector<int> d(n);
		for (int i = 0; i < n; i++) {
			if (i < 6) {
				d[i] = 0;
			}
			else {
				d[i] = 1;
			}
		}
		do {
			for (int i = 0; i < n; i++) {
				if (d[i] == 0) {
					printf("%d ", a[i]);
				}
			}
			printf("\n");
		} while (next_permutation(d.begin(), d.end()));
		printf("\n");
	}
	return 0;
}

14888번 : 연산자 끼워넣기
- push_back() 사용시 미리 벡터 초기화 X

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<int> b; // 왜 b(n-1)을 하고 푸쉬백을 하면 안되는 걸까?
	// 미리 0이 다 채워진 상태에서 그 뒤에 다음 원소들이 삽입...
	vector<int> count(4);
	for (int i = 0; i < 4; i++) {
		scanf("%d", &count[i]);
	}
	for (int i = 0; i < 4; i++) {
		while (count[i] > 0) {
			b.push_back(i);
			count[i] -= 1;
		}
	}
	long long min = 10000000000;
	long long max = -10000000000;
	do {
		long long temp = a[0];
		for (int i = 0; i < n - 1; i++) {
			if (b[i] == 0) {
				temp += a[i + 1];
			}
			else if (b[i] == 1) {
				temp -= a[i + 1];
			}
			else if (b[i] == 2) {
				temp *= a[i + 1];
			}
			else if (b[i] == 3) {
				temp /= a[i + 1];
			}
		}
		if (max < temp) {
			max = temp;
		}
		if (min > temp) {
			min = temp;
		}
	} while (next_permutation(b.begin(), b.end()));
	printf("%lld\n%lld\n", max, min);
	return 0;
}

- minmx_element의 사용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calc(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int ans = a[0];
    for (int i=1; i<n; i++) {
        if (b[i-1] == 0) {
            ans = ans + a[i];
        } else if (b[i-1] == 1) {
            ans = ans - a[i];
        } else if (b[i-1] == 2) {
            ans = ans * a[i];
        } else {
            ans = ans / a[i];
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> b;
    for (int i=0; i<4; i++) {
        int cnt;
        cin >> cnt;
        for (int k=0; k<cnt; k++) {
            b.push_back(i);
        }
    }
    sort(b.begin(),b.end());
    vector<int> result;
    do {
        int temp = calc(a, b);
        result.push_back(temp);
    } while (next_permutation(b.begin(), b.end()));
    auto ans = minmax_element(result.begin(), result.end());
    cout << *ans.second << '\n';
    cout << *ans.first << '\n';
    return 0;
}

