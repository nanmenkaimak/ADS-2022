#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m; cin >> n >> m;
    int res[n];
    for(int i = 0; i < n; i++) {
        int b = INT_MIN;
        for(int j = 0; j < 4; j++) {
            int x; cin >> x;
            if(x > b)
                b = x;
        }
        res[i] = b;
    }

    sort(res, res + n);
    cout << res[m - 1];
}