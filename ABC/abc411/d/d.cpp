#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)


int main() {
	ll N, Q;
	cin >> N >> Q;
	vector<ll> op(Q), p(Q);
	vector<string> s(Q);
	rep(i, Q) {
		cin >> op[i] >> p[i];
		if (op[i] == 2) {
			cin >> s[i];
			reverse(s[i].begin(), s[i].end());
		}
	}

	string ans = "";
	int i = 0;
	revp(t, Q) {
		if (op[t] == 1) {
			if (i == p[t]) {
				i = 0;
			}
		} else if (op[t] == 2) {
			if (i == p[t]) {
				ans += s[t];
			}
		} else {
			if (i == 0) {
				i = p[t];
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	return 0;
}
