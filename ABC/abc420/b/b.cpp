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
	vector<string> S(N);
	rep(i, N) cin >> S[i];
	vector<int> people(N, 0);
	rep(i, M) {
		int cnt0 = 0, cnt1 = 0;
		rep(j, N) {
			if (S[j][i] == '1') {
				cnt1++;
			} else if (S[j][i] == '0') {
				cnt0++;
			}
		}
		bool is0 = cnt0 < cnt1;
		rep(j, N) {
			if (is0) {
				if (S[j][i] == '0') {
					people[j]++;
				}
			} else {
				if (S[j][i] == '1') {
					people[j]++;
				}
			}
		}
	}
	int _max = *max_element(people.begin(), people.end());
	vector<int> ans;
	rep(i, N) {
		if (_max == people[i]) {
			ans.push_back(i + 1);
		}
	}

	rep(i, ans.size()) {
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}

	return 0;
}
