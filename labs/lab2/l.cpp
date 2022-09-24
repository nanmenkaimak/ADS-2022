#include <bits/stdc++.h>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
	// Implement this function
    if (!head) return 0;

    if (!head ->val) return head->val;

    int max_end = head->val;

    int max_res = head->val;

    head = head ->next;

    while(head != NULL) {
        max_end = max(head->val, max_end + head->val);
        max_res = max(max_end, max_res);
        head = head ->next;
    }
    
    return max_res;
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}