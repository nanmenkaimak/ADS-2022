#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct BinSearchTree{
    Node* root;
    BinSearchTree() {
        root = NULL;
    }
private:
    Node* _add(int x, Node *current){
        if(current == NULL) return new Node(x);
        if(current->val == x) return current;
        else if (x < current->val) current->left = _add(x, current->left);
        else current->right = _add(x, current->right);
        return current;
    }

    int _height(Node *current, int &d){
        if(!current) return 0;
        int left = _height(current->left, d);
        int right = _height(current->right, d);
        d = max(d, left + right + 1);
        return max(left, right) + 1;
    }
    
public:
    void add(int x){
        this->root = _add(x, root);
    }

    int getDiameter(){
        int d = 0;
        _height(this->root, d);
        return d;
    }

};


int main() {
    int n;
    cin >> n;
    BinSearchTree tree;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        tree.add(x);
    }
    
    cout << tree.getDiameter()<< endl;

    return 0;
}