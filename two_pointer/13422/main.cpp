#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while(~--T) {
        int N, M, K; cin >> N >> M >> K;
        vector<int> V(2 * N + 1);
        for(int i = 1; i <= N; ++i) cin >> V[i], V[N + i] = V[i];
        int cur = 0, ans = 0;
        for(int i = 1, r = 0; i <= N; ++i) {
            while(r + 1 <= 2 * N && r - i + 2 <= M && cur + V[r + 1] < K) cur += V[++r];
            if(r - i + 1 == M) ++ ans;
            cur -= V[i];
        }
        if(N == M) ans = min(ans, 1);
        cout << ans << '\n';
    }
    return 0;
}
