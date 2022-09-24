#include <bits/stdc++.h>

using namespace std;

struct node {
    char val;
    node * next;
    node(char x) {
        val = x;
        next = NULL;
    }
};

struct ll {
    node * head;
    node * tail;
    ll() {
        head = NULL;
        tail = NULL;
    }
    void add(char x) {
        node * n = new node(x);
        if(head == NULL) {
            head = n;
            tail = n;
        } else {
            tail ->next = n;
            tail = n;
        }
    }
    void print() {
        node * curr = head;
        while(curr != NULL) {
            cout << curr -> val<<" ";
            curr = curr ->next;
        }
    }

    void ans() {
        node * curr = head;
        set<char> st;
        queue<char> q;
        while(curr != NULL) {
            if(st.empty()) {
                cout << curr->val <<" ";
                st.insert(curr->val);
                q.push(curr->val);
            } else {
                if(st.find(curr->val) != st.end()) {
                    queue<char> ref;
                    int cnt = 0;
                    int s = q.size();
                    while(q.front() != curr->val && !q.empty()) {
                        ref.push(q.front());
                        q.pop();
                        cnt++;
                    }
                    if(q.empty()) {
                        while(!ref.empty()) {
                            q.push(ref.front());
                            ref.pop();
                        }
                    } else {
                        q.pop();
                        while(!ref.empty()) {
                            q.push(ref.front());
                            ref.pop();
                        }
                        int k = s - cnt - 1;
                        while(k--) {
                            char p = q.front();
                            q.pop();
                            q.push(p);
                        }
                    }
                } else {
                    st.insert(curr->val);
                    q.push(curr->val);
                }
                if(!q.empty()) {
                    cout << q.front() <<" ";
                } else cout << -1 << " ";
            }
            curr = curr ->next;
        }
        cout << endl;
    }
};


int main() {

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        ll l;
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            char c; cin >> c;
            l.add(c);
        }

        l.ans();
    }


}