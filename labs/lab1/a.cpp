#include <bits/stdc++.h>

using namespace std;

int main() {
    int m; cin >> m;

    for(int i = 0; i < m; i++) {
        int n; cin >> n;

        int a[n];
        queue<int> que;

        for(int j = 0; j < n; j++) {
            que.push(j);
        }

        for(int num = 1; num <= n; num++) {
            for(int k = 1; k <= num; k++) {
                que.push(que.front());
                que.pop();
            }
            a[que.front()] = num;
            que.pop();
        }

        for(int j = 0; j < n; j++) 
            cout << a[j] << " ";
        cout << endl;
    }
}