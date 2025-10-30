#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll=long long;
using mint=atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define revp(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define revp2(i, s, n) for (int i = (int)(n - 1); i >= (int)(s), i--)

int main() {
	vector<ll> data(5);
	rep(i, 5) cin >> data[i];
	vector<pair<ll, string>> users;
	rep(i, (1 << 5)) {
		string user_name = "";
		ll user_score = 0;
		rep(j, 5) {
			if ((i >> j) & 1) {
				user_name += 'A' + j;
				user_score += data[j];
			}
		}
		if (user_name == "") continue;
		users.push_back(make_pair(-1 * user_score, user_name));
	}

	sort(users.begin(), users.end());

	for (auto user : users) {
		cout << user.second << endl;
	}


	return 0;
}
