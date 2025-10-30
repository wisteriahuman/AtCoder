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
	ll N, S;
	cin >> N >> S;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	vector<ll> AS(N + 1, 0);
	rep(i, N) AS[i + 1] = A[i] + AS[i];
	S %= AS[N];
	bool flag = false;
	rep(left, N) {
		ll sum = 0;
		ll right = left;
		while (right < N && sum + A[right] <= S) {
			sum += A[right];
			right++;
		}
		if (sum == S) {
			flag = true;
			break;
		}
	}
	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}
