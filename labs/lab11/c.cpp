#include <bits/stdc++.h>

using namespace std;


vector<pair<int, pair<int, int>>> v;
int par[10000];

int search(int t){
    if(t == par[t])return t;
    return par[t] = search(par[t]);
}

void merge(int i, int j){
    int a = search(i), b = search(j);
    par[a] = par[b];

}

int main(){
    int n, m, x ,y;
    cin >> n >> m >> x >> y;
    
    for(int i = 0; i < m; i++){
        string s;int a, b, c;
        cin >> s >> a >> b >> c;
        if(s == "both")v.push_back({c*min(x,y), {a, b}});
        else if(s == "small")v.push_back({c*y, {a, b}});
        else if(s == "big")v.push_back({c*x, {a, b}});
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)par[i] = i;
    long long minC = 0;
    for(auto e : v){
        int l = e.second.second, r = e.second.first, c = e.first;
        if(search(l) != search(r)){
            minC += c;
            merge(l, r);
        }

    }

    cout << minC;
}