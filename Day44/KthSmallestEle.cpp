class Solution {
public:
    void inorder(TreeNode* root,int &count,int k,int &result)
    {
        if(root==NULL)return;

        inorder(root->left,count,k,result);
        count++;
        if(count==k)
        {
            result = root->val;
            return;
        }
        inorder(root->right,count,k,result);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0,result=-1;
        inorder(root,count,k,result);
        return result;
    }
};