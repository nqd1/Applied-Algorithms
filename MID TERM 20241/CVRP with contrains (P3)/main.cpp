#include <bits/stdc++.h>
using namespace std;
#define MAX 20
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define inf INT_MAX
#define ninf INT_MIN
#define fi(a, b, step) for (int i = a; i < b; i += step)

int n, K;
int c[MAX][MAX] = {0};
bool visited[MAX] = {false};
int s[MAX] = {0};
int load = 0;
int f = 0;
int f_best = inf;
int route[MAX];
int cmin = inf;
unordered_map<int, int> where_at_k;

void input() {
    cin >> n >> K;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {

            cin >> c[i][j];
            if (i != j) cmin = min(cmin, c[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) cin >> s[i];
}

void update() {
    f_best = min(f_best, f + c[route[2 * n]][0]);
}

bool check(int v, int k) {
    if (visited[v]) return false; // already went thru v
    if (v > n) {
        int start = where_at_k[v - n];
        if (!visited[v - n] || k - start > s[v - n]) return false; // not picked up or exceeded limit
    }
    if (v <= n && load + 1 > K) return false; // to pick up but bus full
    return true;
}

void TRY(int k) {
    fi(1, 2 * n + 1, 1) {
        if (check(i, k)) {
            route[k] = i;
            visited[i] = true;
            where_at_k[i] = k;
            f += c[route[k - 1]][route[k]];
            load += (i > n ? -1 : 1);

            if (k == 2 * n) {
                update();
            } else if (f + cmin * (2 * n + 1 - k) < f_best) {
                TRY(k + 1);
            }

            visited[i] = false;
            where_at_k.erase(i);
            f -= c[route[k - 1]][route[k]];
            load -= (i > n ? -1 : 1);
        }
    }
}

int main() {
    fast;
    input();

    route[0] = 0;
    TRY(1);

    cout << f_best << endl;
    return 0;
}
