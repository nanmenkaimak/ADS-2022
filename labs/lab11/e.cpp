#include <bits/stdc++.h>
using namespace std;

int p[200000], r[200000];

int search(int t){
    if (t == p[t]){
        return t;
    } 
    return p[t] = search(p[t]);
}

bool merge(int i, int j){
    int a = search(i), b = search(j);
    if(a == b)return false;
    p[a] = b;
    return 1;
}

int main(){
    int n, m; cin >> n >> m;

    vector<int> g[n];
    
    for(int i = 0; i < n; i++){
        p[i] = i;
        r[i] = i;
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    
    }

    vector<int> ans;
    
    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        ans.push_back(cnt++);
        for(int x : g[i]){
            if(x > i){
                if(merge(i, x))cnt--;
            }
        }
    }

    for(int i = ans.size()-1; i >= 0; i--)cout << ans[i] << "\n";
    
}