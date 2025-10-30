#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s), i--)

vector<ll> gen_pal(ll N) {
	vector<ll> pals;
	for (int i = 1; i <= 12; i++) {
		ll start = i == 1 ? 0 : pow(10, (i - 1) / 2);
		ll end = pow(10, (i + 1) / 2);
		for (ll j = start; j < end; j++) {
			string s = to_string(j);
			string t = s;
			reverse(t.begin(), t.end());
			string pal;
			if (i % 2 == 0) pal = s + t;
			else pal = s + t.substr(1);
			ll x = stoll(pal);
			if (1 <= x && x <= N) pals.push_back(x);
		}
	}
	return pals;
}

bool is_pal(ll X, ll A) {
	vector<ll> digits;
	while (X > 0) {
		digits.push_back(X % A);
		X /= A;
	}
	int n = digits.size();
	for (int i = 0; i < n / 2; i++) {
		if (digits[i] != digits[n - i - 1]) return false;
	}
	return true;
}

int main() {
	int A;
	cin >> A;
	ll N;
	cin >> N;
	vector<ll> pals = gen_pal(N);
	ll ans = 0;
	for (ll p : pals) {
		if (is_pal(p, A)) ans += p;
	}
	cout << ans << endl;
	return 0;
}
