#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	ll N, M;
	cin >> N >> M;
	vector<ll> L(N);
	rep(i, N) {
		cin >> L[i];
		L[i]++;
	}

	ll left = ranges::max(L) - 1;
	ll right = reduce(begin(L), end(L));
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;
		ll now = 1;
		ll cnt = 0;
		rep(i, N) {
			cnt += L[i];
			if (cnt > mid) {
				now++;
				cnt = L[i];
			}
		}

		if (now > M) {
			left = mid;
		} else {
			right = mid;
		}
	}

	cout << right - 1 << endl;

	return 0;
}
