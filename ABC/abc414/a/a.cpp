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
	ll N, L, R;
	cin >> N >> L >> R;
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ll X, Y;
		cin >> X >> Y;
		if (X <= L && R <= Y) {
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}
