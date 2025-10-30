#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define INF 1e15

bool isOK(ll x, vector<ll> H, vector<ll> S, ll N) {
	vector<ll> time(N, 0);
	rep(i, N) {
		if (x < H[i]) {
			return false;
		} else {
			time[i] = (x - H[i]) / S[i];
		}
	}

	sort(time.begin(), time.end());
	rep(i, N) {
		if (time[i] < i) return false;
	}

	return true;
}


int main() {
	ll N;
	cin >> N;
	vector<ll> H(N), S(N);
	rep(i, N) {
		cin >> H[i] >> S[i];
	}
	ll left = 0, right = INF;
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;
		if (isOK(mid, H, S, N)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	cout << right << endl;

	return 0;
}
