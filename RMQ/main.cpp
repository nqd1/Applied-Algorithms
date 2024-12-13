//C++
#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define inf INT_MAX
#define fast ios::sync_with_stdio(false);cin.tie(nullptr)

int st[4*MAX];
int n, m;
int arr[MAX];
vector<pair<int,int>> ij;
int q = 0;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;
    ij.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> ij[i].first >> ij[i].second;
    }
}

void buildST(int id, int left, int right){
    if (left == right){
        st[id] = arr[left];
        return;
    }

    int mid = (left + right)/2;
    buildST(2*id, left, mid);
    buildST(2*id + 1, mid + 1, right);

    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int query(int id, int l, int r, int ql, int qr){
    if (l > qr || r < ql) return inf;
    if (l >= ql && r <= qr) return st[id];
    int mid = (l + r) / 2;
    return min(query(2*id, l, mid, ql, qr), query(2 * id + 1, mid + 1, r, ql, qr));
}

int main(){
    fast;
    input();
    buildST(1, 0, n-1);
    for (auto &p : ij){
        q += query(1, 0, n-1, p.first, p.second);
    }
    cout << q << endl;
}
