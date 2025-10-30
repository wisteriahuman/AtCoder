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
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	vector<int> B(N);
	rep(i, N) cin >> B[i];
	
	ll ans = 0;
	rep(i, N) {
		ans += min(A[i], B[i]);
	}

	rep(i, Q) {
		char c;
		int x, v;
		cin >> c >> x >> v;
		x--;

		ans -= min(A[x], B[x]);

		if (c == 'A') {
			A[x] = v;
		} else if (c == 'B') {
			B[x] = v;
		}

		ans += min(A[x], B[x]);

		cout << ans << endl;
	}

	return 0;
}
