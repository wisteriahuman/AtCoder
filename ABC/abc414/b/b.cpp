#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s), i--)

int main() {
	ll N;
	cin >> N;
	ll cnt = 0;
	vector<pair<char, ll>> data(N);
	for (int i = 0; i < N; i++) {
		cin >> data[i].first >> data[i].second;
		if (cnt > 100 - data[i].second || data[i].second > 100) {
			cout << "Too Long" << endl;
			return 0;
		}
		cnt += data[i].second;
	}
	if (cnt > 100) {
		cout << "Too Long" << endl;
		return 0;
	}
	string S = "";
	for (int i = 0; i < N; i++) {
		S += string(data[i].second, data[i].first);
	}
	cout << S << endl;

	return 0;
}
