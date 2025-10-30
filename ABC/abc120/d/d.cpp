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
	int N, M;
	cin >> N >> M;
	vector<int> A(M), B(M);
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		A[i] = --a;
		B[i] = --b;
	}
	dsu uf(N);
	vector<ll> ans(M);
	ll _cnt = 1LL * N * (N - 1) / 2;
	revp(i, M) {
		ans[i] = _cnt;
		int a = A[i], b = B[i];
		int size_a = uf.size(a);
		int size_b = uf.size(b);
		if (!uf.same(a, b)) {
			_cnt -= 1LL * size_a * size_b;
		}
		uf.merge(a, b);
	}
	rep(i, M) cout << ans[i] << endl;


	return 0;
}
