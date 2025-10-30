#include <bits/stdc++.h>
using namespace std;
using ll=long long;


ll amount(ll d) {
	return d * (d + 1) / 2;
}


int main() {
	ll N;
	cin >> N;
	ll left = -1, right = N;
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;
		if (N > amount(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	cout << right << endl;
	return 0;
}
