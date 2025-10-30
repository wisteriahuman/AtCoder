#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];    
    }
    cin >> k;
    int cnt = 0;
    for (auto v : a) {
        if (k <= v) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
