#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> V(N);
    for(int &x: V) cin >> x;
    int S = accumulate(V.begin(), V.end(), 0);
    int cur = 0, ans = 0;
    for(int l = 0, r = 0; r < N; ) {
        if(cur > ans) cur -= V[l ++];
        else cur += V[r ++];
        ans = max(ans, min(cur, S - cur));
    }
    cout << ans;

    return 0;
}

