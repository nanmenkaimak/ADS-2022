#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> v;

    for(int i = 0; i < n; i++) {
        long long x; cin >> x;
        v.push_back(x);
    }

    priority_queue<long long, vector<long long>, greater<long long>> pq(v.begin(),v.end());
    vector<long long> t;
    long long res = 0;

    while(pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b);
        t.push_back(a + b);
    }

    for(auto i : t) 
        res += i;

    cout << res;

}