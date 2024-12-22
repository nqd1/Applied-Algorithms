#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)

map<int, int> timeline;
vector<pair<int, long long>> mangcongdon;
string s;
int c = 0;

int sec(string time) { // 01:34:67
    return (time[0] - '0') * 36000 + (time[1] - '0') * 3600
        +  (time[3] - '0') * 600   + (time[4] - '0') * 60
        +  (time[6] - '0') * 10    + (time[7] - '0');
}

void input() {
    while (true) {
        cin >> s;
        if (s == "#") break;
        cin >> s;
        timeline[sec(s)]++;
        c++;
    }
}

void buildMangCongDon() {
    long long sum = 0;
    for (const auto& it : timeline) {
        sum += it.second;
        mangcongdon.emplace_back(it.first, sum);
    }
}

long long rangeSum(const string& a, const string& b) {
    int start = sec(a), end = sec(b);
    auto itLow = lower_bound(mangcongdon.begin(), mangcongdon.end(), make_pair(start, 0LL));
    auto itHigh = upper_bound(mangcongdon.begin(), mangcongdon.end(), make_pair(end, LLONG_MAX));

    long long sumHigh = (itHigh == mangcongdon.begin()) ? 0 : prev(itHigh)->second;
    long long sumLow = (itLow == mangcongdon.begin()) ? 0 : prev(itLow)->second;

    return sumHigh - sumLow;
}

void query() {
    while (true) {
        cin >> s;
        if (s == "###") break;
        if (s == "?number_orders") {
            cout << c << endl;
        } else if (s == "?number_orders_in_period") {
            string from, to;
            cin >> from >> to;
            cout << rangeSum(from, to) << endl;
        } else if (s == "?number_orders_at_time") {
            string time;
            cin >> time;
            cout << timeline[sec(time)] << endl;
        }
    }
}

int main() {
    fast;
    input();
    buildMangCongDon();
    query();
    return 0;
}
