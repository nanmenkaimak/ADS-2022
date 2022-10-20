#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    char a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    char k; cin >> k;

    for(int i = 0; i < n; i++) {
        if(k < a[i]) {
            cout << a[i];
            return 0;
        }
    }
    cout << a[0];
}