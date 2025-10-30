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
	ll N;
	cin >> N;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	ll X;
	cin >> X;
	bool flag = false;
	for(ll a : A) {
		if (a == X) {
			flag = true;
			break;
		}
	}
	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}
