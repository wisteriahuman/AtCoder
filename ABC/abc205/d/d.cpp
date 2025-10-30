#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	ll N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	vector<ll> C(N, 0);
	rep(i, N) {
		cin >> A[i];
		C[i] = A[i] - (i + 1);
	}
	ll K;
	rep(i, Q) {
		cin >> K;
		ll idx = lower_bound(C.begin(), C.end(), K) - C.begin();
		if (idx == N) {
			cout << A[N - 1] + (K - C[N - 1]) << endl;
		} else {
			cout << (A[idx] - 1) - (C[idx] - K) << endl;
		}
	}

	return 0;
}
