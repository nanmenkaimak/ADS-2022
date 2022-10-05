#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        int b[4];
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            cin >> b[j];
        }
        for(int j = 0; j < n; j++) {
            if((a[j] >= b[0] && a[j] <= b[1]) || (a[j] >= b[2] && a[j] <= b[3])) {
                cnt++;
            }
        }
        cout << cnt<<endl;
    }
}