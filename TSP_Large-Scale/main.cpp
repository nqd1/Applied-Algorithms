#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

const int MAX = 1000;
int n;
int dist[MAX][MAX];
vector<int> route, temp_route;
bool visited[MAX];
int curr_cost, best_cost = INT_MAX;

void input(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
}


void updateBest(){
    if (curr_cost + dist[temp_route.back()][temp_route[0]] < best_cost) {
        best_cost = curr_cost + dist[temp_route.back()][temp_route[0]];
        route = temp_route;
    }
}

void TRY(int k){
    for (int v = 0; v < n; ++v) {
        if (!visited[v]) {
            visited[v] = true;
            temp_route.push_back(v);
            curr_cost += dist[temp_route[k - 1]][v];

            if (k == n) {
                updateBest();
            }
            else if (curr_cost < best_cost) {
                TRY(k + 1);
            }

            visited[v] = false;
            temp_route.pop_back();
            curr_cost -= dist[temp_route[k - 1]][v];
        }
    }
}

void set_up(){
    fill(visited, visited + n, false);
    visited[0] = true;
    temp_route.push_back(0);
    curr_cost = 0;
    TRY(1);
}

int main() {
    fast;
    input();
    set_up();

    cout << n << '\n';
    for (int city : route) {
        cout << city + 1 << ' ';
    }

    return 0;
}
