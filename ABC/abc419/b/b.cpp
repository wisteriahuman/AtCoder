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
	vector<int> bag;
	int Q;
	cin >> Q;
	rep(_, Q) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			bag.push_back(x);
		} else if (t == 2) {
			sort(bag.begin(), bag.end());
			cout << bag[0] << endl;
			bag.erase(bag.begin());
		}
	}

	return 0;
}
