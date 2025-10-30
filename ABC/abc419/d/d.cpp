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
	string S;
	cin >> S;
	string T;
	cin >> T;
	
	vector<int> pref_sum(N + 1, 0);
	rep(i, M) {
		int l, r;
		cin >> l >> r;
		pref_sum[l - 1]++;
		pref_sum[r]--;
	}
	rep(i, N) {
		pref_sum[i + 1] += pref_sum[i];
		cout << (pref_sum[i] % 2 == 0 ? S[i] : T[i]);
	}
	cout << endl;

	return 0;
}
