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
    bool ans(string s) {
        bool ok = this->ans(this->root, s);
        return ok;
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
    bool ans(node * current, string s) {
        if(current == NULL) 
            return false;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'L' && current->left != NULL) {
                current = current->left;
            } else if(s[i] == 'R' && current->right != NULL) {
                current = current->right;
            } else if(s[i] == 'L' && current->left == NULL){
                return false;
            } else if(s[i] == 'R' && current->right == NULL){
                return false;
            }
        }
        return true;
    }
};


int main(){

    int n,m; cin >> n >> m;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }


    bst * b = new bst();
    

    for(int i = 0; i < n; ++i){
        b->add(a[i]);
    }

    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        bool ok = b -> ans(s);
        if(ok) {
            cout << "YES"<<endl;
        } else {
            cout << "NO"<<endl;
        }
    }


    return 0;
}