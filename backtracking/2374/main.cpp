#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> V(N);
    for(int i = 0; i < N; ++i) cin >> V[i];
    ll ans = 0;
    function<ll(int, int)> go = [&](int l, int r) -> ll {
        if(l > r) return -1;
        int mx = 0, idx = 0;
        for(int i = l; i <= r; ++i) if(mx < V[i]) mx = V[i], idx = i;
        ll left = go(l, idx - 1), right = go(idx + 1, r);
        if(left != -1) ans += V[idx] - left;
        if(right != -1) ans += V[idx] - right;
        return V[idx];
    };
    go(0, N - 1);
    cout << ans << '\n';

    return 0;
}
