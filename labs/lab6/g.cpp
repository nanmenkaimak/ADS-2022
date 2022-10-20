#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    map<string, string> mp;

    for(int i = 0; i < n; i++) {
        bool ok = true;
        string s, s1; cin >> s >> s1;
        for(auto i : mp) {
                if(s == i.second) {
                    mp[i.first] = s1;
                    ok = false;
                    break;
                }
            }
        if(ok) {
            if(mp.find(s1) != mp.end()) {
                mp[s] = mp[s1];
                ok = false;
            }
        }
        if(ok) {
            mp[s] = s1;
        }
    }
    cout <<mp.size()<<endl;
    for(auto i : mp) {
        cout << i.first <<" " <<i.second<<endl;
    }

}