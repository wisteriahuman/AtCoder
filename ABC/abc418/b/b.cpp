#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

int main() {
	string S;
	cin >> S;
	double ans = 0;
	if (S.size() < 3) {
		cout << ans << endl;
		return 0;
	}
	vector<int> St(S.size() + 1, 0);
	rep(i, S.size()) {
		if (S[i] == 't') {
			St[i + 1] = 1 + St[i];
		} else {
			St[i + 1] = St[i];
		}
	}
	
	rep(i, S.size() - 2) {
		rep2(j, i + 2, S.size()) {
			if (!(S[i] == 't' && S[j] == 't')) continue;
			int x = St[j + 1] - St[i];
			double score = (double)(x - 2) / (double)(j - i + 1 - 2);
			if (ans < score) ans = score;
		}
	}
	cout << fixed << setprecision(17) << ans << endl;

	return 0;
}
