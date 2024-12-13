#include<bits/stdc++.h>
using namespace std;

#define MAX 1000000
#define ninf INT_MIN
#define inf INT_MAX
#define fi(a, b) for(int i = a; i < b; i++)

int st[4*MAX], arr[MAX];
vector<tuple<string, int,int>> q;
int n, m;


void input(){
    cin >> n;
    fi(0, n){
        cin >> arr[i];
    }

    cin >> m;
    q.resize(m);
    for(int i = 0; i < m; i++) {
        string op;
        int x, y;
        cin >> op >> x >> y;
        q[i] = {op, x - 1, y - 1};
    }
}

void build(int id, int l, int r){
    // node id = max (from l to r)
    if (l == r){// l == r  then node is leaf => leaf = arr's element
        st[id] = arr[l];
        return;
    }
    int mid = (l + r)/2;

    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);

    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int query(int id, int l, int r, int ql, int qr){
    //node id = max(from l to r)
    //find max (from ql to qr)
    //ex: query(1, 0, n-1, Q.l, Q.r)
    if (qr < l || r < ql) return ninf; // [ql,qr] does not intersect(?) with [l,r]
    if (ql <= l && r <= qr) return st[id]; // [l, r] is completely in [ql, qr]

    int mid = (l + r)/2;
    return max( query(2 * id,       l,          mid,    ql, qr), //left child
                query(2 * id + 1,   mid + 1,    r,      ql, qr));//right child
}

void update(int id, int l, int r, int i, int v){
    if (l == r){
        st[id] = v;
        return;
    }
    if (i < l || r < i) return;

    int mid = (l + r)/2;
    update(2*id, l, mid, i, v);
    update(2*id + 1, mid + 1, r, i, v);

    st[id] = max(st[2*id], st[2*id  + 1]);
}

int main(){
    input();
    build(1, 0, n-1);
    for (auto &t : q){
        if (get<0>(t) == "get-max"){
            cout << query(1, 0, n-1, get<1>(t), get<2>(t)) << endl;
        }
        if (get<0>(t) == "update"){
            update(1, 0, n-1, get<1>(t), get<2>(t) + 1);
        }
    }
}
