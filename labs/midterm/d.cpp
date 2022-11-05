#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int cnt = 0;
    int i = 2;
    set<int> st;
    while(i <= n) {
        if(n % i == 0) {
            n /= i;
            st.insert(i);
        } else {
            i++;
        }
    }
    cout <<st.size();
}