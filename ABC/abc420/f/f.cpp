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
	int N, M, K;
	cin >> N >> M >> K;
	vector<string> S(N);
	rep(i, N) cin >> S[i];

	vector<int> h(M, 0);
	ll ans = 0;
	
	vector<int> prevLess(M), nextLessEq(M);
	vector<int> st;
	st.reserve(M);

	rep(i, N) {
		rep(j, M) {
			if (S[i][j] == '.') {
				h[j]++;
			}	else {
				h[j] = 0;
			}
		}

		st.clear();
		for (int j = M - 1; j >= 0; j--) {
			while(!st.empty() && h[st.back()] > h[j]) st.pop_back();
			nextLessEq[j] = st.empty() ? M : st.back();
			st.push_back(j);
		}

		st.clear();
		rep(j, M) {
			while(!st.empty() && h[st.back()] >= h[j]) st.pop_back();
			prevLess[j] = st.empty() ? -1 : st.back();
			st.push_back(j);
		}

		rep(j, M) {
			int hj = h[j];
			if (hj == 0) continue;
			ll W = K / hj;
			if (W <= 0) continue;
			ll T = W + 1;
			ll L = j - prevLess[j];
			ll R = nextLessEq[j] - j;

			ll a_max = min(L, T - 1);
			if (a_max <= 0) continue;

			ll c = T - R;
			if (c < 0) c = 0;
			if (c > a_max) c = a_max;

			ll S1 = c * R;
			ll rem = a_max - c;
			ll S2 = rem * T - ((a_max + c + 1) * rem) / 2;

			ans += S1 + S2;
		}
	}

	cout << ans << endl;

	return 0;
}
