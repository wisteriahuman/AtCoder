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
	int N;
	cin >> N;
	vector<int> R(N), C(N);
	rep(i, N) {
		cin >> R[i] >> C[i];
	}
	int dr = (*max_element(R.begin(), R.end()) - *min_element(R.begin(), R.end()) + 1) / 2;
	int dc = (*max_element(C.begin(), C.end()) - *min_element(C.begin(), C.end()) + 1) / 2;
	
	int ans = max(dr, dc);
	cout << ans << endl;

	return 0;
}
