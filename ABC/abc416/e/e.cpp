#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

const ll INF = 1LL << 60;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<ll>> dist(N, vector<ll>(N, INF));
	rep(i, N) dist[i][i] = 0;

	rep(i, M) {
		int u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		dist[u][v] = min(dist[u][v], (ll)c);
		dist[v][u] = min(dist[v][u], (ll)c);
	}

	int K, T;
	cin >> K >> T;
	vector<bool> hasAP(N, false);
	vector<int> AP;
	rep(i, K) {
		int d;
		cin >> d;
		d--;
		hasAP[d] = true;
		AP.push_back(d);
	}
	
	rep(i, AP.size()) rep(j, AP.size()) {
		if (i == j) continue;
		int u = AP[i], v = AP[j];
		dist[u][v] = min(dist[u][v], (ll)T);
	}

	rep(k, N) rep(i, N) rep(j, N) {
		if (dist[i][k] + dist[k][j] < dist[i][j]) {
			dist[i][j] = dist[i][k] + dist[k][j];
		}
	}


	int Q;
	cin >> Q;
	rep(query, Q) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, y, t;
			cin >> x >> y >> t;
			x--; y--;
			if (t < dist[x][y]) {
				dist[x][y] = min(dist[x][y], (ll)t);
				dist[y][x] = min(dist[y][x], (ll)t);
				rep(i, N) rep(j, N) {
					ll cand = dist[i][x] + t + dist[y][j];
					if (cand < dist[i][j]) dist[i][j] = cand;
					cand = dist[i][y] + t + dist[x][j];
					if (cand < dist[i][j]) dist[i][j] = cand;
				}
			}
		} else if (type == 2) {
			int x;
			cin >> x;
			x--;
			if (hasAP[x]) continue;
			hasAP[x] = true;
			rep(i, N) {
				if (hasAP[i]) {
					dist[i][x] = min(dist[i][x], (ll)T);
					dist[x][i] = min(dist[x][i], (ll)T);
				}
			}
			rep(i, N) {
				ll best = INF;
				rep(j, N) {
					if (hasAP[j]) {
						best = min(best, dist[i][j]);
					}
				}
				dist[i][x] = min(dist[i][x], best + T);
			}
			rep(i, N) {
				ll best = INF;
				rep(j, N) {
					if (hasAP[j]) {
						best = min(best, dist[j][i]);
					}
				}
				dist[x][i] = min(dist[x][i], best + T);
			}
			rep(i, N) rep(j, N) {
				ll cand = dist[i][x] + dist[x][j];
				if (cand < dist[i][j]) dist[i][j] = cand;
			}
		} else if (type == 3) {
			ll sum = 0;
			rep(i, N) rep(j, N) {
				if (dist[i][j] < INF) {
					sum += dist[i][j];
				}
			}
			cout << sum << endl;
		}
	}

	return 0;
}
