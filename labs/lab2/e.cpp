#include <iostream>
#include <set>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node* head)  
{  
    Node *curr = head;
    Node *nextnext;

    if(head == NULL)
        return;

    while(curr->next != NULL) {
        if(curr->data == curr->next->data) {
            nextnext = curr->next->next;
            free(curr->next);
            curr->next = nextnext;
        } else {
            curr = curr ->next;
        }
    }
}  

int getCount(Node* head)  
{  
    int count = 0; 

    Node *curr = head;
    while(curr != NULL) {
        curr = curr ->next;
        count++;
    }

    return count;  
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}