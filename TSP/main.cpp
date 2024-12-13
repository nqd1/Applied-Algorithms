#include <bits/stdc++.h>
#define MAX 20

using namespace std;

int dist[MAX][MAX];
int n;
int sol = INT_MAX;
int visited[MAX] = {0};
vector<int> path, best_path;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
}

void tsp(int current, int count, int length) {
    if (length > sol) return;

    if (count == n) {
        length += dist[current][0];
        if (length < sol) {
            sol = length;
            best_path = path;
        }
        return;
    }

    for (int next = 1; next < n; next++) {
        if (!visited[next]) {
            visited[next] = 1;
            path.push_back(next);

            tsp(next, count + 1, length + dist[current][next]);

            visited[next] = 0;
            path.pop_back();
        }
    }
}

int main() {
    input();
    path.push_back(0);
    visited[0] = 1;

    tsp(0, 1, 0);

    cout << sol << endl;
    return 0;
}
