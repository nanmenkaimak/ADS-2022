#include <bits/stdc++.h>

using namespace std;

long long ans(vector<long long>& v, long long m) {
    priority_queue<long long> pq(v.begin(), v.end());
    long long sum = 0;
    for(int i = 0; i < m; i++) {
        int cost = pq.top();
        pq.pop();
        sum += cost;
        pq.push(cost - 1);
    }
    return sum;
}

int main() {
    long long n, m; cin >> n >> m;
    vector<long long> v;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    cout << ans(v,m);
}