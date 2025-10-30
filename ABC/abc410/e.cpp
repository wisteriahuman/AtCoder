#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H, M;
    cin >> N >> H >> M;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> dpCur(H + 1, -1), dpNext(H + 1, -1);
    dpCur[H] = M;

    int answer = 0;
    for (int i = 0; i < N; i++) {
        bool possible = false;
        fill(dpNext.begin(), dpNext.end(), -1);

        for (int hp = 0; hp <= H; hp++) {
            int mp = dpCur[hp];
            if (mp < 0) continue;

            if (hp >= A[i]) {
                dpNext[hp - A[i]] = max(dpNext[hp - A[i]], mp);
                possible = true;
            }
            if (mp >= B[i]) {
                dpNext[hp] = max(dpNext[hp], mp - B[i]);
                possible = true;
            }
        }

        if (!possible) {
            break;
        }

        answer = i + 1;
        dpCur.swap(dpNext);
    }

    cout << answer << endl;
    return 0;
}