#include <iostream>

using namespace std;

int cnt = 0;

struct node{
    int val;
    node * left;
    node * right;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

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
    void ans1(node * res, int x) {
        this->ans(res, x);
    }

    node * res(int x) {
        node * res1 = this->findNode(this->root, x);
        return res1;
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
    node * findNode(node * current, int x) {
        node * res = NULL;
        if(current->val == x) {
            res = current;
            return res;
        } else if (current->val < x) {
            return findNode(current->right, x);
        } else if (current->val > x) {
            return findNode(current->left, x);
        }
    }

    void ans(node * res, int x) {
        if(res != NULL) {
            ans(res->left, x);
            cnt++;
            ans(res->right, x);
        }
    }

    
};


int main(){

    int n,m; cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k; cin >> k;
    bst * b = new bst();

    for(int i = 0; i < n; ++i){
        b->add(a[i]);
    }
    node * res = b->res(k);
    b->ans1(res, k);

    cout << cnt;
   
    return 0;
}