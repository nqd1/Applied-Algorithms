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
int load = 0;
int f = 0;
int f_best = inf;
int route[MAX];
int cmin = inf;


void input(){
    cin >> n >> K;
    for(int i = 0; i <= 2*n; i++){
        for (int j = 0; j <= 2*n; j++){
            cin >> c[i][j];
            if (i != j) cmin = min(cmin, c[i][j]);
        }
    }
}
void update(){
    f_best = min(f_best, f + c[route[2 * n]][0]);
}

bool check(int v, int k){
    if (visited[v]) return false; //already went thru v, cant overlap
    if (v > n && !visited[v-n]) return false; //drop p at v (p from v-n) but havent pick up p yet
    if (v <= n && load + 1 > K) return false; //pickup p at v, but bus alrdy full
    return true;
}

void TRY(int k){ // k^th step in the route[2n]
    fi(1, 2*n + 1, 1){
        if (check(i, k)){
            route[k] = i;
            visited[i] = true;
            f += c[route[k-1]][route[k]];
            load += (i > n ? -1 : 1); // drop at i if i > n, else pick-up at i

            if (k == 2*n){
                //route's end reached
                update();
            }
            else if (f + cmin*(2*n+1 - k) < f_best) TRY(k+1);
            //total dist of (2n+1 - k) remaining points + current length (f) is no more than f_best

            //if shits didnt work out, backtrack
            visited[i] = false;
            f -= c[route[k-1]][route[k]];
            load -= (i > n? -1 : 1);
        }
    }
}



int main(){
    fast;
    input();

    route[0] = 0;
    TRY(1);

    cout << f_best << endl;
    return 0;

}
