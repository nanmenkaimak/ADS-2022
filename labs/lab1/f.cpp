#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int a = 0, num = 2, ans = 0;

    while (a != n) {
        int cnt = 0;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0){
                cnt++;
                break;
            }
        }
        if (cnt == 0) {
            a++;
            ans = num;
        }
        num++;
    }
    cout << ans;
}