#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    stack<int> st;
    stack<int> stmax;
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        if(s == "add") {
            int x; cin >> x;
            st.push(x);
            if(x > max) {
                max = x;
            }
            stmax.push(max);
        } else if (s == "delete") {
            if(!st.empty()){
                st.pop();
                stmax.pop();
            }
            max = stmax.top();
        } else if (s == "getcur") {
            if(!st.empty())
                cout << st.top()<<endl;
            else cout <<"error"<<endl;
        } else if (s == "getmax") {
            if(!st.empty())
                cout << max<<endl;
            else cout << "error"<<endl;
        }
    }
}