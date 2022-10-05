#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k; cin >> k;

    int l = 0, r = n - 1, m;
    
    while(l <= r) {
        m = l + (r - l) / 2;
        if(a[m] == k) {
            cout << "Yes" <<endl;
            return 0;
        } else if (a[m] > k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    if(l > r) {
        cout << "No";
    } else if(a[m] == k) {
        cout << "Yes";
    }
}