#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	sort(B.begin(), B.end());
	int ans = INT_MAX;
	for (int a : A) {
		vector<int>::iterator it = lower_bound(B.begin(), B.end(), a);
		ans = min(ans, abs(*it - a));
		if (B.begin() != it) {
			ans = min(ans, abs(*prev(it) - a));
		}
	}
	cout << ans << endl;
	return 0;
}
