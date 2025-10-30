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
	int H, W;
	cin >> H >> W;
	
	vector<string> A(H);
	rep(i, H) cin >> A[i];

	pair<int, int> S{-1, -1}, G{-1, -1};
	rep(i, H) rep(j, W) {
		if (A[i][j] =='S') S = {i, j};
		if (A[i][j] =='G') G = {i, j};
	}

	auto passable = [&](int i, int j, int p)->bool{
		char c = A[i][j];
		if (c == '#') return false;
		if (c == 'x') return p == 1;
		if (c == 'o') return p == 0;
		return true;
	};

	vector<vector<array<int, 2>>> dist(H, vector<array<int, 2>>(W, {-1, -1}));
	queue<tuple<int, int, int>> q;

	dist[S.first][S.second][0] = 0;
	q.emplace(S.first, S.second, 0);

	int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};

	while(!q.empty()) {
		auto [i, j, p] = q.front();
		q.pop();
		int now = dist[i][j][p];
		rep(idx, 4) {
			int ni = i + di[idx], nj = j + dj[idx];
			if (!(0 <= ni && ni < H && 0 <= nj && nj < W)) continue;
			if (!passable(ni, nj, p)) continue;
			int np = p ^ (A[ni][nj] == '?');
			if (dist[ni][nj][np] != -1) continue;
			dist[ni][nj][np] = now + 1;
			q.emplace(ni, nj, np);
		}
	}

	int a0 = dist[G.first][G.second][0];
	int a1 = dist[G.first][G.second][1];
	int ans = (a0 == -1 ? a1 : (a1 == -1 ? a0 : min(a0, a1)));

	cout << ans << endl;

	return 0;
}
