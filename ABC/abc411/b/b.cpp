#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	ll N;
	cin >> N;
	vector<ll> D(N - 1);
	vector<ll> S(N, 0);
	rep(i, N - 1) {
		cin >> D[i];
		S[i + 1] = S[i] + D[i];
	}
	rep(i, N - 1) {
		rep2(j, i + 1, N) {
			cout << S[j] - S[i] << " \n"[j + 1 == N];
		}
	}

	return 0;
}
