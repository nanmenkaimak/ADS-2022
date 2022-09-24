#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a,pair<int, int> &b) { 
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second; 
} 

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
        map<int,int> mp;
        vector<pair<int,int>> v;
        while(curr != NULL) {
            mp[curr->val]++;
            curr = curr->next;
        }
        for(auto i : mp) 
            v.push_back(make_pair(i.first, i.second));
        sort(v.begin(), v.end(), cmp);
        int k = v.begin() ->second;
        for(auto i : v) {
            if(k == i.second) 
                cout << i.first <<" ";
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

}