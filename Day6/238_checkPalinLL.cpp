#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next==NULL)  return head;
        ListNode* slow=head;
        ListNode* fast=head;
        stack<int> st;

        int len=0;
        ListNode* ptr=head;
        while(ptr)
        {
            len++;
            ptr=ptr->next;
        }

        while(fast!=NULL && fast->next!=NULL)
        {
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }

        if(len%2!=0 && slow->next!=NULL)    slow=slow->next;
        while(slow!=NULL)
        {
            if(st.top()==slow->val)
            {
                slow=slow->next;
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};