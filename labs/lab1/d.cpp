#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;

    if(s == "") {
        cout << "YES";
        return 0;
    }

    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        } else if (st.top() == s[i]) {
            st.pop();
        }
    }
    if(st.empty()) cout << "YES";
    else cout << "NO";
}