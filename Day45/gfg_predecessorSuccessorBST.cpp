class Solution
{
    public:
    Node* success(Node* root,Node*& suc, int key)
    {
        if(root==NULL)return NULL;
        
        while(root)
        {
            if(key >= root->key)
                root=root->right;
            else{
                suc = root;
                root=root->left;
            }
        }
        return NULL;
    }
    
    Node* previous(Node* root,Node*& pre, int key)
    {
        if(root==NULL)return NULL;
        
        while(root)
        {
            if(key > root->key){
                pre = root;
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        return NULL;
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        success(root,suc,key);
        previous(root,pre,key);
    }