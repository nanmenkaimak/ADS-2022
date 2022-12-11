#include <bits/stdc++.h>

using namespace std;

vector<pair <int,pair<int,int>>> v;
int par[1000000];
int ln[1000000], rn[1000000]; 

int search(int t){
    if(t == par[t]){
        return t;
    }
    return par[t] = search(par[t]);
}

bool mergs(int i, int j){
    int a = search(i), b = search(j);
    if(a == b){
        return false;
    } 
    par[a] = b;
    ln[b] = min(ln[a], ln[b]);
    rn[b] = max(rn[a], rn[b]);
    return 1;
}

int main(){
    int n, m, l, r, c;
    cin >> n >> m;

    vector<bool> visit(n , false);
    for(int i = 0; i < m; i++){
        cin >> l >> r >> c;
        l--;
        r--;
        v.push_back({c, {l, r}});
    }
    for(int i = 0; i < n; i++){
        par[i] = i;
        ln[i] = i;
        rn[i] = i;
    }
    sort(v.begin(), v.end());
    long long minC = 0;
    int cnt = 0, p = -1;
    for(int i = 0; i < v.size(); i++){
        if(cnt > n - 1){
            break;
        }
        int l = v[i].second.first;
        int r = v[i].second.second;
        int c = v[i].first;
        p = l;
        for(int j = l; j <= r; j++){
            if(j != search(j)){
                p = search(j);
                break;
            }
        }
        if(ln[p] <= l and r <= rn[p])continue;
        else if(ln[p] <= r and r <= rn[p])r = ln[p];
        else if(ln[p] <= l and l <= rn[p])l = rn[p];

        for(int j = l; j <= r; j++){
            if(mergs(p, j)){
                cnt++;
                minC += c;
            }
        }
    }
    cout << minC;
}