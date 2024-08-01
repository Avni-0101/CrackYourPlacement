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
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = NULL;
        ListNode* temp = head;

        while(temp!=NULL)
        {
            ans = new ListNode(temp->val,ans);
            temp=temp->next;
        }
        return ans;
    }
};

// METHOD 2

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* reverse = head;
        stack <int> st; 

        while(reverse!=NULL)
        {
            st.push(reverse->val);
            reverse = reverse->next;
        }

        reverse = head;
        while(reverse!=NULL)
        {
            int temp = st.top();
            st.pop();
            reverse->val = temp;
            reverse = reverse->next;
        }

        return head;
    }
};