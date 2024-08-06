class Solution{
public:

    void inorder(Node* root,int l,int h, int &count)
    {
        if(root==NULL)  return;
        
        inorder(root->left,l,h,count);
        if(root->data>=l && root->data<=h)
        {
            count++;
        }
        else if(root->data > h)  return;
        inorder(root->right,l,h,count);
    }
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      int count=0;
      inorder(root,l,h,count);
      return count;
    }
};