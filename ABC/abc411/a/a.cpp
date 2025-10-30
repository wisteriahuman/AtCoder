#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	string P;
	ll L;
	cin >> P;
	cin >> L;
	string ans = P.length() >= L ? "Yes" : "No";
	cout << ans << endl;

	return 0;
}
