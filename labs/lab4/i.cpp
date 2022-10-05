#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

map<int, int> mp;

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node * add(Node* root, int data) {
	if (root == NULL) {
		root = new Node(data);
        mp[data]++;
	} else if (root->data > data) {
		if (root->left == NULL) {
			root->left = new Node(data);
            mp[data]++;
		} else {
			add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == NULL) {
			root->right = new Node(data);
            mp[data]++;
		} else {
			add(root->right, data);
		}
	} else if (root->data == data) {
        mp[data]++;
    }
    return root;
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

Node * deleteNode(Node* root, int data) {
    Node * kkk = find(root, data);
	if (root == NULL) {
		return NULL;
	} else if(kkk != NULL && mp[data] > 1) {
        mp[data]--;
        return root;
    } else { 
        mp[data]--;
        if (root->data > data) {
            deleteNode(root->left, data);
            return root;
        } else if (root->data < data) {
            deleteNode(root->right, data);
            return root;
        } else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else {
                Node* temp = getMin(root->right);
                root->data = temp->data;
                deleteNode(root->right, temp->data);
                return root;
            }
        }
}
}



int main() {
    Node * root = NULL;
    Node * result;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        if(s == "insert") {
            int x; cin >> x;
            result = add(root, x);
            if(root == NULL) {
                root = result;
            }
        } else if (s == "delete") {
            int x; cin >> x;
            result = deleteNode(root, x);
            if(result == NULL) 
                root = NULL;
        } else if (s == "cnt") {
            int x; cin >> x;
            cout << mp[x] <<endl;
        }
    }
}