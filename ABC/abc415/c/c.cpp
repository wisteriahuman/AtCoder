#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

void solve(int N, string S) {
	int bN = (1 << N);
	vector<bool> dp(bN, false);
	dp[0] = true;
	rep(i, bN) {
		if (!dp[i]) continue;
		rep(j, N) {
			if (i >> j & 1) continue;
			int ni = i | (1 << j);
			if (S[ni - 1] == '0') {
				dp[ni] = true;
			}
		}
	}
	cout << (dp[bN - 1] ? "Yes" : "No") << endl;
}

int main() {
	int T;
	cin >> T;
	rep(i, T) {
		int N;
		cin >> N;
		string S;
		cin >> S;
		solve(N, S);
	}
	return 0;
}
