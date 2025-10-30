#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < Q; i++) {
		int x;
		cin >> x;
		cout << A.end() - lower_bound(A.begin(), A.end(), x) << endl;
	}
	return 0;
}
