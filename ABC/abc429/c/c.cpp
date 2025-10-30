#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using mint=modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s); i--)

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];

	vector<int> freq(N + 1);
	for(int a : A) freq[a]++;

	ll _total = (ll)N * (N - 1) * (N - 2) / 6;
	ll _same = 0;
	for (int v : freq) {
		_same += (ll)v * (v - 1) * (v - 2) / 6;
	}
	ll _diff = 0, _prefix = 0;
	for (int v : freq) {
		_diff += (ll)_prefix * v * (N - _prefix - v);
		_prefix += v;
	}
	
	cout << _total - _same - _diff << endl;

	return 0;
}
