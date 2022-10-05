#include <bits/stdc++.h>

using namespace std;

bool canEatIntime(int a[], int h, int k, int n) {
    int hours = 0;
    for(int i = 0; i < n; i++) {
        int div = a[i] / k;
        hours += div;
        if(a[i] % k != 0) 
            hours++;
    }
    return hours <= h;
}


int minEatSpeed(int a[], int h, int n) {
    int left = 1;
    int right = 1000000000;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(canEatIntime(a, h, mid, n)) 
            right = mid - 1;
        else left = mid + 1;
    }
    return left;
}

int main() {
    int n,h; cin >> n >> h;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << minEatSpeed(a,h,n);

}