#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    deque<int> dq;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        dq.push_front(x);
        if(dq.size() > 1) {
            while(dq.front() - dq.back() > 3000) {
                dq.pop_back();
            }
        }
        cout << dq.size() <<" ";
    }
}