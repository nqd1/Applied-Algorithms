#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)

int main(){
    fast;
    int n;
    cin >> n;

    vector<int> llist(n);

    int max_time = 0;

    for (int i = 0; i < n; i++){
        cin >> llist[i];
    }

    sort(llist.rbegin(), llist.rend());
    for (int i = 0; i < n; i++){
        max_time = max(max_time, i + llist[i]);
    }

    cout << max_time << endl;
    return 0;
}
