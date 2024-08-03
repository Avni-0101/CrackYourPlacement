#include<bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:

    bool areIdentical(TreeNode* a,TreeNode* b)
    {
        if(!a && !b)  return true;
        if(!a || !b)    return false;
        
        return (a->val == b->val && areIdentical(a->left,b->left) && areIdentical(a->right,b->right));
    }

    void mirror(TreeNode* root)
    {
        if(root==NULL)    return;

        if(root->left && root->right)
        {
            swap(root->left,root->right);
        }
        else if(root->left)
        {
            root->right = root->left;
            root->left = NULL;
        }
        else if(root->right)
        {
            root->left=root->right;
            root->right=NULL;
        }

        mirror(root->left);
        mirror(root->right);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        
        mirror(root->right);

        return areIdentical(root->left,root->right);
    }
};


//////////////////////////// SIMPLE METHOD ////////////////////////////

class Solution {
public:
    bool areIdentical(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;

        return (a->val == b->val && areIdentical(a->left, b->right) && areIdentical(a->right, b->left));
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return areIdentical(root->left, root->right);
    }
};