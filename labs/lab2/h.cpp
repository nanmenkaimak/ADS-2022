#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    Node * curr = head;
    if(p == 0) {
        node ->next = head;
        head = node;
    } else {
        while(--p) {
            curr = curr ->next;
        }
        node->next = curr->next;
        curr->next = node;
    }
    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    if (head == NULL) return NULL;
    Node * curr = head;
    if (p == 0) {
        head = curr ->next;
        free(curr);
        return head;
    }
     
    while(--p) {
        curr = curr ->next;
    }

    Node *toremove = curr ->next->next;
    free(curr->next);
    
    curr->next = toremove;

    return head;  
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    if (head == NULL) return NULL;
    Node * curr = head;
    if (p1 == 0) {
        head = curr ->next;
        Node *toreplace = curr;
        return insert(head, toreplace, p2); 
    }
     
    while(--p1) {
        curr = curr ->next;
    }

    Node *toremove = curr ->next->next;
    Node *toreplace = curr ->next;
    
    curr->next = toremove;

    return insert(head, toreplace, p2); 
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node *curr = head;
    Node *prev = NULL, *next = NULL;

    while(curr != NULL) {
        next = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
 
void print(Node* head){
    /* write your code here */
    Node * curr = head;
    while(curr != NULL) {
        cout << curr ->val << " ";
        curr = curr ->next;
    }
    return;
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    if(x == 0 || head == NULL) return head;

    Node *curr = head;
    int cnt = 1;
    while(cnt < x && curr != NULL) {
        curr = curr ->next;
        cnt++;
    }

    if(curr == NULL)
        return head;

    Node *temp = curr;

    while(curr->next != NULL) {
        curr = curr ->next;
    }

    curr->next = head;
    head = temp->next;
    temp->next = NULL;

    return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    if (head == NULL || x == 0) return head;

    int len = 1;
    Node *curr = head;

    while(curr ->next != NULL) {
        curr = curr ->next;
        len++;
    }

    if(len == x) return head;

    x = len - x;

    int cnt = 1;
    Node *temp = head;
    
    while(cnt < x && temp != NULL) {
        temp = temp ->next;
        cnt++;
    }

    if(temp == NULL) 
        return head;
    
    curr->next = head;
    head = temp ->next;
    temp ->next = NULL;

    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}