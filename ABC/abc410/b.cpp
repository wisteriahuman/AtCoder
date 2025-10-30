#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> box(n + 1, 0);
    set<pair<int, int>> pq;

    for (int i = 1; i <= n; i++) {
        pq.insert({0, i});
    }

    rep(i, q) {
        int x;
        cin >> x;
        
        int ans;
        
        if (x >= 1) {
            ans = x;
            pq.erase({box[ans], ans});
            box[ans]++;
            pq.insert({box[ans], ans});
        } else {
            auto it = pq.begin();
            ans = it->second;
            pq.erase(it);
            box[ans]++;
            pq.insert({box[ans], ans});
        }
        cout << ans;
        if (i + 1 == q) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }

    return 0;
}
