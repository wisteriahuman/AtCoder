#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using mint=modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> P(K, 0);
	vector<int> ans;
	rep(i, K) {
		int a, b;
		cin >> a >> b;
		if (++P[--a] == M) {
			ans.push_back(++a);
		}
	}

	rep(i, ans.size()) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}

	return 0;
}
