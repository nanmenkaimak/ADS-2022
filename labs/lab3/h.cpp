#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m; cin >> n >> m;
    int a[n];

    int k = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        k += x;
        a[i] = k;
    }
    
    
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        int left = 0, right = n - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(a[mid] >= x) {
                if(mid != 0 && a[mid - 1] < x) {
                    cout << mid + 1 <<endl;
                    break;
                } else if(mid == 0) {
                    cout << mid + 1 <<endl;
                    break;
                } else {
                    right = mid - 1;
                }
            } else {
                left = mid + 1;
            }
        }
    }
}