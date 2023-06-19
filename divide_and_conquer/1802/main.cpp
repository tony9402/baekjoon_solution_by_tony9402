#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while(~--T) {
        string S; cin >> S;
        int N = (int)S.size();
        function<bool(int, int)> go = [&](int l, int r) -> bool {
            if(l >= r) return true;
            int tmp = l;
            while(l < r) if(S[l ++] == S[r --]) return false;
            return go(tmp, r - 1);
        };
        cout << (N % 2 && go(0, N - 1) ? "YES" : "NO") << '\n';
    }

    return 0;
}
