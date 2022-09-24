#include <iostream>
using namespace std;

struct Node {
	string word;
	Node* next;

	Node() {}

	Node(string word) {
		this->word = word;
		this->next = NULL;
	}
};

// your code goes here

Node* cyclicShift(Node* head, int k) {
    if (k == 0 || head == NULL || head ->next == NULL) 
        return head;

    Node * curr = head;
	Node *last = curr;
	while(last ->next != NULL) 
		last = last ->next;
    for(int i = 0; i < k; i++) {
		Node *first = curr;
		curr = first->next;
		first->next = NULL;
		last->next = first;
		last = first;
	}

	return curr;

}

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->word << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int k; cin >> k;
	Node* head;
	Node* cur;
	for (int i = 0; i < n; i++) {
		string word; cin >> word;
		if (i == 0) {
			head = new Node(word);
			cur = head;
		} else {
			cur->next = new Node(word);
			cur = cur->next;
		}
	}

	head = cyclicShift(head, k);
	print(head);
}