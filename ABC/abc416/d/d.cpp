#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

void solve() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N), B(N);
	rep(i, N) cin >> A[i];
	rep(i, N) cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	multiset<int> st(A.begin(), A.end());

	ll ans = 0;
	for (int b : B) {
		auto it = st.lower_bound(M - b);
		if (it != st.end()) {
			ans += (ll)(*it + b - M);
			st.erase(it);
		} else {
			auto itb = st.begin();
			ans += (ll)(*itb + b);
			st.erase(itb);
		}
	}
	cout << ans << endl;

}

int main() {
	int T;
	cin >> T;
	rep(i, T) solve();

	return 0;
}
