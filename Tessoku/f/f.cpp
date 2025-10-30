#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> A(N);
	vector<int> S(N + 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		S[i + 1] = A[i] + S[i];
	}
	int L, R;
	for (int i = 0; i < Q; i++) {
		cin >> L >> R;
		cout << S[R] - S[L - 1] << endl;
	}

	return 0;
}
