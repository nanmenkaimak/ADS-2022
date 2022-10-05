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

vector<node *> v;

struct bst{
    public:
    bst(){
        root = NULL;
    }
    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    void print1(node * res){
        this->print(res);
    }
    node * ans() {
        node * res = this->ans(this->root);
        return res;
    }

    

    private:
    node * root;
    node * add(node * current, int x){
        if(current == NULL){
            current = new node(x);
        }else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }else{
                add(current->left, x);
            }
        }else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }else{
                add(current->right, x);
            }
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
    void tostore(node * current) { 
        if(current == NULL) 
            return;
        tostore(current->left);
        v.push_back(current);
        tostore(current->right);
    }

    node * balance(int start, int end) {
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        node * root = v[mid];

        root->left = balance(start, mid - 1);
        root ->right = balance(mid + 1, end);

        return root;
    }

    node * ans(node * root) {
        tostore(root);
        return balance(0, v.size() - 1);
    }

    
};


int main(){

    int n; cin >> n;
    int m = pow(2, n) - 1;
    int a[m];

    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    bst * b = new bst();

    for(int i = 0; i < m; ++i){
        b->add(a[i]);
    }

    node * res = b->ans();
    
    b->print1(res);
   

    return 0;
}