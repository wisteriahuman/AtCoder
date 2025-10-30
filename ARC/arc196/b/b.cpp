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


ll modpow(ll a, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}


void solve() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	rep(i, H) cin >> S[i];

	vector<int> row_a_cnt(H, 0);
	vector<int> col_a_cnt(W, 0);
	vector<vector<int>> row_sa(H, vector<int>(W + 1, 0));
	vector<vector<int>> col_sa(W, vector<int>(H + 1, 0));
	rep(i, H) rep(j, W) {
		int d = 0;
		if (S[i][j] == 'A') {
			row_a_cnt[i]++;
			col_a_cnt[j]++;
			d = 1;
		}
		row_sa[i][j + 1] = row_sa[i][j] ^ d;
		col_sa[j][i + 1] = col_sa[j][i] ^ d;
	}
	bool flag = true;
	rep(i, H) {
		if (row_a_cnt[i] % 2 != 0) {
			flag = false;
			break;
		}
	}
	if (flag) rep(j, W) {
		if (col_a_cnt[j] % 2 != 0) {
			flag = false;
			break;
		}
	}
	if (!flag) {
		cout << 0 << endl;
		return;
	}
	rep(i, H) {
	
	}
	int N = H + W;
	dsu G(N * 2);
	rep(i, H) rep(j, W) {
		if (S[i][j] == 'B') {
			int C = 1 ^ row_sa[i][j] ^ col_sa[j][i];
			if (C == 1) {
				G.merge(i, H + j + N);
				G.merge(i + N, H + j);
			} else {
				G.merge(i, H + j);
				G.merge(i + N, H + j + N);
			}
		}
	}
	

	rep(v, N) {
		if (G.same(v, v + N)) {
			flag = false;
			break;
		}
	}
	if (!flag) {
		cout << 0 << endl;
		return;
	}

	cout << modpow(2, G.groups().size() / 2, 998244353) << endl;

}


int main() {
	int T;
	cin >> T;
	rep(i, T) solve();

	return 0;
}
