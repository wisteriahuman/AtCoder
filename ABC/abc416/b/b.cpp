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
	string T = S;

	bool flag = false;
	rep(i, S.size()) {
		if (S[i] == '.') {
			if (!flag) {
				T[i] = 'o';
				flag = true;
			} else {
				T[i] = '.';
			}
		} else {
			T[i] = '#';
			flag = false;
		}
	}

	cout << T << endl;

	return 0;
}
