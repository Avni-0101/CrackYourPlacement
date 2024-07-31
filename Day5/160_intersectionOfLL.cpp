/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> count;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        while(ptr1!=NULL)
        {
            count[ptr1]++;
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL)
        {
            if(count[ptr2])  return ptr2;
            count[ptr2]++;
            ptr2=ptr2->next;
        }
        return NULL;
    }
};


// METHOD 2

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0,m=0;
        ListNode* ptr1 = headA;
		ListNode* ptr2 = headB;

        while(ptr1)
        {
            n++;
            ptr1=ptr1->next;
        }
        
        while(ptr2)
        {
            m++;
            ptr2=ptr2->next;
        }

        int diff = abs(n-m);
        if(n>m)
        {
            while(diff)
            {
                headA=headA->next;
                diff--;
            }
        }
        else
        {
            while(diff)
            {
                headB=headB->next;
                diff--;
            }
        }

        while(headA && headB)
        {
            if(headA==headB)    return headA;

            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};