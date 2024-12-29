#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> c;
vector<bool> visited;
vector<int> tour;

int findNearest(int k) {
    int nearest = -1;
    int minDist = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && c[k][i] < minDist) {
            minDist = c[k][i];
            nearest = i;
        }
    }
    return nearest;
}

void TRY(int k) {
    visited[k] = true;
    tour.push_back(k + 1);
    int nextCity = findNearest(k);

    if (tour.size() == n) {
        return;
    }

    TRY(nextCity);
}

void set_up() {
    cin >> n;
    c.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
}

int main() {
    set_up();

    TRY(0);

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << tour[i] << " ";
    }
    cout << endl;

    return 0;
}
