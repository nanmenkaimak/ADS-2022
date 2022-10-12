#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

int res = 0;

struct bst{
    public:
    bst(){
        root = NULL;
    }
    void add(int x, int y, int z) {
        node * result = this->add(this->root, x, y, z);
        if(root == NULL) {
            root = result;
        }
    } 

    void print() {
        this->print(this->root);
    }

    int ans() {
        res = this->MaxWidth(this->root);
        return res;
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
            current = new node(1);
            return current;
        }
        node * parent = findNode(current, x);
        if(z == 1) {
            parent->right = new node(y);
        } else if(z == 0) {
            parent->left = new node(y);
        }
        return current;
    }

    int height(node * current) {
        if(current == NULL) return 0;

        int lHeight = height(current->left);
        int rHeight = height(current->right);

        return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
    }

    int getWidth(node * current, int level) {
        if(current == NULL) return 0;
        if(level == 1) return 1;
        else if(level > 1) {
            return getWidth(current->left, level - 1) + getWidth(current->right, level - 1);
        }
    }

    int MaxWidth(node * current) {
        int maxWidth = 0;
        int width = 0;
        int h = height(current);

        for(int i = 1; i <= h; i++) {
            width = getWidth(current, i);
            if(width > maxWidth) 
                maxWidth = width;
        }
        return maxWidth;
    }

    void print(node * current){
        if(current != NULL){
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        } 
    }
};


int main() {
    int n; cin >> n;

    bst *b = new bst;

    for(int i = 0; i < n; i++) {
        if(i == 0){
            b->add(0,1,0);
        } else {
            int x, y, z; cin >> x >> y >> z;
            b->add(x,y,z);
        }
    }
    cout << b->ans();
}