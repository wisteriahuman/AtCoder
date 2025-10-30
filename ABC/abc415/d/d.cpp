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
	ll N, M;
	cin >> N >> M;
	vector<pair<ll, ll>> ex(M);
	rep(i, M) {
		ll A, B;
		cin >> A >> B;
		ex[i] = {A, A - B};
	}
	sort(ex.begin(), ex.end());

	vector<pair<ll, ll>> dp(M);
	dp[0] = ex[0];
	rep2(i, 1, M) {
		pair<ll, ll> tmp = dp[i - 1];
		if (ex[i].second < tmp.second || (ex[i].second == tmp.second && ex[i].first < tmp.first)) {
			tmp = ex[i];
		}
		dp[i] = tmp;
	}

	ll minA = ex[0].first;
	ll S = 0, ans = 0;

	while (true) {
		ll avail = (ll)(N - S);
		if (avail < minA) break;

		ll left = 0, right = M - 1, idx = -1;
		while (left <= right) {
			ll mid = (left + right) / 2;
			if (ex[mid].first <= avail) {
				idx = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		if (idx == -1) break;

		auto cand = dp[idx];
		ll d = cand.second, Areq = cand.first;

		ll tmax = ((N - Areq) - S) / d + 1;
		S += tmax * d;
		ans += tmax;
	}
	cout << ans << endl;


	return 0;
}
