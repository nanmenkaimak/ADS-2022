#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
	Node(){
		this->val = 0;
        this->left = this->right = nullptr;
	}
    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};



Node *insert(Node *node, int x,  int y, int z){
	if(!node)return nullptr;
	if(node->val == x){
		if(z == 0){
			node->left = new Node(y);
		}
		else node->right = new Node(y);
		return node;
	}
	insert(node->left, x, y, z);
	insert(node->right, x, y, z);
	return node;
}

int getWidth(Node *node){
	if(!node)return 0;
	int maxw = -1;
	queue<Node*> q;
    q.push(node);
	while(!q.empty()){
		int size = q.size();
		int cnt = 0;
		while(size--){
			if(q.front()->left)q.push(q.front()->left);
			if(q.front()->right)q.push(q.front()->right);
			cnt++;
			q.pop();
		}
		maxw = max(maxw, cnt);
	}
	return maxw;
}

void print(Node *node){
	if(!node)return;
    cout << node->val << " ";
	print(node->left);
    print(node->right);
}
int main() {
    int n;
    cin >> n;
	n--;
    Node *root = new Node(1);

	for(int i = 0; i < n; i++){
		int x, y, z;
		cin >> x >> y >> z;
        root = insert(root, x, y, z);
	}
	cout <<getWidth(root);
    return 0;
}