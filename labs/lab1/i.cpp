#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<char> v;

    for(int i = 0; i < n; i++) {
        char x; cin >> x;
        v.push_back(x);
    }

    int cntS = 0;
    int cntK = 0;

    while(!v.empty()) {
        int i = 0;
        vector<char> k;
        vector<char> s;
        while(i < v.size()) {
            if(v[i] == 'K' && cntS == 0) {
                cntK++;
                i++;
                k.push_back('K');
            }
            else if(v[i] == 'S' && cntK == 0) {
                cntS++;
                i++;
                s.push_back('S');
            }
            else if(v[i] == 'K' && cntS > 0) {
                v.erase(v.begin() + i);
                cntS--;
            }
            else if(v[i] == 'S' && cntK > 0) {
                v.erase(v.begin() + i);
                cntK--;
            }
        }
        if(cntK == 0 && !v.empty() && !s.empty() && k.empty()) {
            cout << "SAKAYANAGI";
            return 0;
        }
        if(cntS == 0 && !v.empty() && !k.empty() && s.empty()) {
            cout << "KATSURAGI";
            return 0;
        }
    }
}