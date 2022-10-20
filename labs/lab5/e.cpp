#include <bits/stdc++.h>

using namespace std;

long long ans(priority_queue<int, vector<int>, greater<int>> pq, int m) {
    long long res = 0;
    int length = pq.size();
    length = min(length, m);
    for(int i = 0; i < length; i++) {
        res += pq.top();
        pq.pop();
    }

    return res;
}

int main() {
    int n, m; cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        if(s == "insert") {
            int x; cin >> x;
            pq.push(x);
        } else if (s == "print") {
            if(pq.empty())
                cout << 0<<endl;
            else 
                cout << ans(pq, m)<<endl;
        }
    }
}