#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

const ll NEG_INF = -1LL << 60;

int N, K;
vector<ll> A;
vector<vector<int>> G;

pair<vector<ll>, vector<ll>> dfs(int u, int par) {
    vector<ll> dp(K + 1, NEG_INF), up(K + 1, NEG_INF);
    dp[0] = 0;
    up[0] = A[u];

    for (int v : G[u]) {
        if (v == par) continue;
        auto child = dfs(v, u);
        vector<ll> dp_child = child.first, up_child = child.second;
        vector<ll> new_dp(K + 1, NEG_INF), new_up(K + 1, NEG_INF);
        rep(t, K + 1) {
            if (dp[t] == NEG_INF && up[t] == NEG_INF) continue;
            rep(s, K - t + 1) {
                if (dp_child[s] != NEG_INF) {
                    new_dp[t + s] = max(new_dp[t + s], dp[t] + dp_child[s]);
                    new_up[t + s] = max(new_up[t + s], up[t] + dp_child[s]);
                }
                if (up_child[s] != NEG_INF) {
                    new_up[t + s] = max(new_up[t + s], dp[t] + up_child[s]);
                }
                if (up_child[s] != NEG_INF && t + s + 1 <= K) {
                    new_dp[t + s + 1] =
                        max(new_dp[t + s + 1], up[t] + up_child[s] - A[u]);
                }
            }
        }
        dp = new_dp;
        up = new_up;
    }
    return make_pair(dp, up);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);
    rep(i, N) cin >> A[i];
    G.assign(N, vector<int>());
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto res = dfs(0, -1);
    vector<ll> dp_root = res.first, up_root = res.second;
    ll ans = 0;
    rep(i, K + 1) {
        ans = max(ans, dp_root[i]);
        ans = max(ans, up_root[i]);
    }
    cout << ans << endl;
    return 0;
}
