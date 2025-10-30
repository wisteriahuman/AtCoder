#include <bits/stdc++.h>
using namespace std;

int main() {
	int D, N;
	cin >> D;
	cin >> N;
	vector<int> data(D, 0);
	int L, R;
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		L--;
		R;
		data[L]++;
		if (R < D) {
			data[R]--;
		}
	}
	int ans = 0;
	for (int d : data) {
		ans += d;
		cout << ans << endl;
	}
	return 0;
}
