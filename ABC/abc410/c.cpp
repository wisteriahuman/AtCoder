#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) a[i] = i + 1;

    int offset = 0;

    rep(i, q) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            int idx = (p + offset) % n;
            a[idx] = x;
        } else if (type == 2) {
            int p;
            cin >> p;
            p--;
            int idx = (p + offset) % n;
            cout << a[idx] << endl;
        } else if (type == 3) {
            int k;
            cin >> k;
            offset = (offset + k) % n;
        }
    }

    return 0;
}
