
#include <bits/stdc++.h>
using namespace std;
using T = tuple<int,int,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, K;
    cin >> H >> W >> K;
    vector<pair<int,int>> goals(K);
    for(int idx = 0; idx < K; idx++){
        int r, c;
        cin >> r >> c;
        goals[idx] = {r - 1, c - 1};
    }

    const int INF = 1e9;
    vector<vector<int>> dist(H, vector<int>(W, INF));
    vector<vector<int>> small1(H, vector<int>(W, INF));
    vector<vector<int>> small2(H, vector<int>(W, INF));
    vector<vector<bool>> used(H, vector<bool>(W, false));

    priority_queue<T, vector<T>, greater<T>> hq;
    for(auto [i, j] : goals){
        dist[i][j] = 0;
        hq.emplace(0, i, j);
    }

    const vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    while(!hq.empty()){
        auto [cnt, i, j] = hq.top(); hq.pop();
        if(used[i][j] || dist[i][j] != cnt) continue;
        used[i][j] = true;

        for(auto [di, dj] : dirs){
            int ni = i + di, nj = j + dj;
            if(ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if(used[ni][nj]) continue;

            if(cnt < small1[ni][nj]){
                small2[ni][nj] = small1[ni][nj];
                small1[ni][nj] = cnt;
            }
            else if(cnt < small2[ni][nj]){
                small2[ni][nj] = cnt;
            }

            if(small2[ni][nj] < INF){
                int nd = small2[ni][nj] + 1;
                if(nd < dist[ni][nj]){
                    dist[ni][nj] = nd;
                    hq.emplace(nd, ni, nj);
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(dist[i][j] < INF) ans += dist[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}