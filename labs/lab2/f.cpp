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

    void ans(int a, int b) {
        node * curr = head;
        node *p = new node(a);

        if (b == 0){
            p->next = head;
            head = p;
            return;
        }

        while (--b) {
            curr = curr ->next;
        }
        p->next = curr->next;
        curr->next = p;
    }
};


int main() {
    ll l;

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        l.add(x);
    }

    int a,b; cin >> a >> b;

    l.ans(a,b);
    l.print();
    

}