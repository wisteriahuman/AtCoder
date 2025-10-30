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
	ll N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	int maxA = 0;
	const int LIM = 1'000'000;
	vector<int> cnt(LIM + 1, 0);
	rep(i, N) {
		cin >> A[i];
		cnt[A[i]]++;
		maxA = max(maxA, A[i]);
	}
	vector<int> B(Q);
	int maxB = 0;
	rep(i, Q) {
		cin >> B[i];
		maxB = max(maxB, B[i]);
	}
	int L = max(maxA, maxB);
	vector<ll> S_cnt(L + 1, 0), S_sum(L + 1, 0);
	rep(i, L) {
		S_cnt[i + 1] = S_cnt[i] + cnt[i];
		S_sum[i + 1] = S_sum[i] + 1LL*i*cnt[i];
	}

	for (int b : B) {
		if (b > maxA) {
			cout << -1 << endl;
			continue;
		}
		int t = b - 1;
		ll s_t = 0;
		if (t >= 0) {
			ll sum_le = S_sum[t];
			ll cnt_le = S_cnt[t];
			s_t = sum_le + 1LL*t*(N - cnt_le);
		}
		ll ans = s_t + 1;
		if (ans < b) ans = b;
		cout << ans << endl;
	}
	return 0;
}
