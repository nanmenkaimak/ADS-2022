#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node * next;
    node(int x) {
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
    void add(int x) {
        node * n = new node(x);
        if(head == NULL) {
            head = n;
            tail = n;
        } else {
            tail -> next = n;
            tail = n;
        }
    }

    void ans(int k) {
        node * curr = head;
        int ans = 100000000;
        int i = 0;
        int res = 0;
        while(curr != NULL) {
            if(abs(k - curr->val) < ans) {
                ans = abs(k - curr->val);
                res = i;
            }
            curr = curr -> next;
            i++;
        }
        cout << res;
    }
};

int main() {

    ll l;

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        l.add(x);
    }

    int k; cin >> k;

    l.ans(k);

}