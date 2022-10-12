#include <bits/stdc++.h>

using namespace std;

int ans(vector<int>& v) {
    priority_queue<int> pq(v.begin(), v.end());

    while(pq.size() > 1) {
        int tas1 = pq.top();
        pq.pop();
        int tas2 = pq.top();
        pq.pop();
        if(tas1 > tas2) 
            pq.push(tas1 - tas2);
    }

    if(pq.empty()) 
        return 0;
    return pq.top();
}

int main() {
    int n; cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    cout << ans(v);

}