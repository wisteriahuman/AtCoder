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

	vector<vector<int>> g(N + 1);
	vector<char> learned(N + 1, false);
	queue<int> q;

	rep2(i, 1, N + 1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			learned[i] = true;
			q.push(i);
		} else {
			g[a].push_back(i);
			g[b].push_back(i);
		}
	}

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (!learned[v]) {
				learned[v] = true;
				q.push(v);
			}
		}
	}

	int ans = 0;
	rep2(i, 1, N + 1) if (learned[i]) ++ans;
	cout << ans << endl;


	return 0;
}
