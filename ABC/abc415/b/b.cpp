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
	int cnt = 0;
	int N = S.length();
	rep(i, N) {
		if (S[i] == '.') continue;
		if (cnt == 0) {
			cout << i + 1 << ",";
			cnt++;
		} else if (cnt == 1) {
			cout << i + 1 << endl;
			cnt = 0;
		}
	}

	return 0;
}
