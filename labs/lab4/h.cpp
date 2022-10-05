#include <iostream>

using namespace std;

int res = 0;

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
            print(current->right);
            cout << current->val << " ";
            print(current->left);
        }
    }
    void ans(node * current) {
        if(current != NULL) {
            ans(current->right);
            res += current->val;
            current->val = res;
            ans(current->left);
        }
    }

    
};


int main(){

    int n,m; cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bst * b = new bst();

    for(int i = 0; i < n; ++i){
        b->add(a[i]);
    }

    b->ans();
    
    b->print();
   

    return 0;
}