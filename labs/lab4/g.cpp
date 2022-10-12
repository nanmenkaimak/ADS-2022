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

int cnt = 0;
vector<int> nodes;

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

    int ans() {
        int maxdis = this->ans(this->root);
        return maxdis;
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

    int sizeofbst(node * current) {
        int size = 0;
        if(current == NULL) 
            return 0;
        else {
            size = sizeofbst(current->left) + sizeofbst(current->right) + 1;
            return size;
        }
    }

    void tovector(node * current) {
        if(current == NULL) return;
        else {
            if(current->left != NULL) 
                tovector(current->left);
            nodes.push_back(current->val);
            if(current->right != NULL) 
                tovector(current->right);
        }
    }

    int getdistance(node * current, int n) {
        if(current != NULL) {
            int x = 0;
            if((current->val == n) || (x = getdistance(current->left, n) > 0) || (x = getdistance(current->right, n) > 0))
                return x + 1;
            return 0;
        }
        return 0;
    }

    node * lowestCommonAncestor(node * current, int a, int b) {
        if(current != NULL) {
            if(current->val == a || current->val == b) {
                return current;
            }

            node * left = lowestCommonAncestor(current->left, a, b);
            node * right = lowestCommonAncestor(current->right, a, b);

            if(left != NULL && right != NULL) 
                return current;
            
            if(left != NULL)
                return left;
            
            if(right != NULL) 
                return right;
        }
        return NULL;
    }

    int findDistance(node * current, int a, int b) {
        int d1 = getdistance(current, a) - 1;
        int d2 = getdistance(current, b) - 1;

        node * ancestor = lowestCommonAncestor(current, a, b);

        int d3 = getdistance(current, ancestor->val) - 1;

        return (d1 + d2) - 2 * d3; 
    }

    int ans(node * current) {
        int maxdis = 0, distance = 0;

        int treesize = sizeofbst(current);

        tovector(current);

        for(int i = 0; i < treesize; i++) {
            for(int j = i; j < treesize; j++) {
                distance = findDistance(current, nodes[i], nodes[j]);
                if(maxdis <= distance) {
                    maxdis = distance;
                } 
            }
        }
        return maxdis; 
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

    cout << b->ans();

}