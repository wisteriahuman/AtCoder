#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> A(M);
	rep(i, N) cin >> A[i];
	sort(A.begin(), A.end());
	rep2(i, 1, N + 1) {
		auto it = lower_bound(A.begin(), A.end(), i);
		cout << *it - i << endl;
	}

	return 0;
}
