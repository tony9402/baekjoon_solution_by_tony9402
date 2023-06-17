#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while(~--T) {
        int N, K; cin >> N >> K;
        vector<int> V(N);
        for(int &x: V) cin >> x;
        sort(V.begin(), V.end());
        int ans = 0, mn = INT_MAX, l = 0, r = N - 1;
        while(l < r) {
            int d = abs(K - V[l] - V[r]);
            if(d < mn) mn = d, ans = 1;
            else if(d == mn) ans ++;
            if(abs(K - V[l + 1] - V[r]) <= abs(K - V[l] - V[r - 1])) ++l;
            else --r;
        }
        if(ans == 0) ++ans;
        cout << ans << '\n';
    }
    return 0;
}
