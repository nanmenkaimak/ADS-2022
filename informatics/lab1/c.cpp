#include <bits/stdc++.h>

using namespace std;

int main() {
    deque<int> st;

    string word; 
    
    while(cin >> word) {
        if (word == "push_front") {
            int x; cin >> x;
            st.push_front(x);
            cout << "ok"<<endl;
        } else if (word == "pop_front") {
            if (st.empty()) {
                cout << "error"<<endl;
            } else {
                cout << st.front()<<endl;
                st.pop_front();
            }
        } else if (word == "push_back") {
            int x; cin >> x;
            st.push_back(x);
            cout << "ok"<<endl;
        } else if (word == "pop_back") {
            if (st.empty()) {
                cout << "error"<<endl;
            } else {
                cout << st.back()<<endl;
                st.pop_back();
            }
        } else if (word == "front") {
            if (st.empty()) {
                cout << "error"<<endl;
            } else {
                cout << st.front()<<endl;
            }
        } else if (word == "back") {
            if (st.empty()) {
                cout << "error"<<endl;
            } else {
                cout << st.back()<<endl;
            }
        } else if (word == "size") {
            cout << st.size() <<endl;
        } else if (word == "clear") {
            st.clear();
            cout << "ok"<<endl;
        } else if (word == "exit") {
            cout << "bye"<<endl;
            return 0;
        }
    }
}