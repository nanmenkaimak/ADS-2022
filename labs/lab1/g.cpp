#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int a = 0, num = 2, ans = 0;
    int b = 0, num2 = 2;

    while (b != n) {
        int cnt = 0;
        int cnt1 = 0;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0){
                cnt++;
                break;
            }
        }
        if (cnt == 0) {
            a++;
            for (int i = 2; i * i <= a; i++) {
                if (a % i == 0){
                    cnt1++;
                    break;
                }
            }
            if(a == 1) {
               num2++; 
            }
            else if(cnt1 == 0){
                b++;
                ans = num;
            }
        }
        num++;
    }
    cout << ans;
}