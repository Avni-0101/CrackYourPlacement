/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(l1!=NULL || l2!=NULL)
        {
            int add = carry;
            if (l1 != NULL) {
                add += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                add += l2->val;
                l2 = l2->next;
            }

            carry = add / 10;
            temp->next = new ListNode(add % 10);
            temp = temp->next;
        }
        if(carry!=0)
        {
            temp->next = new ListNode(1);
        }

        return ans->next;
    }
};