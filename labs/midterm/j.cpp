#include <bits/stdc++.h>

using namespace std;

int main() {
    int find; cin >> find;
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    int l = 0, r = n - 1;

    while(l <= r) {
        if(a[l] + a[r] == find) {
            cout << a[l] <<" " <<a[r];
            l++;
            r--;
        } else if(a[l] + a[r] > find) {
            r--;
        } else {
            l++;
        }
    }
}