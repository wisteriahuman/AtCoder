#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

int main() {
	int N, K, X;
	cin >> N >> K >> X;
	vector<string> S(N);
	rep(i, N) cin >> S[i];
	vector<string> A;
	function<void(int, string)> dfs = [&](int idx, string now) {
		if (idx == K) {
			A.push_back(now);
			return;
		}
		rep(i, N) {
			dfs(idx + 1, now + S[i]);
		}
	};
	dfs(0, "");
	sort(A.begin(), A.end());
	cout << A[X - 1] << endl;

	return 0;
}
