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

    void ans() {
        node * curr = head;
        while(curr != NULL && curr ->next != NULL) {
            curr ->next = curr->next->next;
            curr = curr ->next;
        }
    }
};


int main() {
    ll l;

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        l.add(x);
    }

    l.ans();
    l.print();

}