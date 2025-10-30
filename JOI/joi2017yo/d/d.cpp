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

const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
	vector<int> cnt(M, 0);
	rep(i, N) {
        cin >> a[i];
        a[i]--;
		cnt[a[i]]++;
    }
	vector<vector<int>> cum(M, vector<int>(N + 1, 0));
	rep(i, N) {
		rep(v, M) {
			cum[v][i + 1] = cum[v][i];
		}
		cum[a[i]][i + 1]++;
	}

	vector<int> len(1 << M, 0);
	for (int S = 1; S < (1 << M); S++) {
		int v = __builtin_ctz(S);
		int T = S ^ (1 << v);
		len[S] = len[T] + cnt[v];
	}

    vector<int> dp(1 << M, 0);
    rep(S, 1 << M) {
        rep(v, M) {
            if (!((S >> v) & 1)) continue;
			int l = len[S ^ (1 << v)];
			int r = l + cnt[v];
			int cost = cum[v][r] - cum[v][l];
			dp[S] = max(dp[S], dp[S ^ (1 << v)] + cost);
        }
    }

	int ans = N - dp[(1 << M) - 1];
    cout << ans << endl;


    return 0;

}
