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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,int> visited;
        ListNode* curr = head;
        while(curr!=NULL && curr->next!=NULL)
        {
            visited[curr]++;

            if(visited[curr]>=2)
            {
                return true;
            }
            curr=curr->next;
        }
        return false;
    }
};

// Method 2

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;

        while(fast!=NULL && fast->next!=NULL)
        {
            if(slow==fast && flag)  return true;
            slow=slow->next;
            fast=fast->next->next;
            flag=1;
        }
        return false;
    }
};