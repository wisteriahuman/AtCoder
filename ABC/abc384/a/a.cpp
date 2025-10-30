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
	char c1, c2;
	cin >> N >> c1 >> c2;
	string S;
	cin >> S;
	string ans = "";
	for (char c : S) {
		if (c == c1) {
			ans += c1;
		} else {
			ans += c2;
		}
	}
	cout << ans << endl;

	return 0;
}
