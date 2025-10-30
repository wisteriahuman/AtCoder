#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(K);
	vector<bool> have(N, false);
	for (int i = 0; i < K; i++) {
		cin >> A[i];
		have[A[i] - 1] = true;
	}

	vector<pair<ll, ll>> have_p;
	vector<pair<ll, ll>> not_have_p;
	for (int i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		if (have[i]) {
			have_p.push_back({x, y});
		} else {
			not_have_p.push_back({x, y});
		}
	}

	ll ans = 0;
	for (pair<ll, ll> nhp : not_have_p) {
		ll cnt = numeric_limits<ll>::max();
		for (pair<ll, ll> hp : have_p) {
			ll hx, hy, nhx, nhy;
			tie(hx, hy) = hp;
			tie(nhx, nhy) = nhp;
			ll tmp = pow(hx - nhx, 2) + pow(hy - nhy, 2);
			if (tmp < cnt) {
				cnt = tmp;
			}
		}
		if (cnt > ans) {
			ans = cnt;
		}
	}
	printf("%.12lf\n", sqrt((double)ans));
	
	return 0;
}
