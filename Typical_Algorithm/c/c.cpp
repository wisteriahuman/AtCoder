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
#define INF 1e18

int main() {
	int N;
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	rep(i, N) rep(j, N) {
		cin >> A[i][j];
	}
	vector<vector<ll>> dp(1 << N, vector<ll>(N, INF));
	dp[1 << 0][0] = 0;

	rep(S, 1 << N) {
		rep(v, N) {
			if (!((S >> v) & 1)) continue;
			rep(u, N) {
				if (u == v) continue;
				if (!((S >> u) & 1)) continue;
				dp[S][v] = min(dp[S][v], dp[S ^ (1 << v)][u] + A[u][v]);
			}
		}
	}

	ll ans = INF;

	rep2(v, 1, N) {
		ans = min(ans, dp[(1 << N) - 1][v] + A[v][0]);
	}
	cout << ans << endl;

	return 0;
}
