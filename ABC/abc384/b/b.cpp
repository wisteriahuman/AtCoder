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
	ll N, R;
	cin >> N >> R;
	rep(i, N) {
		ll D, A;
		cin >> D >> A;
		if (D == 1 && 1600 <= R && R <= 2799) {
			R += A;
		} else if (D == 2 && 1200 <= R && R <= 2399) {
			R += A;
		}
	}
	cout << R << endl;

	return 0;
}
