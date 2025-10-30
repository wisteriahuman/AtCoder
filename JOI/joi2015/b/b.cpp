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
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];

	vector<ll> B(2*N);
	rep(i, 2*N) B[i] = A[i % N];
	

	vector<vector<ll>> dp0(2*N, vector<ll>(2*N)), dp1(2*N, vector<ll>(2*N));
	
	for(int len = 1; len <= N; len++) for(int l = 0, r = l + len - 1; r < 2*N; l++, r++) {
		if (l == r) {
			dp0[l][r] = B[l];
			dp1[l][r] = 0;
		} else {
			dp0[l][r] = max(B[l] + dp1[l + 1][r], B[r] + dp1[l][r - 1]);
			dp1[l][r] = B[l] > B[r] ? dp0[l + 1][r] : dp0[l][r - 1];
		}
	}

	ll ans = 0;
	rep(i, N) ans = max(ans, B[i] + dp1[i + 1][i + N - 1]);
	cout << ans << endl;

	return 0;
}
