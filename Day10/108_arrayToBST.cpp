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

    void construct(TreeNode* &tree,int start,int end,vector<int> &nums)
    {
        if(start>end)  return;

        int mid= (start+end)/2;
        tree = new TreeNode(nums[mid]);
        
        construct(tree->left,start,mid-1,nums);
        construct(tree->right,mid+1,end,nums);

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        TreeNode* tree;
        construct(tree,start,end,nums);   
        return tree;
    }
};