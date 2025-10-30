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
	ll N;
	cin >> N;
	mint ans = 0;
	ans += mint(N) * mint(N + 1) / 2;
	ll b = 1;
	while (b <= N) {
		ll k = N / b;
		ll next_b = N / k + 1;
		ans -= mint(k) * mint(next_b - b);
		b = next_b;
	}

	cout << ans.val() << endl;

	return 0;
}
