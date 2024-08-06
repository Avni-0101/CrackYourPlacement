/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,int &prev, int &minDiff)
    {
        if(root==NULL)  return;

        inorder(root->left,prev,minDiff);
        minDiff = min(minDiff,abs(prev-root->val));
        prev = root->val;
        inorder(root->right,prev,minDiff);
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff=INT_MAX, prev=INT_MAX;
        inorder(root,prev,minDiff);
        return minDiff;
    }
};