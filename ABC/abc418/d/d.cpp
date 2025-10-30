#include <bits/stdc++.h>

#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

int main() {
    int N;
    cin >> N;
    string T;
    cin >> T;

    vector<int> pref(N + 1, 0);
    rep(i, N) {
        pref[i + 1] = pref[i] ^ (T[i] - '0');
    }

    ll cnt[2][2] = {};
    cnt[0][0] = 1;

    ll ans = 0;
    rep2(j, 1, N + 1) {
        int pj = j & 1;
        int v = pref[j];
        ans += cnt[pj][v];
        ans += cnt[pj ^ 1][v ^ 1];
        cnt[pj][v]++;
    }
    cout << ans << endl;
    return 0;
}
