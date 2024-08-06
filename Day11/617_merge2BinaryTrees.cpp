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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL) return NULL;
        else if(!root1) return root2;
        else if(!root2) return root1;

        int value=0;
        if(root1) value += root1->val;
        if(root2) value += root2->val;
        
        TreeNode* merged = new TreeNode(value);

        merged->left = mergeTrees(root1->left,root2->left);
        merged->right = mergeTrees(root1->right,root2->right);

        return merged;
    }
};