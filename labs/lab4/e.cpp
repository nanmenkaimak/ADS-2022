#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node * left;
    node * right;
    node(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bt {
public:
    bt() {
        root = new node(1);
    }

    void add(int x, int y, int z) {
        node * result = this->add(this->root, x, y, z);
    }  

    void print() {
        this->print(this->root);
    }

    int ans() {
        this->ans(this->root);
    }

private:
    node * root;
    node * findNode(node * current, int x) {
        if(current == NULL) {
            return NULL;
        }

        if(current->val == x) {
            return current;
        }

        node * res = findNode(current->left, x);
        if(res != NULL) 
            return res; 

        node * res1 = findNode(current->right, x);
        if(res1 != NULL) 
            return res1;

    }

    node * add(node * current, int x, int y, int z) {
        if(current == NULL) {
            current = new node(y);
            return current;
        }
        node * parent = findNode(current, x);
        if(z == 1) {
            parent->left = new node(y);
        } else if(z == 0) {
            parent->right = new node(y);
        }
        return current;
    }

    void print(node * current){
        if(current != NULL){
            cout << current->val << " ";
            print(current->left);
            print(current->right);
        } 
    }

    int ans(node * current) {
        if(current == NULL) 
            return 0;
        
        int res = 1;
        queue<pair<node*, int>> q;

        q.push({current, 0});

        while(!q.empty()) {
            int n = q.size();

            int start = q.front().second;
            int end = q.back().second;

            res = max(res, end - start + 1);

            for(int i = 0; i < n; i++) {
                pair<node*, int> p = q.front();

                int idx = p.second - start;

                q.pop();

                if(p.first->left != NULL) {
                    q.push({p.first->left, (long long)2 * idx + 1});
                } 

                if(p.first->right != NULL) {
                    q.push({p.first->right, (long long)2 * idx + 2});
                }
            }
        }
        return res;
    }
};

int main() {
    bt * b = new bt;
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x,y,z; cin >> x >> y >> z;
        b->add(x,y,z);
    }

    int ans = b->ans();

    cout << ans;

    

}