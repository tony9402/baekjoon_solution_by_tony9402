#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, B, W; cin >> N >> B >> W;
    string S; cin >> S;
    int cntB = 0, cntW = 0, ans = 0;
    for(int i = 0, r = -1; i < N; ++i) {
        while(r + 1 < N && cntB + (S[r + 1] == 'B') <= B) cntB += (S[++r] == 'B'), cntW += (S[r] == 'W');
        if(cntW >= W) ans = max(ans, r - i + 1);
        cntB -= (S[i] == 'B');
        cntW -= (S[i] == 'W');
    }
    cout << ans;
    return 0;
}

