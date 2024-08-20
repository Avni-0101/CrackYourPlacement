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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(root==NULL)   return ans;

        queue<TreeNode*> q;
        bool flag=true;

        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            if(node!=NULL)
            {
                if(flag==true){    ans.push_back(node->val);}

                if(node->right!=NULL){  q.push(node->right);}
                if(node->left!=NULL){  q.push(node->left);}

                flag=false;
            }
            else if(!q.empty())
            {
                flag=true;
                q.push(NULL);
            }
        }
        return ans;
    }
};