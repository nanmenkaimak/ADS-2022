#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<char> st1;
    stack<char> st2;
    string word1, word2; cin >> word1 >> word2;
    for(int i = 0; i < word1.size(); i++) {
        if(word1[i] == '#') {
            st1.pop();
        } else {
            st1.push(word1[i]);
        }
    }
    for(int i = 0; i < word2.size(); i++) {
        if(word2[i] == '#') {
            st2.pop();
        } else {
            st2.push(word2[i]);
        }
    }

    if((!st1.empty() && st2.empty()) || (!st2.empty() && st1.empty())) {
        cout << "No";
        return 0;
    }

    int n = 0;
    if (st1.size() >= st2.size()) 
        n = st1.size();
    else n = st2.size();

    bool ok = true;
    for(int i = 0; i < n; i++) {
        if (st1.top() != st2.top()){
            ok = false;
            break;
        }
        st1.pop();
        st2.pop();
    }

    if(ok) cout << "Yes";
    else cout << "No";

}