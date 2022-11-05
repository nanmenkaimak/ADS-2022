#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) 
            return false;
    }
    return true;
}

int main() {
    int n; cin >> n;

    int l = 2, r = n;
    while(l <= r) {
        if(isPrime(l) && isPrime(r)) {
            if(l + r == n) {
                cout << l << " " << r<<endl;
                return 0;
            } else if(l + r > n) {
                r--;
            } else if (l + r < n) {
                l++;
            }
        } else if (!isPrime(l)) {
            l++;
        } else if (!isPrime(r)){
            r--;
        }
    }
}