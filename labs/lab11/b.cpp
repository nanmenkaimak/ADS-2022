#include <bits/stdc++.h>

using namespace std;

vector <pair <int, pair <int, int>>> v;
int par[300000];

int search(int t){
    if(t == par[t]){
        return t;
    }
    return par[t] = search(par[t]);
}

void merge(int i, int j){
    int a = search(i), b = search(j);
    par[a] = par[b];
}

int main(){
    int n; cin >> n;
    int d[n];
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                v.push_back({d[i] + d[j], {i, j}});
            }
        }
    }
    for(int i = 0; i < n; i++){
        par[i] = i;
    }
    sort(v.begin(), v.end());
    long long minC = 0;
    for(auto e : v){
        int i = e.second.first, j = e.second.second, c = e.first;
        if(search(i) != search(j)){
            minC += c;
            merge(i, j);
        }
    }

    cout << minC; 
}