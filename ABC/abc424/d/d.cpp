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

void solve() {
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	rep(i, H) cin >> S[i];

	vector<int> row(H, 0);
	int total_black = 0;
	rep(i, H) {
		int m = 0;
		rep(j, W) {
			if (S[i][j] == '#') {
				m |= (1 << j);
				total_black++;
			}
		}
		row[i] = m;
	}

        int M = 1 << W;
        const int NEG = -1e9;
        vector<int> dp(M, NEG), ndp(M, NEG);

        rep(m, M) {
            if ((m & ~row[0]) == 0) {
                dp[m] = __builtin_popcount(m);
            }
        }

        auto ok = [&](int a, int b) -> bool {
            int aa = a & (a << 1);
            int bb = b & (b << 1);
            return (aa & bb) == 0;
        };

        rep2(i, 1, H) {
            fill(ndp.begin(), ndp.end(), NEG);
            rep(p, M) if (dp[p] > NEG) {
                rep(m, M) {
                    if ((m & ~row[i]) != 0) continue;
                    if (!ok(p, m)) continue;
                    ndp[m] = max(ndp[m], dp[p] + __builtin_popcount(m));
                }
            }
            dp.swap(ndp);
        }

        int keep_max = 0;
        rep(m, M) keep_max = max(keep_max, dp[m]);
        int ans = total_black - keep_max;
        cout << ans << endl;

}

int main() {
	int T;
	cin >> T;
	rep(i, T) {
	}

	return 0;
}
