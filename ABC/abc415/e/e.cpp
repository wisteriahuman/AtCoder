#include <bits/stdc++.h>

#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

struct State {
    bool flag;
    ll first;
    ll second;
};

int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    vector<ll> P(H + W - 1);
    rep(i, H + W - 1) cin >> P[i];

    vector<vector<State>> dp(H, vector<State>(W, {false, 0, 0}));
    dp[0][0] = {true, A[0][0] - P[0], A[0][0] - P[0]};

    auto combine = [&](const State &p1, const State &p2) {
		if (!p1.flag) return p2;
		if (!p2.flag) return p1;
        if (p1.second == p2.second) {
            return p1.first >= p2.first ? p1 : p2;
        }
        return p1.second > p2.second ? p1 : p2;
    };

    rep(i, H) rep(j, W) {
        if (i == 0 && j == 0) continue;
        int k = i + j;
        State cand = {false, 0, 0};
        if (i > 0 && dp[i - 1][j].flag) {
            State np;
			np.flag = true;
            np.first = dp[i - 1][j].first + A[i][j] - P[k];
            np.second = min(dp[i - 1][j].second, np.first);
            cand = np;
        }
        if (j > 0 && dp[i][j - 1].flag) {
            State np;
            np.flag = true;
            np.first = dp[i][j - 1].first + A[i][j] - P[k];
            np.second = min(dp[i][j - 1].second, np.first);
            cand = cand.flag ? combine(cand, np) : np;
        }
        dp[i][j] = cand;
    }

    ll ans = dp[H-1][W-1].flag && dp[H-1][W-1].second < 0 ? -dp[H-1][W-1].second : 0;
    cout << ans << endl;

    return 0;
}

