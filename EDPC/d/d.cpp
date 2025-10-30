#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100
#define MAX_W 100000
#define max(a, b) (a) > (b) ? (a) : (b)

long long dp[MAX_N][MAX_W + 1];
long long weight[MAX_W + 1];
long long value[MAX_N];


long long knapsack(long long i, long long w) {
	if (i < -1) return 0;

	if (dp[i][w] != -1) return dp[i][w];
	
	if (w < weight[i]) {
		dp[i][w] = knapsack(i - 1, w);
	} else {
		dp[i][w] = max(knapsack(i - 1, w), knapsack(i - 1, w - weight[i]) + value[i]);
	}

	return dp[i][w];
}

int main() {
	long long N, W;
	cin >> N >> W;
	for (long long i = 0; i < N; i++) {
		cin >> weight[i] >> value[i];
	}
	long long ans = knapsack(N - 1, W);
	cout << ans << endl;
	return 0;
}
