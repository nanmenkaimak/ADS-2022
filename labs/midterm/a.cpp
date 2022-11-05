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

int sum = 0;
int a[10000] = {0};

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
    void print(){
        this->print(this->root);
    }
    
    void ans() {
        this->ans(this->root);
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
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }
    

    void ans(node * current) {
        int cnt = 0;
        if(current != NULL) {
            node *currleft = current;
            node *currright = current;
            // int leftcnt = 0;
            // int rightcnt = 0;
            ans(current->left);
            while(currleft != NULL && currright != NULL) {
                if(currleft->left != NULL && currright->right != NULL) 
                    a[cnt]++;
                cnt++; 
                currleft = currleft->left;
                currright = currright->right;
            }
            ans(current->right);
        }
    }
};


int main(){

    int n; cin >> n;

    bst * b = new bst();
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        b->add(x);
    }
    b->ans();
    for(int i = 0; i < n - 1; i++) {
        cout << a[i] <<" ";
    }

    return 0;
}