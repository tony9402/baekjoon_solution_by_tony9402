#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    if(B * C > D * A) swap(A, C), swap(B, D);
    ll mn = LLONG_MAX;
    for(int i = 0; i < A; ++i) { 
        ll x = (N - C * i + A - 1) / A;
        if(x < 0) break;
        mn = min(mn, i * D + x * B);
    }
    cout << mn;

    return 0;
}
