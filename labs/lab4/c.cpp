#include <iostream>

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
    node * ans(int x) {
        node * result = this->ans(this->root, x);
        return result;
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
    node * ans(node * current, int x) {
        node * res = NULL;
        if(current->val == x) {
            res = current;
            return res;
        } else if (current->val < x) {
            return ans(current->right, x);
        } else if (current->val > x) {
            return ans(current->left, x);
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

    node * res = b->ans(k);

    b->print1(res);

    

    return 0;
}