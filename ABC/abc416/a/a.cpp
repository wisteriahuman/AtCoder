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
	int N, L, R;
	cin >> N >> L >> R;
	string S;
	cin >> S;
	bool ok = true;
	rep2(i, L - 1, R) {
		if (S[i] != 'o') {
			ok = false;
		}
	}
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
