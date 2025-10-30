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

int main() {
	ll N, M, C;
	cin >> N >> M >> C;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	sort(A.begin(), A.end());

	vector<pair<ll, int>> P;
	for (auto x : A) {
		if (P.empty() || P.back().first != x) {
			P.push_back({x, 1});
		} else {
			P.back().second++;
		}
	}
	int K = P.size();
	rep(i, K) P.push_back({P[i].first + M, P[i].second});

	ll ans = 0;
	ll sum = 0;
	int r = 0;

	rep(l, K) {
		while (r < (int)P.size() && sum < C) {
			sum += P[r].second;
			r++;
		}
		if (sum < C) break;

		ll width;
		if (l == 0) {
			width = M - P[K - 1].first + P[0].first;
		} else {
			width = P[l].first - P[l - 1].first;
		}
		

		ans += width * sum;
		sum -= P[l].second;
	}

	cout << ans << endl;

	return 0;
}
