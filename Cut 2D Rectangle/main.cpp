#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define MAX 11


int H, W, n;
int h[MAX], w[MAX], x[MAX], y[MAX], o[MAX]; // piece with   (size,  top_left_coord, orientation) =
                                            //              ((w,h),     (x,y),      (90 or 0)  )
bool marked[MAX][MAX] = {false};

void input(){
    cin >> H >> W >> n;
    for (int i = 0; i < n; i++){
        cin >> h[i] >> w[i];
    }
}

bool check(int vx, int vy, int vo, int k){
    int wk = w[k];
    int hk = h[k];

    if (vo == 1) swap(hk, wk);

    if (vx + wk > W || vy + hk > H) return false;

    for (int i = vx; i < vx + wk; i++){
        for (int j = vy; j < vy + hk; j++){
            if (marked[i][j]) return false;
        }
    }
    return true;
}

void marking(int vx, int vy, int vo, int k, bool MarkAs){
    int wk = w[k], hk = h[k];
    if (vo == 1) swap(wk, hk);

    for (int i = vx; i < vx + wk; i++){
        for (int j = vy; j < vy + hk; j++){
            marked[i][j] = MarkAs;
        }
    }
}

void Try(int k){
    if (k == n){
        cout << "1" << endl;
        exit(0);
    }

    for (int vo = 0; vo <= 1; vo++){
        for (int vx = 0; vx < W; vx++){
            for (int vy = 0; vy < H; vy++){
                if(check(vx,vy,vo,k)){
                    x[k] = vx;
                    y[k] = vy;
                    marking(vx, vy, vo, k, true);

                    Try(k+1);

                    marking(vx, vy, vo, k, false);
                }
            }
        }
    }
}

int main(){
    fast;
    input();

    Try(0);

    cout << "0" << endl;
    return 0;
}
