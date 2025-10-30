#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

bool isAns(vector<ll> A, ll K, ll score, ll L) {
	ll cnt = 0;
	ll tmp = 0;
	for (ll a : A) {
		if (a - tmp >= score) {
			cnt++;
			tmp = a;
		}
	}
	if (L - tmp >= score) cnt++;
	return cnt >= K + 1;
}

ll binary_search(vector<ll> A, ll L, ll K) {
	ll left = 0, right = L + 1;
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;
		if (isAns(A, K, mid, L)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left;
}


int main() {
	ll N, L;
	cin >> N >> L;
	ll K;
	cin >> K;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	ll ans = binary_search(A, L, K);
	cout << ans << endl;
	return 0;
}
