#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> edges(N + 1);
    for (int i = 0; i < M; i++) {
        int A, B, W;
        cin >> A >> B >> W;
        edges[A].push_back({B, W});
    }

    static bool visited[1001][1024];
    queue<pair<int, int>> q;
    visited[1][0] = true;
    q.push({1, 0});

    while (!q.empty()) {
        auto [u, x] = q.front();
        q.pop();
        for (auto &e : edges[u]) {
            int v = e.first, w = e.second;
            int nx = x ^ w;
            if (!visited[v][nx]) {
                visited[v][nx] = true;
                q.push({v, nx});
            }
        }
    }

    for (int x = 0; x < 1024; x++) {
        if (visited[N][x]) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}