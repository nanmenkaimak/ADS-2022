#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    vector<int> res;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    res.push_back(-1);

    for(int i = 1; i < n; i++) {
        bool ok = true;
        for(int j = i - 1; j >= 0; j--) {
            if (v[i] >= v[j]) {
                ok = false;
                res.push_back(v[j]);
                break;
            }
        }
        if (ok) 
            res.push_back(-1);
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}