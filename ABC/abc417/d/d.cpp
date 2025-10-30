#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

static ll N;
static vector<ll> P, A, B;
static ll _size;
static ll P_max, A_max;
static vector<vector<ll>> bdp;
static vector<ll> SB;
static int cnt = 0;

void solve(int x) {
	int ans;
//	cout << ++cnt << ": " << "x:" << x << " ans:";
	if (x - SB[N] > _size) {
		ans = max(0LL, x - SB[N]);
	} else {
		ll need = x - _size;
		int idx = lower_bound(SB.begin(), SB.end(), need) - SB.begin();
		ll j = x - SB[idx];
		ans = bdp[idx][j];
	}
	cout << ans << endl;
}

int main() {
	cin >> N;
	P.resize(N);
	A.resize(N);
	B.resize(N);
	rep(i, N) cin >> P[i] >> A[i] >> B[i];
	ll P_max = *max_element(P.begin(), P.end());
	ll A_max = *max_element(A.begin(), A.end());
	_size = 3000;

	// i 番目までのプレゼントを受け取ったときテンションjのときの最終的なテンション
	bdp.assign(N + 1, vector<ll>(_size + 1));
	rep(j, _size + 1) bdp[N][j] = j;
	revp(i, N) rep(j, _size + 1) {
		ll nxt = ((j <= P[i]) ? min(_size, j + A[i]) : max(0LL, j - B[i]));
		bdp[i][j] = bdp[i + 1][nxt];
	}


	SB.assign(N + 1, 0);
	rep(i, N) SB[i + 1] = SB[i] + B[i];


	ll Q;
	cin >> Q;
	rep(i, Q) {
		ll x;
		cin >> x;
		solve(x);
	}

	return 0;
}
