#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S, E, Q; cin >> S >> E >> Q;
    string A, B;

    set<string> st;
    int ans = 0;
    while(cin >> A >> B) {
        if(A <= S) st.insert(B);
        else if(E <= A && A <= Q) {
            if(st.count(B)) {
                st.erase(B);
                ++ ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
