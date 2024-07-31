#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node 
{ 
    public:
    int data; 
    Node* next; 
}; 

void sortList(Node *head) 
{
    int count0=0,count1=0,count2=0;

    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data == 0)  count0++;
        else if(temp->data == 1)    count1++;
        else    count2++;

        temp=temp->next;
    }

    temp = head;
    while(temp!=NULL)
    {
        if(count0)
        {
            temp->data = 0;
            count0--;
        }
        else if(count1)
        {
            temp->data = 1;
            count1--;
        }
        else{
            temp->data = 2;
            count2--;
        }
        temp=temp->next;
    }
}

void push (Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data; 
 
    /* link the old list of the new node */
    new_node->next = (*head_ref); 
 
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 

void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout << node->data << " "; 
        node = node->next; 
    } 
    cout << endl; 
} 

int main(void) 
{ 
    Node *head = NULL; 
    push(&head, 0); 
    push(&head, 1); 
    push(&head, 0); 
    push(&head, 2); 
    push(&head, 1); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 1); 
    push(&head, 2); 
 
    cout << "Linked List before Sorting\n"; 
    printList(head); 
 
    sortList(head); 
 
    cout << "Linked List after Sorting\n"; 
    printList(head); 
 
    return 0; 
} 
 