#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string target; cin >> target;

    map<string, int> mp; mp[""] = 1;
    for(int i = 0; i < (int)target.size(); ++i) {
        map<string, int> nxt;
        for(auto [it, value] : mp) {
            for(int j = 0; j < 10; ++j) {
                string L = to_string(j) + it;
                string R = it + to_string(j);
                if(target.find(L) != string::npos) nxt[L] += value;
                if(L != R && target.find(R) != string::npos) nxt[R] += value;
            }
        }
        mp.swap(nxt);
    }
    cout << mp[target];

    return 0;
}

