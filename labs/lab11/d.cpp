#include <bits/stdc++.h>

using namespace std;

int par[10000];

int search(int t){
    if(t == par[t])return t;

    return par[t] = search(par[t]); 
}

void merge(int i, int j){
    par[search(i)] = par[search(j)];
}

int main(){
    int n; cin >> n;
    int g[n][n];
    int cnt = 0;
    vector<pair<int, pair<int, int>>> v;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            v.push_back({g[i][j], {i, j}});
        }

    sort(v.begin(), v.end());
    long long cost = 0;
    for(int i = 0; i < n; i++)par[i] = i;
    for(auto i : v){
        if(search(i.second.first) != search(i.second.second)){
            cost += i.first;
            merge(i.second.first, i.second.second);
        }
    }
    cout << cost;
}