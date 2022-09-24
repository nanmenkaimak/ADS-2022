#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
	Node * newnode = new Node(s);

	if(head == NULL) {
		head = newnode;
		return;
	}

	Node * curr = head;
	
	while(curr->next != NULL) {
		curr = curr ->next;
	}

	curr ->next = newnode;
	return;
}
void add_front(string s){
	Node * newnode = new Node(s);
	newnode->next = head;
	head = newnode;
	return;
}
bool empty(){
	if(head == NULL) return true;
	return false;
}
void erase_front(){
	Node * curr = head;
	head = head ->next;
	delete curr;
}
void erase_back(){
	Node * last = head;
	if(head ->next == NULL) {
		head = NULL;
		return;
	}
	while(last->next->next != NULL) {
		last = last ->next;
	}

	Node *lastNode = last ->next;
	last->next = NULL;
	free(lastNode);
	return;
}
string front(){
	return head ->val;
}
string back(){
	Node *curr = head;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	return curr ->val;
}
void clear(){
	head = NULL;
	return;
}

void show() {
	Node * curr = head;
	while(curr != NULL) {
		cout << curr ->val << " ";
		curr = curr ->next;
	}
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
		if(s == "show") {
			show();
		}
   		// cout << "hi" << endl;
   	}
    return 0;
}