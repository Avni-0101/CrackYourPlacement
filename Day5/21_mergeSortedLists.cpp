#include<bits/stdc++.h>
using namespace std;
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode(-1);
        ListNode* ptr = merged;

        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val <= list2->val)
            {
                ptr->next = new ListNode(list1->val,NULL);
                list1=list1->next;
                ptr=ptr->next;
            }
            else
            {
                ptr->next = new ListNode(list2->val,NULL);
                ptr=ptr->next;
                list2=list2->next;
            }
        }
        while(list1!=NULL)
        {
            ptr->next = new ListNode(list1->val,NULL);
            list1=list1->next;
            ptr=ptr->next;
        }
        while(list2!=NULL)
        {
            ptr->next = new ListNode(list2->val,NULL);
            list2=list2->next;
            ptr=ptr->next;
        }

        return merged->next;
    }
};