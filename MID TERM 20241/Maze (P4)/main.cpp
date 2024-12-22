#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int n, a, b;
vector<vector<int>> mat, dp;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
void input() {
    cin >> n >> a >> b;
    mat.assign(n + 1, vector<int>(n + 1));
    dp.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
}

void solve() {
    if (mat[1][1] == 1 || mat[a][b] == 1) {
        cout << 0;
        return;
    }

    queue<pair<int, int>> q;
    dp[1][1] = 1;
    q.push({1, 1});

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int k = 0; k < 2; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx <= n && ny <= n && mat[nx][ny] == 0) {
                if (dp[nx][ny] == 0) q.push({nx, ny});
                dp[nx][ny] += dp[x][y];
            }
        }
    }

    cout << dp[a][b];
}

int main() {
    fast;
    input();
    solve();
    return 0;
}
