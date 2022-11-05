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
    int getLevelhelp(node * current, int data, int level) {
        if(current == NULL) 
            return 0;
        if(current->val == data){
            return level;
        } 
        int levelleft = getLevelhelp(current->left, data, level + 1);
        
        if(levelleft != 0) 
            return levelleft;

        levelleft = getLevelhelp(current->right, data, level + 1);
        
        return levelleft;  
    }
    // int getLevelhelp(node * current, int x, int level) {
    //     if(current->val == x) {
    //         return level;
    //     } else if (current->val < x) {
    //         return getLevelhelp(current->right, x, level + 1);
    //     } else if (current->val > x) {
    //         return getLevelhelp(current->left, x, level + 1);
    //     }
    // }
    int getLevel(node * current, int data) {
        return getLevelhelp(current, data, 1);
    }
    // int getLevel(node * root, int data) {
    //     queue<node*> q;
    //     int level = 1;
    //     q.push(root);
    
    //     // extra NULL is pushed to keep track
    //     // of all the nodes to be pushed before
    //     // level is incremented by 1
    //     q.push(NULL);
    //     while (!q.empty()) {
    //         node* temp = q.front();
    //         q.pop();
    //         if (temp == NULL) {
    //             if (q.front() != NULL) {
    //                 q.push(NULL);
    //             }
    //             level += 1;
    //         } else {
    //             if (temp->val == data) {
    //                 return level;
    //             }
    //             if (temp->left) {
    //                 q.push(temp->left);
    //             }
    //             if (temp->right) {
    //                 q.push(temp->right);
    //             }
    //         }
    //     }
    //     return 0;
    // }

    void ans(node * current) {
        if(current != NULL) {
            ans(current->left);
            int level = getLevel(root, current->val);
            sum += (current->val - level + 1);
            ans(current->right);
        }
    }
};


int main(){

    int n,m; cin >> n;

    bst * b = new bst();
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        b->add(x);
    }

    b->ans();
    cout << sum<<endl;

    return 0;
}