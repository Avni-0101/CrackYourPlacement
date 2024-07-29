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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int len=-1;
        int decimal=0;

        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }

        temp = head;
        while(temp!=NULL)
        {
            decimal += pow(2,len)*temp->val;
            cout<<len<<" ";
            len--;
            temp=temp->next;
        }
        return decimal;
    }
};

// Method 2

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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int decimal=0;

        while(temp!=NULL)
        {
            decimal = decimal << 1;
            decimal = temp->val==1?decimal|1:decimal; 
            temp=temp->next;
        }
        return decimal;
    }
};