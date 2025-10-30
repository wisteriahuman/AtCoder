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
	vector<vector<int>> g(N);
	rep(i, M) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	string S;
	cin >> S;

	const int INF = 1e9;

	vector<array<int, 2>> dist(N, {INF, INF});
	vector<array<int, 2>> src_id(N, {-1, -1});

	using T = tuple<int, int, int>;
	priority_queue<T, vector<T>, greater<T>> pq;

	rep(s, N) {
		if (S[s] == 'S') {
			dist[s][0] = 0;
			src_id[s][0] = s;
			pq.emplace(0, s, s);
		}
	}

	auto get_now_for_src = [&](int v, int src) -> int {
		if (src_id[v][0] == src) return dist[v][0];
		if (src_id[v][1] == src) return dist[v][1];
		return INF;
	};

	auto try_update = [&](int v, int src, int d) -> bool {
		bool updated = false;
		if (src_id[v][0] == src) {
			if (d < dist[v][0]) { dist[v][0] = d; updated = true; }
		} else if (src_id[v][1] == src) {
			if (d < dist[v][1]) { dist[v][1] = d; updated = true; }
		} else if (src_id[v][0] == -1) {
			src_id[v][0] = src; dist[v][0] = d; updated = true;
		} else if (src_id[v][1] == -1) {
			src_id[v][1] = src; dist[v][1] = d; updated = true;
		} else {
			if (d < dist[v][1]) {
				src_id[v][1] = src; dist[v][1] = d; updated = true;
			}
		}

		if (dist[v][0] > dist[v][1]) {
			swap(dist[v][0], dist[v][1]);
			swap(src_id[v][0], src_id[v][1]);
		}
		return updated;
	};

	while (!pq.empty()) {
		auto [d, v, ssrc] = pq.top(); pq.pop();
		if (d != get_now_for_src(v, ssrc)) continue;

		for (int to : g[v]) {
			int nd = d + 1;
			int now_same = get_now_for_src(to, ssrc);
			int worst = dist[to][1];
			if (now_same <= nd) continue;
			if (worst <= nd) continue;
			if (try_update(to, ssrc, nd)) {
				pq.emplace(nd, to, ssrc);
			}
		}

	}

	rep(i, N) {
		if (S[i] == 'D') {
			ll ans = dist[i][0] + dist[i][1];
			cout << ans << endl;
		}
	}

	return 0;
}
