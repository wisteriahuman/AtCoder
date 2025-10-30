#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	ll N, Q;
	cin >> N >> Q;
	vector<bool> mass(N, false);
	ll ans = 0;
	rep(i, Q) {
		ll A;
		cin >> A;
		A--;
		bool left_black = A > 0 ? mass[A - 1] : false;
		bool right_black = A < N - 1 ? mass[A + 1] : false;
		
		if (mass[A]) {
			if (left_black and right_black) {
				ans++;
			} else if (left_black or right_black) {
			} else {
				ans--;
			}
		} else {
			if (left_black and right_black) {
				ans--;
			} else if (left_black or right_black) {
			} else {
				ans++;
			}
		}
		mass[A] = !mass[A];
		cout << ans << endl;
	}

	return 0;
}
