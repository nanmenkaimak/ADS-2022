#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> st;

    string word; 
    
    while(cin >> word) {
        if (word == "push") {
            int x; cin >> x;
            st.push(x);
            cout << "ok"<<endl;
        } else if (word == "pop") {
            if (st.empty()) {
                cout << "error"<<endl;
            } else {
                cout << st.front()<<endl;
                st.pop();
            }
        } else if (word == "front") {
            if (st.empty()) {
                cout << "error"<<endl;
            } else {
                cout << st.front()<<endl;
            }
        } else if (word == "size") {
            cout << st.size() <<endl;
        } else if (word == "clear") {
            while(!st.empty()) {
                st.pop();
            }
            cout << "ok"<<endl;
        } else if (word == "exit") {
            cout << "bye"<<endl;
            return 0;
        }
    }
}