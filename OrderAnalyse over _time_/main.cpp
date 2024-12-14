#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)


map<int, int> timeline;

string s;
int c = 0;
int sec(string time){ // 01:34:67
    return  (time[0] - '0') * 36000 + (time[1] - '0') * 3600
        +   (time[3] - '0') * 600   + (time[4] - '0') * 60
        +   (time[6] - '0') * 10    + (time[7] - '0');
}

void input(){
    while (true){
        cin >> s;
        if (s == "#") break;
        cin >> s;
        timeline[sec(s)] ++;
        c++;
    }
}

void query(){
    while (true){
        cin >> s;
        if (s == "###") break;
        if (s == "?number_orders") cout << c << endl;
        else if (s == "?number_orders_in_period"){
            int counter = 0;
            string from, to;
            cin >> from >> to;
            auto it1 = timeline.lower_bound(sec(from));
            auto it2 = timeline.upper_bound(sec(to));


            for (auto it = it1; it != it2; it++){
                counter += it->second;
            }

            cout << counter << endl;
        }
        else if (s == "?number_orders_at_time"){
            string time;
            cin >> time;
            cout << timeline[sec(time)] << endl;
        }
    }
}


int main(){
    fast;
    input();
    query();

    return 0;
}
