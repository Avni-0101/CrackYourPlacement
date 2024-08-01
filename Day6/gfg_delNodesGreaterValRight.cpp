#include<bits/stdc++.h>
using namespace std;

// The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head==NULL || head->next==NULL)  return head;
        Node* prev=NULL;
        Node* curr=head;
        Node* after=head->next;
        
        while(curr!=NULL && curr->next!=NULL)
        {
            if(after->data<=curr->data)
            {
                if(after->next==NULL)
                {
                    after=curr->next;
                    prev = curr;
                    curr=curr->next;
                }
                after=after->next;
            }
            else
            {
                if(prev==NULL)
                {
                    head=curr->next;
                    curr = head;
                    after=curr->next;
                }
                else
                {
                    prev->next=after;
                    curr=after;
                    after=curr->next;
                }
            }
        }
        return head;
    }
    
};
   