//////////////////////////////////          BRUTE FORCE        //////////////////////////////

class BSTIterator {
public:
    vector<int> inorder;
    int ptr = -1;
    BSTIterator(TreeNode* root) { 
        TreeNode* curr = root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }
    
    int next() {
        if(hasNext())
        {
            ptr++;
            return inorder[ptr];
        }
        return -1;
    }
    
    bool hasNext() {
        return ptr < (int)inorder.size() - 1;
    }
};

//////////////////////////////////          METHOD 2        //////////////////////////////

class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushAll(TreeNode* node){
        while(node!=NULL)
        {
            st.push(node); node=node->left;
        }
        // for(; node!=NULL; st.push(node), node=node->left);
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
