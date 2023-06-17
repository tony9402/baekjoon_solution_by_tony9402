#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> V(N);
    for(int i = 0; i < N; ++i) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());

    int mx = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(auto [l, r] : V) {
        while(!pq.empty() && pq.top().first < l) pq.pop();
        pq.emplace(r, 0);
        mx = max(mx, (int)pq.size());
    }
    cout << mx << '\n';
    priority_queue<int, vector<int>, greater<>> rooms;
    for(int i = 1; i <= mx; ++i) rooms.push(i);
    vector<int> cnt(mx + 1);
    for(auto [l, r]: V) {
        while(!pq.empty() && pq.top().first < l) {
            rooms.push(pq.top().second);
            pq.pop();
        }
        int room_num = rooms.top(); rooms.pop();
        pq.emplace(r, room_num);
        ++ cnt[room_num];
    }
    for(int i = 1; i <= mx; ++i) cout << cnt[i] << ' ';

    return 0;
}
