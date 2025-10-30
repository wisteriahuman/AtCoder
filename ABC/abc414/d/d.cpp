#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s), i--)

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> X(N);
	rep(i, N) cin >> X[i];
	sort(X.begin(), X.end());
	vector<ll> diff(N - 1);
	rep(i, N - 1) diff[i] = X[i + 1] - X[i];
	sort(diff.begin(), diff.end());
	ll ans = reduce(diff.begin(), diff.end() - M + 1);
	cout << ans << endl;

	return 0;
}
