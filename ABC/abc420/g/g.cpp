#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

int main() {
    ll X;
    cin >> X;
    ll D = 4 * X - 1;
    ll AD = D >= 0 ? D : -D;
    vector<ll> ans;

    for (ll i = 1; i * i <= AD; i++) {
        if (AD % i != 0) continue;
        ll d2 = AD / i;
        array<pair<ll, ll>, 2> ps =
            D > 0 ? array<pair<ll, ll>, 2>{{{i, d2}, {-i, -d2}}}
                  : array<pair<ll, ll>, 2>{{{i, -d2}, {-i, d2}}};

        for (auto [p, q] : ps) {
            if ((p & 1) == 0 || (q & 1) == 0) continue;
            if (((p + q) & 3) != 0) continue;
            if (((q - p) & 3) != 2) continue;
            ll m = (q - p) / 2;
            if ((m & 1) == 0) continue;
            ll n = (m - 1) / 2;
            ans.push_back(n);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << endl;
    rep(i, ans.size()) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}

    return 0;
}
