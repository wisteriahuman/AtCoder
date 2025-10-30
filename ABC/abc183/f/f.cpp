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

class mdsu {
    vector<int> parent, rank;
    vector<unordered_map<int,int>> cnt;
public:
    mdsu(int n, const vector<int>& C) : parent(n), rank(n, 0), cnt(n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            cnt[i][C[i]] = 1;
        }
    }

    int leader(int x) {
        return parent[x] == x ? x : parent[x] = leader(parent[x]);
    }

    bool merge(int x, int y) {
        int rx = leader(x), ry = leader(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        if (cnt[rx].size() < cnt[ry].size()) cnt[rx].swap(cnt[ry]);
        for (auto &p : cnt[ry]) {
            cnt[rx][p.first] += p.second;
        }
        return true;
    }

    unordered_map<int,int>& get(int x) {
        return cnt[leader(x)];
    }
};

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> C(N);
	rep(i, N) {
		cin >> C[i];
		C[i]--;
	}

	mdsu muf(N, C);

	rep(i, Q) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			muf.merge(a, b);
		} else if (t == 2) {
			int x, y;
			x--; y--;
			auto &mp = muf.get(x);
			cout << (mp.count(y) ? mp.at(y) : 0) << endl;
		}
	}


	return 0;
}
