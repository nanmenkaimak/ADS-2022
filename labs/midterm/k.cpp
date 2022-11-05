#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    deque<int> dq1;
    bool ok = true;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 1) {
            int m; cin >> m;
            if(ok) dq1.push_back(m);
            else dq1.push_front(m);
            cnt++;
        } else {
            if(ok) ok = false;
            else ok = true;
        }
    }
    if(ok) {
        for(int i = 0; i < cnt; i++) {
            cout << dq1.front() <<" ";
            dq1.pop_front();
        }
    } else {
        for(int i = 0; i < cnt; i++) {
            cout << dq1.back() <<" ";
            dq1.pop_back();
        }
    }
}