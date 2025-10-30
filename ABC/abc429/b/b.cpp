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
	vector<int> A(N);
	rep(i, N) cin >> A[i];

	vector<int> S(N + 1, 0);
	rep(i, N) S[i + 1] = A[i] + S[i];
	int _sum = S[N];
	bool isOk = false;
	rep(i, N) {
		int cnt = S[i] + _sum - S[i + 1];
		if (cnt == M) {
			isOk = true;
			break;
		}
	}

	cout << (isOk ? "Yes" : "No") << endl;

	return 0;
}
