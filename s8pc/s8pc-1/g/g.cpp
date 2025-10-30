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

const ll INF = 1LL << 60;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<ll>> dist(N, vector<ll>(N, -1));
	vector<vector<ll>> times(N, vector<ll>(N, 0));
	rep(i, M) {
		int s, t;
		ll d, time;
		cin >> s >> t >> d >> time;
		s--; t--;
		dist[s][t] = dist[t][s] = d;
		times[s][t] = times[t][s] = time;
	}

	vector<vector<array<ll, 2>>> dp(1 << N, vector<array<ll, 2>>(N, {INF, 0}));
	dp[1 << 0][0] = {0, 1};

	rep(S, 1 << N) {
		rep(v, N) {
			if (!((S >> v) & 1)) continue;
			rep(u, N) {
				if (u == v) continue;
				if (!((S >> u) & 1)) continue;
				if (dist[u][v] == -1) continue;
				ll t = dp[S][v][0];
				ll nt = dp[S ^ (1 << v)][u][0] + dist[u][v];
				if (nt > times[u][v]) continue;
				if (nt < t) {
					dp[S][v] = {nt, dp[S ^ (1 << v)][u][1]};
				} else if (nt == t) {
					dp[S][v] = {t, dp[S][v][1] + dp[S ^ (1 << v)][u][1]};
				} else {
					// 遷移なし
				}
			}
		}
	}

	array<ll, 2> ans = {INF, 0};
	rep(v, N) {
		if (dist[v][0] == -1) continue;
		ll nt = dp[(1 << N) - 1][v][0] + dist[v][0];
		if (nt > times[v][0]) continue;
		if (ans[0] == nt) {
			ans[1] += dp[(1 << N) - 1][v][1];
		} else if (ans[0] > nt) {
			ans = {nt, dp[(1 << N) - 1][v][1]};
		}
	}

	if (ans[0] == INF) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}
