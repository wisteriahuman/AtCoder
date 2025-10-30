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

	dsu uf(N);
	vector<int> compBlack(N, 0);
	vector<int> isBlack(N, 0);

	rep(i, Q) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			int a = uf.leader(u);
			int b = uf.leader(v);
			if (a != b) {
				int sum = compBlack[a] + compBlack[b];
				int l = uf.merge(a, b);
				compBlack[l] = sum;
			}
		} else if (t == 2) {
			int v;
			cin >> v;
			v--;
			int l = uf.leader(v);
			if (!isBlack[v]) {
				isBlack[v] = 1;
				compBlack[l]++;
			} else {
				isBlack[v] = 0;
				compBlack[l]--;
			}
		} else if (t == 3) {
			int v;
			cin >> v;
			v--;
			int l = uf.leader(v);
			cout << (compBlack[l] > 0 ? "Yes" : "No") << endl;

		}
	}

	return 0;
}
