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
    void path(TreeNode* root,vector<string> &ans, string p)
    {   
        if (root == NULL) return;

        if (!p.empty()) p += "->";
        p += to_string(root->val);

        if(root->left==NULL && root->right==NULL){  
            ans.push_back(p);
            return;
        }

        if(root->left)
            path(root->left,ans,p);
        if(root->right)
            path(root->right,ans,p);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string p="";
        path(root,ans,p);
        return ans;
    }
};