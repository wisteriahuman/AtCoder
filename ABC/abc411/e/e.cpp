#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s), i--)

#define MOD 998244353

int main() {
	ll N;
	cin >> N;
	vector<vector<ll>> A(N, vector<ll>(6));
	vector<ll> S;
	rep(i, N) rep(j, 6) {
		cin >> A[i][j];
		S.push_back(A[i][j]);
	}
	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());
	ll K = S.size();
	vector<vector<ll>> upd(K);
	rep(i, N) rep(j, 6) {
		ll id = lower_bound(S.begin(), S.end(), A[i][j]) - S.begin();
		upd[id].push_back(i);
	}

	mint ans = 0;
	vector<ll> B(N);
	mint prod = 1;
	ll zero_cnt = N;
	rep(i, K - 1) {
		for (int j : upd[i]) {
			if (!B[j]) {
				--zero_cnt;
			} else {
				prod /= B[j];
			}
			B[j]++;
			prod *= B[j];
		}
		ans -= (zero_cnt ? 0 : prod) * (S[i + 1] - S[i]);
	}
	ans /= mint(6).pow(N);
	ans += S[K - 1];
	cout << ans.val() << endl;

	return 0;
}
