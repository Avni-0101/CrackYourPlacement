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
    void dfs(TreeNode* root, int sum, int targetSum, bool &isPath)
    {
        if(root==NULL)  return;

        sum+= root->val;

        if(root->left == NULL && root->right==NULL && sum==targetSum)
        {
            isPath = true;
            cout<<sum<<endl;
            return;
        }

        if(root->left && !isPath)  dfs(root->left,sum,targetSum,isPath);
        if(root->right && !isPath)  dfs(root->right,sum,targetSum,isPath);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool isPath = false;
        dfs(root,0,targetSum,isPath);

        return isPath;
    }
};