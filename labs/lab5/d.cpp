#include <bits/stdc++.h>

using namespace std;

int ans(vector<int> &v, int m) {
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(),v.end());
    int res = 0;

    while(pq.top() < m) {
        int least = pq.top();
        pq.pop();
        int second_least = pq.top();
        pq.pop();
        int newmix = least + 2 * second_least;
        pq.push(newmix);
        res++;
        if(pq.size() == 1 && pq.top() < m)
            return -1; 
    }

    return res;
}

int main() {
    int n,m; cin >> n >> m;
    vector<int> v;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    cout<<ans(v,m);

}