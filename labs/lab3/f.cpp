#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k; cin >> k;

    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        int sum = 0, cnt = 0;
        for(int j = 0; j < n; j++) {
            if(x >= a[j]) {
                sum += a[j];
                cnt++;
            }
        }
        cout << cnt << " " << sum <<endl;
    }
}