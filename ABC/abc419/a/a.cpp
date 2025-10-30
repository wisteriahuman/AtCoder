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
	string S;
	cin >> S;

	if (S == "red") {
		cout << "SSS" << endl;
	} else if (S == "blue") {
		cout << "FFF" << endl;
	} else if (S == "green") {
		cout << "MMM" << endl;
	} else {
		cout << "Unknown" << endl;
	}

	return 0;
}
