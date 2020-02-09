1759푼 문제 : 9095, 1759, 6603, 1182, 14501, 14888, 15658,

* 재귀
- 재귀의 겨우 불가능한 경우, 정답을 찾은 경우, 다음 경우로 분류해 보자.
- 인덱스를 주의해서 보자.
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
- 순열로 구현한 경우
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int l, c;
	cin >> l >> c;
	vector<char> a(c);
	vector<int> diff(c);
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < c; i++) {
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
			diff[i] = 0;
		}
		else {
			diff[i] = 1;
		}
	}
	vector<int> combi;
	for(int i = 0; i<c; i++){
		if (i < l) combi.push_back(0);
		else combi.push_back(1);
	}
	do {
		int ah = 0;
		int wk = 0;
		vector<char> temp;
		for (int i = 0; i < c; i++) {
			if (combi[i] == 0) {
				temp.push_back(a[i]);
				if (diff[i] == 0) ah += 1;
				else wk += 1;
			}
		}
		if (ah >= 1 && wk >= 2) {
			for (int i = 0; i < l; i++) {
				cout << temp[i];
			}
			cout << endl;
		}
	} while (next_permutation(combi.begin(), combi.end()));
	return 0;
}

** 재귀로 구현한 경우
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool check(string& password) {
	int ja = 0;
	int mo = 0;
	for (char x : password) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			mo += 1;
		else
			ja += 1;
	}
	return mo >= 1 && ja >= 2;
}
void go(int l, vector<char>& alpha, string password, int i) {
	if (password.length() == l) {
		if (check(password)) {
			cout << password << endl;
		}
		return;
	}
	if (i == alpha.size()) return;
	go(l, alpha, password + alpha[i], i + 1);
	go(l, alpha, password, i + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int l, c;
	cin >> l >> c;
	vector<char> a(c);
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	go(l, a, "", 0);
	return 0;
}

6603번 : 로또, 재귀를 이용하여 풀어보기

#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;
void go(vector<int>& a, int index, int cnt) {
	if (cnt == 6) {
		for (int num : lotto) {
			cout << num << " ";
		}
		cout << endl;
		return;
	}
	if (index < a.size()) {
		lotto.push_back(a[index]);
		go(a, index + 1, cnt + 1);
		lotto.pop_back();
		go(a, index + 1, cnt);
	}
	else return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		go(a, 0, 0);
		cout << endl;
	}
}

1182번 : 재귀 함수 사용하기

#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
void go(int index, vector<int>& a, int match, int sum) {
	if (index == a.size())
		return;
	if (sum + a[index] == match) {
		cnt += 1;
	}
	go(index + 1, a, match, sum + a[index]);
	go(index + 1, a, match, sum);
}
int main() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, a, s, 0);
	cout << cnt << endl;
	return 0;
}

14501번 : 퇴사
- 소스 코드, ans를 저렇게 사용해도 되는구나..
#include <iostream>
using namespace std;
const int inf = -100000000;
int t[21];
int p[21];
int n;
int ans = 0;
void go(int day, int sum) {
    if (day == n+1) {
        if (ans < sum) ans = sum;
        return;
    }
    if (day > n+1) {
        return;
    }
    go(day+1, sum);
    go(day+t[day], sum+p[day]);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }
    go(1, 0);
    cout << ans << '\n';
    return 0;
}

- 내 코드, n 범위 제대로 확인해보기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> box;
void go(vector<int> &t, vector<int> &p,int index, int sum, int n, vector<int> &box){
	if (index >= n) {
		if (index == n) {
			box.push_back(sum);
		}
		return;
	}
	go(t, p, index + 1, sum, n, box);
	go(t, p, index + t[index], sum + p[index], n, box);

}
int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	vector<int> p(n);
	for(int i = 0; i<n; i++){
		cin >> t[i] >> p[i];
	}
	go(t, p, 0, 0, n, box);
	auto max = max_element(box.begin(), box.end());
	cout << *max << endl;
	return 0;
}


15658번 : 연산자 끼워넣기(2), 시간 복잡도가 (4^N-1)
	
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> box;
void go(int index, int n, long long result,
	vector<int> &a,int add, int min, int mul, int minu) {
	if (index == n) {
		box.push_back(result);
		return;
	}
	if(add > 0)
		go(index + 1, n, result + a[index], a, add - 1, min, mul, minu);
	if(min > 0)
		go(index + 1, n, result - a[index], a, add , min - 1, mul, minu);
	if(mul > 0)
		go(index + 1, n, result * a[index], a, add , min, mul - 1, minu);
	if(minu > 0)
		go(index + 1, n, result / a[index], a, add , min, mul, minu - 1);
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> op(4);
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	go(1, n, a[0], a, op[0], op[1], op[2], op[3]);
	auto p = minmax_element(box.begin(), box.end());
	cout << *p.second << endl;
	cout << *p.first << endl;
	return 0;
}
