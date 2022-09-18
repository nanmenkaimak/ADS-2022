#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<int, string>> v;
     
    int x;

    while (cin >> x) {
        string s; cin >> s;
        v.push_back(make_pair(x,s));
    }
    sort(v.begin(), v.end());
    for(auto i : v) 
        cout << i.first << " " << i.second <<endl;
}