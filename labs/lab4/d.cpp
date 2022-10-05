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
    void print(){
        this->print(this->root);
    }
    void ans(int level, int res[]) {
        this->ans(this->root, level, res);
    }

    int getHeight() {
        int level = this->getHeight(this->root);
        return level;
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
    void ans(node * current, int level, int res[]) {
        if(current == NULL) 
            return;
        res[level] += current->val; 

        ans(current->left, level + 1, res);
        ans(current->right, level + 1, res);
    }

    int getHeight(node * current) {
        if(current == NULL) {
            return 0;
        } else {
            int left = getHeight(current->left);
            int right = getHeight(current->right);

            return max(left,right) + 1;
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

    
    int level = b->getHeight();
    int res[level] = {0};

    b->ans(0, res);
    
    cout << level<<endl;

    for(int i = 0; i < level; i++) {
        cout << res[i] <<" ";
    }

    return 0;
}