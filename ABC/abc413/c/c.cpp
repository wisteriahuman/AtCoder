#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;
    int t;
    queue<pair<int, int>> que;
    for (int i = 0; i < Q; i++) {
        cin >> t;
        if (t == 1) {
            int c, x;
            cin >> c >> x;
            que.push({x, c});
        } else {
            int k;
            cin >> k;
            ll ans = 0;
            while (k > 0) {
                auto [x, c] = que.front();
                if (c <= k) {
                    ans += (ll)x * c;
                    k -= c;
                    que.pop();
                } else {
                    ans += (ll)x * k;
                    que.front() = {x, c - k};
                    k = 0;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}