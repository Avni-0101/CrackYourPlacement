
class NodeValue{
    public:
    int maxNode,minNode,maxSize;
    
    NodeValue(int minNode,int maxNode,int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeValue helper(Node* root)
    {
        if(root==NULL)  
    	{
    	    return NodeValue(INT_MAX,INT_MIN,0);
    	}
    	
    	auto left = helper(root->left);
    	auto right = helper(root->right);
    	
    	if(left.maxNode<root->data && root->data<right.minNode)
    	{
    	    return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),1+left.maxSize+right.maxSize);
    	}
    	
    	return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    
    int largestBst(Node *root)
    {   
    	return helper(root).maxSize;
    }