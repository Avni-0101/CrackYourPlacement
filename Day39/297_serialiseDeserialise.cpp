class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        getline(ss,item,',');

        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr = q.front(); 
            q.pop();

            getline(ss,item,',');
            if(item=="null")
            {
                curr->left = NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(item));
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            getline(ss,item,',');
            if(item=="null")
            {
                curr->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(item));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));