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

struct pdsu {
	vector<int> parent, rank;
	vector<ll> diff_weight;

	pdsu(int n) : parent(n), rank(n, 0), diff_weight(n, 0) {
		rep(i, n) parent[i] = i;
	}

	int leader(int x) {
		if (parent[x] == x) return x;
		int r = leader(parent[x]);
		diff_weight[x] += diff_weight[parent[x]];
		return parent[x] = r;
	}

	ll weight(int x) {
		leader(x);
		return diff_weight[x];
	}

	bool merge(int x, int y, ll w) {
		w += weight(x);
		w -= weight(y);

		x = leader(x);
		y = leader(y);
		if (x == y) return diff(x, y) == w;

		if (rank[x] < rank[y]) {
			swap(x, y);
			w = -w;
		}

		parent[y] = x;
		diff_weight[y] = w;
		if (rank[x] == rank[y]) rank[x]++;
		return true;
	}

	bool same(int x, int y) {
		return leader(x) == leader(y);
	}

	ll diff(int x, int y) {
		return weight(y) - weight(x);
	}
};

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> ans;
	pdsu puf(N);
	rep(i, Q) {
		int a, b, d;
		cin >> a >> b >> d;
		a--; b--;
		if (puf.merge(b, a, d)) {
			ans.push_back(i + 1);
		}
	}
	rep(i, ans.size()) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}

	return 0;
}
