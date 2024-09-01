//////////////////////////              BRUTE            ////////////////////////////////////////
class Solution {
public:
    bool getPath(TreeNode* root,TreeNode* node,vector<TreeNode*> &path)
    {
        if(!root) return false;

        path.push_back(root);
        if(root == node)   return true;
        if(getPath(root->left,node,path) || getPath(root->right,node,path))
        {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP,pathQ;

        getPath(root,p,pathP);
        getPath(root,q,pathQ);

        int i=0,j=0;
        TreeNode* lca = NULL;

        while(i<pathP.size() && j<pathQ.size())
        {
            if(pathP[i]==pathQ[j])  lca = pathP[i];
            else break;

            i++;j++;
        }

        return lca;
    }
};

//////////////////////////              OPTIMISED             ////////////////////////////////////////

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)    return NULL;

        if(root==p || root==q)   return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);         
        TreeNode* right = lowestCommonAncestor(root->right,p,q);         

        if(left==NULL && right==NULL)    return NULL;
        else if(left==NULL)  return right;
        else if(right==NULL)  return left;
       
        return root;
    }
};